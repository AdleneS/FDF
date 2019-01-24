/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   newimg.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 10:49:22 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/24 11:40:08 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		session(t_file *file)
{
	if (!(file->data = malloc(sizeof(t_data))))
		return (0);
	if ((file->map_height * file->map_width) < 500)
		file->data->of = 50;
	else if ((file->map_height * file->map_width) < 1500)
		file->data->of = 15;
	else
		file->data->of = 5;
	file->s_x = (1920 / 2) - (file->map_width / 2 * file->data->of) + 500;
	file->s_y = (1080 / 2) - (file->map_height / 2 * file->data->of) + 300;
	file->data->el = -0.07;
	file->data->rot = -0.8;
	file->data->rot2 = 0;
	file->data->rot3 = 1;
	file->color.startcolor = 0xFFFFFF;
	file->color.endcolor = 0xFF0055;
	return (1);
}

void	ft_init(t_file *file)
{
	if (!file->color.color)
	{
		RED = 0;
		GREEN = 0;
		BLUE = 0;
	}
}

int		new_image(t_file *file)
{
	if ((file->mlx = mlx_init()))
		if ((file->win = mlx_new_window(file->mlx, 1920, 1080, "file")))
			return (1);
	return (0);
}

void	ft_pixel_put(t_file *file, int x, int y)
{
	int i;

	i = (x * 4) + (y * file->sl);
	if ((x > 0 && x < 1920) && (y > 0 && y < 1080))
	{
		file->imgdata[i] = (char)file->color.blue;
		file->imgdata[i + 1] = (char)file->color.green;
		file->imgdata[i + 2] = (char)file->color.red;
	}
}
