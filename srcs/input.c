/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 11:09:46 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 19:19:58 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	exit_prog(int key, t_file *file)
{
	if (key == 53)
	{
		mlx_destroy_window(file->mlx, file->win);
		exit(EXIT_SUCCESS);
	}
}

void	zoom(int key, t_file *file)
{
	if (key == 18)
	{
		file->color.startcolor = rand();
		fdf_display(file);
	}
	if (key == 19)
	{
		file->color.endcolor = rand();
		fdf_display(file);
	}
	if (key == 69 || key == 78)
	{
		file->data->of += (key == 69) ? 1 : -1;
		fdf_display(file);
	}
}

void	elevation(t_file *file)
{
	if (ROT >= 5.4 || ROT < -7.0)
		ROT = -0.8;
	if (ROT2 >= 5.4 || ROT2 < -7.0)
		ROT2 = -0.8;
	if (ROT3 >= 5.4 || ROT3 < -7.0)
		ROT3 = -0.8;
}

void	move(int key, t_file *file)
{
	if (key == 116 || key == 121)
		file->data->el -= (key == 116) ? 0.01 : -0.01;
	else if (key == 124 || key == 123)
		file->s_x += (key == 124) ? 5 : -5;
	else if (key == 125 || key == 126)
		file->s_y += (key == 125) ? 5 : -5;
	else if (key == 0 || key == 2)
		file->data->rot += (key == 0) ? 0.05 : -0.05;
	else if (key == 12 || key == 14)
		file->data->rot2 += (key == 12) ? 0.05 : -0.05;
	else if (key == 13 || key == 1)
		file->data->rot3 += (key == 13) ? 0.05 : -0.05;
	else
		return ;
	fdf_display(file);
}

int		get_key(int key, void *file)
{
	t_file	*tmp;

	tmp = (t_file*)file;
	fdf_display(file);
	zoom(key, tmp);
	elevation(tmp);
	move(key, tmp);
	exit_prog(key, tmp);
	return (1);
}
