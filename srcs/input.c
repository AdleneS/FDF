/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 11:09:46 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 12:15:47 by asaba       ###    #+. /#+    ###.fr     */
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
	if (key == 13)
	{
		file->color.startcolor *= 255;
		fdf_display(file);
	}
	if (key == 1)
	{
		file->color.endcolor *= 255;
		fdf_display(file);
	}
	if (key == 69 || key == 78)
	{
		file->data->of += (key == 69) ? 1 : -1;
		fdf_display(file);
	}
}

void	elevation(int key, t_file *file)
{
	if (key == 116 || key == 121)
	{
		file->data->el -= (key == 116) ? 0.1 : -0.1;
		fdf_display(file);
	}
}

void	move(int key, t_file *file)
{
	if (key == 124 || key == 123)
		file->s_x += (key == 124) ? 5 : -5;
	else if (key == 125 || key == 126)
		file->s_y += (key == 125) ? 5 : -5;
	else if (key == 0 || key == 2)
		file->data->rot += (key == 0) ? 0.05 : -0.05;
	else if (key == 12 || key == 14)
		file->data->rot = (key == 14) ? -0.8 : -1.57;
	else
		return ;
	fdf_display(file);
}

int		get_key(int key, void *file)
{
	t_file	*tmp;

	tmp = (t_file*)file;
	zoom(key, tmp);
	elevation(key, tmp);
	move(key, tmp);
	exit_prog(key, tmp);
	return (1);
}
