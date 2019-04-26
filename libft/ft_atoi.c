/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:09:36 by ashari            #+#    #+#             */
/*   Updated: 2019/04/13 12:43:44 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int							ft_atoi(const char *str)
{
	int						i;
	int						znak;
	unsigned long long int	result;

	i = 0;
	result = 0;
	znak = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			znak *= -1;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - '0');
		if (result >= 9223372036854775807 && znak == 1)
			return (-1);
		else if (result > 9223372036854775807 && znak == -1)
			return (0);
		i++;
	}
	return (result * znak);
}
