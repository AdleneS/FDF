/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 14:46:56 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/24 12:11:37 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static int		file_storelist(t_map **lst, t_file *file, char **splitline)
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
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

static int		file_read(int fd, t_map **map, t_file *file)
{
	char		*line;
	char		**splitline;
	int			count;
	int			c;

	c = 0;
	while ((get_next_line(fd, &line) == 1))
	{
		if (!(splitline = ft_strsplit(line, ' ')))
			error("Split Error");
		if (count == 0)
			count = linecount(splitline);
		if (!(checkline(splitline, count)))
			return (0);
		if (!(file_storelist(map, file, splitline)))
			return (0);
		if (line)
			free(line);
		freesplit(&splitline);
		c++;
	}
	file->map_height = c;
	return (1);
}

int				file_open(char *filename, t_map **map, t_file **file)
{
	int fd;

	if ((fd = open(filename, O_RDONLY)) < 1)
		return (0);
	if (read(fd, 0, 0) < 0)
		return (0);
	if (!(file_read(fd, map, *file)))
		return (0);
	close(fd);
	return (1);
}
