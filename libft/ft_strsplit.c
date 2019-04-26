/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 20:26:17 by ashari            #+#    #+#             */
/*   Updated: 2019/04/13 12:26:24 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_l(char const *s, int i, char c)
{
	int count;

	count = 0;
	while (s[i + 1] != c && s[i] != '\0')
	{
		count++;
		i++;
	}
	return (count + 1);
}

static int	c_w(char const *s, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count + 1);
}

static int	skipp(int i, char const *s, char c)
{
	while (s[i] == c)
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i1;
	int		i;
	int		j;
	char	**new;

	i1 = -1;
	i = 0;
	if (s == NULL || !(new = (char **)malloc
(sizeof(char *) * (c_w(s, c) + 1))))
		return (NULL);
	while (++i1 < (c_w(s, c) - 1))
	{
		i = skipp(i, s, c);
		while (s[i] != c && s[i] != '\0')
		{
			j = -1;
			if (!(new[i1] = (char *)malloc(sizeof(char) * c_l(s, i, c))))
				return (NULL);
			while (s[i] != c && s[i])
				new[i1][++j] = s[i++];
			new[i1][++j] = '\0';
		}
	}
	new[i1] = NULL;
	return (new);
}
