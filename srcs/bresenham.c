/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bresenham.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 10:28:25 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 15:12:43 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	bres_draw_x(t_bresenham data, t_file file, t_point point)
{
	data.i = 1;
	data.cumul = data.dx / 2;
	while (data.i <= data.dx)
	{
		data.x += data.xinc;
		data.cumul += data.dy;
		if (data.cumul >= data.dx)
		{
			data.cumul -= data.dx;
			data.y += data.yinc;
		}
		if ((CURZ <= NEXZ || CURZ >= NEXZ) && fabs(CURZ) > 0 && fabs(NEXZ) > 0)
			color_converter(file.color.endcolor, &file);
		else if (fabs(CURZ + NEXZ) > 0.01)
			get_color(&data, &file, &point);
		else
			color_converter(0xFFFFFF, &file);
		ft_pixel_put(&file, data.x, data.y);
		data.i++;
	}
}

void	bres_draw_y(t_bresenham data, t_file file, t_point point)
{
	data.i = 1;
	data.cumul = data.dy / 2;
	while (data.i <= data.dy)
	{
		data.y += data.yinc;
		data.cumul += data.dx;
		if (data.cumul >= data.dy)
		{
			data.cumul -= data.dy;
			data.x += data.xinc;
		}
		if ((CURZ <= NEXZ || CURZ >= NEXZ) && fabs(CURZ) > 0 && fabs(NEXZ) > 0)
			color_converter(file.color.endcolor, &file);
		else if (fabs(CURZ + NEXZ) > 0.01)
			get_color(&data, &file, &point);
		else
			color_converter(0xFFFFFF, &file);
		ft_pixel_put(&file, data.x, data.y);
		data.i++;
	}
}

void	bresenham(t_point point, t_file file)
{
	t_bresenham		data;

	data.x = point.xi;
	data.y = point.yi;
	data.dx = (point.xf - point.xi);
	data.dy = (point.yf - point.yi);
	data.yinc = (data.dy > 0) ? 1 : -1;
	data.xinc = (data.dx > 0) ? 1 : -1;
	data.dx = fabs(data.dx);
	data.dy = fabs(data.dy);
	if (data.dx > data.dy)
		bres_draw_x(data, file, point);
	else
		bres_draw_y(data, file, point);
}
