/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 12:10:44 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/24 11:54:22 by asaba       ###    #+. /#+    ###.fr     */
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
		return (error("Map Error"));
	if (!(session(file)))
		return (error("Init Error"));
	ft_init(file);
	if (!(new_image(file)) || !file->map)
		return (error("Image Error"));
	fdf_xyz(file->map, file);
	fdf_display(file);
	mlx_hook(WIN, 2, (1L << 0), get_key, (void *)file);
	mlx_hook(WIN, 17, 0, wasted, NULL);
	mlx_loop(MLX);
	return (1);
}
