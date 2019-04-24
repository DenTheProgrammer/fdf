/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:30:37 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/24 18:20:03 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char		ft_helper(int w)
{
	char res;

	res = 1;
	while (--w)
		res = (res << 1) | 1;
	return (res);
}

static int		ft_insertion(t_lst *tetr, long long *map, int row, int shift)
{
	char		tmp;
	long long	m[33];
	int			t_row;
	int			h;
	char		t;

	t = ft_helper(tetr->w);
	tmp = tetr->map;
	h = tetr->h;
	t_row = row + h - 1;
	while (h)
	{
		m[t_row] = map[t_row] ^ ((tmp & t) << (shift - (tetr->w - 1)));
		if (m[t_row] - map[t_row] != ((tmp & t) << (shift - (tetr->w - 1))))
			return (0);
		tmp = tmp >> tetr->w;
		t_row--;
		h--;
	}
	map = ft_arrncpy(map, m, row, tetr->h);
	return (1);
}

static void		ft_free_from(t_lst *tetr, long long *map, int row, int shift)
{
	char		tmp;
	int			h;
	char		t;

	h = tetr->h;
	t = ft_helper(tetr->w);
	tmp = tetr->map;
	h = tetr->h;
	row += h - 1;
	while (h)
	{
		map[row] &= ~((tmp & t) << (shift - (tetr->w - 1)));
		tmp = tmp >> tetr->w;
		h--;
		row--;
	}
}

int				ft_try_to_solve(t_lst *tetr, long long *map, int size)
{
	int row;
	int	shift;

	shift = 0;
	row = 0;
	while (tetr)
	{
		if (((map[row] >> (size - 1 - shift)) & 1) == 0 || tetr->nul != 0)
		{
			if (tetr->h > size - row)
				return (0);
			else if (ft_insertion(tetr, map, row, size - 1 - shift))
			{
				tetr->x = shift;
				tetr->y = row;
				if (ft_try_to_solve(tetr->next, map, size))
					return (1);
				else
					ft_free_from(tetr, map, row, size - 1 - shift);
			}
		}
		if ((++shift == size || tetr->w > size - shift) && ++row)
			shift = 0;
	}
	return (1);
}
