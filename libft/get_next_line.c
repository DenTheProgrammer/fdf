/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 10:28:38 by ashari            #+#    #+#             */
/*   Updated: 2019/04/26 19:10:22 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_cpytoln(int fd, char **line, char **s_line)
{
	char			*save;
	int				i;

	i = 0;
	while (s_line[fd][i] != '\n' && s_line[fd][i] != '\0')
		i++;
	if (s_line[fd][i] == '\n')
	{
		*line = ft_strndup(s_line[fd], i);
		save = ft_strdup(s_line[fd] + i + 1);
		free(s_line[fd]);
		s_line[fd] = save;
	}
	else if (s_line[fd][i] == '\0')
	{
		*line = ft_strdup(s_line[fd]);
		ft_strdel(&s_line[fd]);
	}
	return (1);
}

int					get_next_line(int fd, char **line)
{
	static	char	*s_line[10241];
	char			buff[BUFF_SIZE + 1];
	char			*save;
	int				size;

	if (fd < 0 || line == NULL || (size = read(fd, buff, 0) < 0))
		return (-1);
	(!s_line[fd]) ? s_line[fd] = ft_strnew(1) : NULL;
	if (ft_strchr(s_line[fd], '\n'))
		return (ft_cpytoln(fd, line, s_line));
	while ((size = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[size] = '\0';
		save = ft_strjoin(s_line[fd], buff);
		free(s_line[fd]);
		s_line[fd] = save;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (size == 0 && (s_line[fd] == NULL || s_line[fd][0] == '\0'))
		return (0);
	return (ft_cpytoln(fd, line, s_line));
}
