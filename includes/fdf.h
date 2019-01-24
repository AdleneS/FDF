/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 10:28:18 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/24 12:09:57 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>

# define MLX		file->mlx
# define WIN		file->win
# define RED		file->color.red
# define GREEN		file->color.green
# define BLUE		file->color.blue
# define SCOLOR		file->color.startcolor
# define ECOLOR		file->color.endcolor
# define CURZ		file.current_z
# define NEXZ		file.next_z
# define ROT		file->data->rot
# define ROT2		file->data->rot2
# define ROT3		file->data->rot3
# define HEIGHT		file->map_height
# define WIDTH		file->map_width

typedef struct		s_color
{
	int				startcolor;
	int				endcolor;
	int				color;
	int				red;
	int				green;
	int				blue;
}					t_color;

typedef struct		s_bresenham
{
	double			x;
	double			y;
	double			dx;
	double			dy;
	double			yinc;
	double			xinc;
	double			cumul;
	double			i;
}					t_bresenham;

typedef struct		s_axis
{
	double			x;
	double			y;
	double			z;
	double			true_z;
}					t_axis;

typedef struct		s_point
{
	double			xi;
	double			yi;
	double			xf;
	double			yf;
}					t_point;

typedef struct		s_data
{
	int				x;
	int				s_x;
	int				s_y;
	double			el;
	double			of;
	double			rot;
	double			rot2;
	double			rot3;
	int				i;
	int				j;
}					t_data;

typedef struct		s_map
{
	int				*line;
	struct s_map	*next;
}					t_map;


typedef struct		s_file
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*imgdata;
	int				map_height;
	int				map_width;
	int				win_height;
	int				win_width;
	int				s_x;
	int				s_y;
	double			current_z;
	double			next_z;
	t_data			*data;
	t_map			*map;
	t_axis			**xyz;

	int				bpp;
	int				end;
	int				sl;

	t_color			color;
}					t_file;

/*
** READ
*/

int					file_open(char *file, t_map **map, t_file **app);
int					new_image(t_file *file);

/*
** CHECK
*/

int					checkline(char **splitline, int count);
int					linecount(char **splitline);
int					error(char *issue);
int					wasted(void);
void				freesplit(char ***splitline);

/*
** SETUP
*/

int					session(t_file *file);
void				fdf_xyz(t_map *map, t_file *file);
void				ft_init(t_file *fdf);

/*
** COLORS
*/

int					get_color(t_bresenham *data, t_file *file, t_point *point);
void				color_converter(int hexvalue, t_file *file);

/*
** TRACING
*/

int					get_key(int key, void *param);
void				fdf_display(t_file *param);
void				bresenham(t_point point, t_file file);
void				ft_pixel_put(t_file *file, int x, int y);
void				fdf_algo(t_file *file);
void				fdf_algo2(t_file *file);

/*
** HUD
*/
void				hud_inputs(t_file *file);
void				hud_infos(t_file *file);
void				hud_rotation(t_file *file);
void				border_input(t_file *file);
void				border_info(t_file *file);

#endif
