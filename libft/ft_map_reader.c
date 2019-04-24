/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:55:53 by ashari            #+#    #+#             */
/*   Updated: 2019/04/22 13:31:16 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static	char		*del_all(t_lst **tetramino, char **tmp)
{
	if (tetramino)
		ft_list_del(tetramino);
	if (tmp)
		ft_strdel(tmp);
	return (NULL);
}

static	char		*is_valid(char *buff, t_lst **tetramino, int res)
{
	int				loc;
	t_lst			*tetramino_tmp;
	char			*tmp;

	if ((loc = ft_is_map_valid(buff, res)) >= 0)
	{
		tmp = ft_strndup(buff, 20);
		if (ft_is_tetramino_valid(tmp, loc))
		{
			if (!(tetramino_tmp =
				ft_list_pushback(tetramino, tmp)))
				return (NULL);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
	return (tmp);
}

t_lst				*ft_map_reader(int fd, t_lst **tetramino)
{
	int				res;
	int				i;
	char			*tmp;
	char			buff[22];

	tmp = NULL;
	i = 0;
	while ((res = read(fd, buff, 21)) > 20)
	{
		buff[res] = '\0';
		if (!(is_valid(buff, tetramino, res)))
			return ((t_lst *)del_all(tetramino, &tmp));
		i++;
	}
	if (res == 20 && i <= 25)
	{
		buff[20] = '\0';
		if (!(is_valid(buff, tetramino, res)))
			return ((t_lst *)del_all(tetramino, &tmp));
	}
	else
		return ((t_lst *)del_all(tetramino, &tmp));
	if (res == -1)
		return (NULL);
	return (*tetramino);
}
