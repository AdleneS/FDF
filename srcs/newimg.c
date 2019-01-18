/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   newimg.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 10:49:22 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 12:10:07 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		session(t_file *file)
{
	if (!(file->data = malloc(sizeof(t_data))))
		return (0);
	file->map = NULL;
	file->s_x = 700;
	file->s_y = 250;
	file->data->of = 15;
	file->data->el = -2;
	file->data->rot = -0.8;
	file->data->rot2 = 0;
	file->color.startcolor = 0x0000FF;
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
	file->mlx = mlx_init();
	file->win = mlx_new_window(file->mlx, 1920, 1080, "fdf");
	return (0);
}

void	ft_pixel_put(t_file *fdf, int x, int y)
{
	int i;

	i = (x * 4) + (y * fdf->sizeline);
	if ((x > 0 && x < 1920) && (y > 0 && y < 1080))
	{
		fdf->imgdata[i] = (char)fdf->color.blue;
		fdf->imgdata[i + 1] = (char)fdf->color.green;
		fdf->imgdata[i + 2] = (char)fdf->color.red;
	}
}
