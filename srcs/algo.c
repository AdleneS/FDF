/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 5018/11/27 15:18:49 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 16:50:17 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

#define ROT			file->data->rot
#define OF			file->data->of

void	fdf_xyz(t_map *map, t_file *file)
{
	int i;
	int j;

	i = 0;
	file->xyz = (t_axis **)malloc(sizeof(t_axis) * ((file->map_height)));
	while (map)
	{
		j = -1;
		file->xyz[i] = (t_axis*)malloc(sizeof(t_axis) * file->map_width);
		while (++j < file->map_width)
		{
			file->xyz[i][j].x = i * -cos(ROT) - j * sin(ROT);
			file->xyz[i][j].y = i * -sin(ROT) + j * cos(ROT);
			file->xyz[i][j].z = map->line[j] * file->data->el;
		}
		i++;
		map = map->next;
	}
}

void	fdf_display(t_file *file)
{
	file->img = mlx_new_image(file->mlx, 1920, 1080);
	file->imgdata = mlx_get_data_addr(file->img, &file->bpp, &file->sizeline,
		&file->end);
	free(file->xyz);
	fdf_xyz(file->map, file);
	fdf_algoo(file);
	fdf_algoo2(file);
	mlx_put_image_to_window(file->mlx, file->win, file->img, 0, 0);
	mlx_destroy_image(file->mlx, file->img);
}

void	fdf_algoo(t_file *file)
{
	t_point	p;
	t_axis	**tmp_xyz;
	int		i;
	int		j;

	tmp_xyz = file->xyz;
	i = 0;
	while (i < file->map_height)
	{
		j = -1;
		while (++j < file->map_width - 1)
		{
			p.xi = tmp_xyz[i][j].x * OF + file->s_x;
			p.yi = tmp_xyz[i][j].y * OF + file->s_y + tmp_xyz[i][j].z;
			p.xf = tmp_xyz[i][j + 1].x * OF + file->s_x;
			p.yf = tmp_xyz[i][j + 1].y * OF + file->s_y + tmp_xyz[i][j + 1].z;
			file->current_z = tmp_xyz[i][j].z;
			file->next_z = tmp_xyz[i][j + 1].z;
			bresenham(p, *file);
		}
		i++;
	}
}

void	fdf_algoo2(t_file *file)
{
	t_point	p;
	t_axis	**tmp_xyz;
	int		i;
	int		j;

	tmp_xyz = file->xyz;
	i = 0;
	while (i + 1 < file->map_height)
	{
		j = -1;
		while (++j < file->map_width)
		{
			p.xi = tmp_xyz[i][j].x * OF + file->s_x;
			p.yi = tmp_xyz[i][j].y * OF + file->s_y + tmp_xyz[i][j].z;
			p.xf = tmp_xyz[i + 1][j].x * OF + file->s_x;
			p.yf = tmp_xyz[i + 1][j].y * OF + file->s_y + tmp_xyz[i + 1][j].z;
			file->current_z = tmp_xyz[i][j].z;
			file->next_z = tmp_xyz[i + 1][j].z;
			bresenham(p, *file);
		}
		i++;
	}
}
