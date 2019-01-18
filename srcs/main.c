/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 12:10:44 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 12:12:10 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	t_file	*file;
	t_axis	*xyz;

	i = 0;
	j = 0;
	xyz = NULL;
	file = NULL;
	if (argc != 2)
		return (0);
	if (!(file = malloc(sizeof(t_file))))
		return (0);
	if (!(session(file)))
		return (0);
	file_open(argv[1], &file->map, &file);
	ft_init(file);
	new_image(file);
	fdf_xyz(file->map, file);
	fdf_display(file);
	mlx_hook(file->win, 2, (1L << 0), get_key, (void *)file);
	mlx_loop(file->mlx);
	return (1);
}
