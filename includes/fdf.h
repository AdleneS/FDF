/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 10:28:18 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 12:16:36 by asaba       ###    #+. /#+    ###.fr     */
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

# define RED		file->color.red
# define GREEN		file->color.green
# define BLUE		file->color.blue
# define SCOLOR		file->color.startcolor
# define ECOLOR		file->color.endcolor
# define CURZ		file.current_z
# define NEXZ		file.next_z

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
	int				s_x;
	int				s_y;
	int				current_z;
	int				next_z;
	t_data			*data;
	t_map			*map;
	t_axis			**xyz;

	int				bpp;
	int				end;
	int				sizeline;

	t_color			color;
}					t_file;


void				bresenham(t_point point, t_file file);
int					file_open(char *file, t_map **map, t_file **app);
void				fdf_display(t_file *param);
int					file_read(int fd, t_map	**map, t_file *app);
int					file_storelist(t_map **orig_list, t_file *app, char **splitline);
int					get_z(t_map *map, int x, int y);
int					get_key(int key, void *param);
int					new_image(t_file *file);
void				ft_init(t_file *fdf);
void				ft_pixel_put(t_file *fdf, int x, int y);
void				fdf_algoo(t_file *file);
void				fdf_algoo2(t_file *file);
int					get_color(t_bresenham *data, t_file *file, t_point *point);
void				color_converter(int hexvalue, t_file *file);
void				fdf_xyz(t_map *map, t_file *file);
int					session(t_file *file);

#endif
