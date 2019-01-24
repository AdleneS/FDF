/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hud.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 17:51:25 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/24 11:12:56 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		hud_inputs(t_file *file)
{
	mlx_string_put(MLX, WIN, 5, 5, 0xFFFF00, "Inputs:");
	mlx_string_put(MLX, WIN, 5, 30, 0xFFFFFF, "Move: Arrows");
	mlx_string_put(MLX, WIN, 5, 55, 0xFFFFFF, "Zoom: + or -");
	mlx_string_put(MLX, WIN, 5, 80, 0xFFFFFF, "Elevation : v or ^");
	mlx_string_put(MLX, WIN, 5, 105, 0xFFFFFF, "Rotations X: A or D");
	mlx_string_put(MLX, WIN, 5, 130, 0xFFFFFF, "Rotations Y: S or W");
	mlx_string_put(MLX, WIN, 5, 155, 0xFFFFFF, "Rotations Z: Q or E");
	mlx_string_put(MLX, WIN, 5, 180, 0xFFFFFF, "Colors : 1 or 2");
	mlx_string_put(MLX, WIN, 5, 1050, file->color.endcolor, "MADE BY ASABA");
}

void		hud_infos(t_file *file)
{
	char	*itoa;

	mlx_string_put(MLX, WIN, 5, 230, 0xFFFF00, "Infos:");
	mlx_string_put(MLX, WIN, 5, 255, 0xFFFFFF, "X: ");
	itoa = ft_itoa(file->s_x);
	mlx_string_put(MLX, WIN, 30, 255, 0xFFFFFF, itoa);
	free(itoa);
	mlx_string_put(MLX, WIN, 100, 255, 0xFFFFFF, "Y: ");
	itoa = ft_itoa(file->s_y);
	mlx_string_put(MLX, WIN, 130, 255, 0xFFFFFF, itoa);
	free(itoa);
	mlx_string_put(MLX, WIN, 5, 280, 0xFFFFFF, "ZOOM: ");
	itoa = ft_itoa(file->data->of);
	mlx_string_put(MLX, WIN, 60, 280, 0xFFFFFF, itoa);
	free(itoa);
	itoa = ft_itoa(file->data->el * 10 * -1);
	mlx_string_put(MLX, WIN, 5, 305, 0xFFFFFF, "Elevation: ");
	mlx_string_put(MLX, WIN, 125, 305, 0xFFFFFF, itoa);
	free(itoa);
}

void		hud_rotation(t_file *file)
{
	char	*itoa;

	mlx_string_put(MLX, WIN, 5, 330, 0xFFFFFF, "Rotation X: ");
	itoa = ft_itoa(ROT);
	mlx_string_put(MLX, WIN, 125, 330, 0xFFFFFF, itoa);
	free(itoa);
	mlx_string_put(MLX, WIN, 5, 355, 0xFFFFFF, "Rotation Y: ");
	itoa = ft_itoa(ROT2);
	mlx_string_put(MLX, WIN, 125, 355, 0xFFFFFF, itoa);
	free(itoa);
	mlx_string_put(MLX, WIN, 5, 380, 0xFFFFFF, "Rotation Z: ");
	itoa = ft_itoa(ROT3);
	mlx_string_put(MLX, WIN, 125, 380, 0xFFFFFF, itoa);
	free(itoa);
}

void		border_input(t_file *file)
{
	t_point	p;

	p.xi = 0;
	p.yi = 205;
	p.xf = 250;
	p.yf = 205;
	bresenham(p, *file);
	p.xi = 250;
	p.yi = 0;
	p.xf = 250;
	p.yf = 205;
	bresenham(p, *file);
}

void		border_info(t_file *file)
{
	t_point	p;

	p.xi = 0;
	p.yi = 220;
	p.xf = 250;
	p.yf = 220;
	bresenham(p, *file);
	p.xi = 0;
	p.yi = 415;
	p.xf = 250;
	p.yf = 415;
	bresenham(p, *file);
	p.xi = 250;
	p.yi = 220;
	p.xf = 250;
	p.yf = 415;
	bresenham(p, *file);
}
