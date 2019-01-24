/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   useful.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/24 11:09:33 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/24 12:10:18 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		wasted(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

int		linecount(char **splitline)
{
	int		i;

	i = 0;
	while (splitline[i])
		i++;
	return (i);
}

int		checkline(char **splitline, int count)
{
	if (linecount(splitline) != count)
		return (0);
	return (1);
}

void	freesplit(char ***splitline)
{
	char	**str;
	int		i;

	i = 0;
	str = *splitline;
	while (*str)
	{
		ft_strdel(str);
		i++;
		str = &(*splitline)[i];
	}
	ft_memdel((void**)splitline);
}
