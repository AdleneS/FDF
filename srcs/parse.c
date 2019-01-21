/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 14:46:56 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 17:50:33 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		file_open(char *filename, t_map **map, t_file **file)
{
	int fd;

	if ((fd = open(filename, O_RDONLY)) < 1)
		return (0);
	file_read(fd, map, *file);
	close(fd);
	return (1);
}

int		file_read(int fd, t_map **map, t_file *file)
{
	char		*line;
	char		**splitline;
	int			c;

	c = 0;
	while ((get_next_line(fd, &line) == 1))
	{
		splitline = ft_strsplit(line, ' ');
		file_storelist(map, file, splitline);
		if (line)
			free(line);
		free(splitline);
		c++;
	}
	file->map_height = c;
	return (1);
}

int		linecount(char **splitline)
{
	int		i;

	i = 0;
	while (splitline[i])
		i++;
	return (i);
}

int		file_storelist(t_map **orig_list, t_file *file, char **splitline)
{
	t_map	*new;
	t_map	*tmp;
	int		i;

	if (!(new = (t_map *)malloc(sizeof(t_map))))
		return (0);
	i = 0;
	i = linecount(splitline);
	file->map_width = i;
	if (!(new->line = malloc(sizeof(int) * i)))
		return (0);
	i = -1;
	while (splitline[++i])
		new->line[i] = ft_atoi(splitline[i]);
	new->next = NULL;
	if (*orig_list == NULL)
		*orig_list = new;
	else
	{
		tmp = *orig_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}
