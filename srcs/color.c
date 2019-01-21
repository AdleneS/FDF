/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/17 16:52:56 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 13:54:37 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	color_converter(int hexvalue, t_file *file)
{
	RED = ((hexvalue >> 16) & 0xFF);
	GREEN = ((hexvalue >> 8) & 0xFF);
	BLUE = ((hexvalue) & 0xFF);
}

double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double per)
{
	return ((int)((1 - per) * start + per * end));
}

int		get_color(t_bresenham *data, t_file *file, t_point *point)
{
	double	per;

	if (file->color.color == file->color.endcolor)
		return (1);
	if (data->dx > data->y)
		per = percent(point->xi, point->xf, data->x);
	else
		per = percent(point->yi, point->yf, data->y);
	if (-fabs(file->current_z) > -fabs(file->next_z))
	{
		RED = get_light((SCOLOR >> 16) & 0xFF, (ECOLOR >> 16) & 0xFF, per);
		GREEN = get_light((SCOLOR >> 8) & 0xFF, (ECOLOR >> 8) & 0xFF, per);
		BLUE = get_light(SCOLOR & 0xFF, ECOLOR & 0xFF, per);
	}
	else
	{
		RED = get_light((ECOLOR >> 16) & 0xFF, (SCOLOR >> 16) & 0xFF, per);
		GREEN = get_light((ECOLOR >> 8) & 0xFF, (SCOLOR >> 8) & 0xFF, per);
		BLUE = get_light(ECOLOR & 0xFF, SCOLOR & 0xFF, per);
	}
	return (1);
}
