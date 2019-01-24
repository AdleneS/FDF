/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 5018/11/27 15:18:49 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/24 12:08:45 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

#define OF			file->data->of
#define EL			file->data->el
#define X			file->xyz[i][j].x
#define Y			file->xyz[i][j].y
#define Z			file->xyz[i][j].z
#define S_X			file->s_x
#define S_Y			file->s_y

void	fdf_xyz(t_map *map, t_file *file)
{
	int		i;
	int		j;

	i = 0;
	if (!(file->xyz = (t_axis **)malloc(sizeof(t_axis) * (HEIGHT))))
		error("Malloc Error");
	while (map)
	{
		j = -1;
		if (!(file->xyz[i] = (t_axis*)malloc(sizeof(t_axis) * (WIDTH))))
			error("Malloc Error");
		while (++j < file->map_width)
		{
			X = (i - HEIGHT / 2) * -cos(ROT) - (j - WIDTH / 2) * sin(ROT);
			Y = (i - HEIGHT / 2) * -sin(ROT) + (j - WIDTH / 2) * cos(ROT);
			Z = map->line[j] * EL;
			file->xyz[i][j].true_z = Z * EL;
			X = (X * cos(ROT2) + map->line[j] * EL * sin(ROT2));
			Z = X * -sin(ROT2) + map->line[j] * EL * cos(ROT2);
			Y = (Y * cos(ROT3) + map->line[j] * EL * sin(ROT3));
			Z = Y * -sin(ROT3) + map->line[j] * EL * cos(ROT3);
		}
		i++;
		map = map->next;
	}
}

void	fdf_display(t_file *file)
{
	int i;

	i = -1;
	if (!(file->img = mlx_new_image(MLX, 1920, 1080)))
		error("Image Error");
	if (!(file->imgdata = mlx_get_data_addr(file->img, &file->bpp, &file->sl,
		&file->end)))
		error("Image Error");
	while (++i < HEIGHT)
		free(file->xyz[i]);
	free(file->xyz);
	fdf_xyz(file->map, file);
	fdf_algo(file);
	fdf_algo2(file);
	border_input(file);
	border_info(file);
	mlx_put_image_to_window(MLX, WIN, file->img, 0, 0);
	hud_inputs(file);
	hud_infos(file);
	hud_rotation(file);
	mlx_destroy_image(MLX, file->img);
}

void	fdf_algo(t_file *file)
{
	t_point	p;
	int		i;
	int		j;

	i = 0;
	while (i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH - 1)
		{
			p.xi = X * OF + S_X;
			p.yi = Y * OF + S_Y + file->xyz[i][j].z;
			p.xf = file->xyz[i][j + 1].x * OF + S_X;
			p.yf = file->xyz[i][j + 1].y * OF + S_Y + file->xyz[i][j + 1].z;
			file->current_z = file->xyz[i][j].true_z;
			file->next_z = file->xyz[i][j + 1].true_z;
			bresenham(p, *file);
		}
		i++;
	}
}

void	fdf_algo2(t_file *file)
{
	int		i;
	int		j;
	t_point	p;

	i = 0;
	while (i + 1 < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
		{
			p.xi = X * OF + S_X;
			p.yi = Y * OF + S_Y + file->xyz[i][j].z;
			p.xf = file->xyz[i + 1][j].x * OF + S_X;
			p.yf = file->xyz[i + 1][j].y * OF + S_Y + file->xyz[i + 1][j].z;
			file->current_z = file->xyz[i][j].true_z;
			file->next_z = file->xyz[i + 1][j].true_z;
			bresenham(p, *file);
		}
		i++;
	}
}
