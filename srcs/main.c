/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 12:10:44 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 18:42:28 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_file	*file;
	t_axis	*xyz;

	xyz = NULL;
	file = NULL;
	if (argc != 2)
		return (0);
	if (!(file = malloc(sizeof(t_file))))
		return (0);
	file->map = NULL;
	if (!(file_open(argv[1], &file->map, &file)))
		return (error("Map Error\n"));
	if (!(session(file)))
		return (0);
	ft_init(file);
	new_image(file);
	fdf_xyz(file->map, file);
	fdf_display(file);
	mlx_hook(WIN, 2, (1L << 0), get_key, (void *)file);
	mlx_loop(MLX);
	return (1);
}
