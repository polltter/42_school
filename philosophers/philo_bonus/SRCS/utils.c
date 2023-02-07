/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:22:21 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/02/05 16:01:22 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philo.h"

int	ft_atoi(char *s)
{
	int			i;
	int			sign;
	long int	n;

	n = 0;
	i = 0;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		n = n * 10 + s[i] - '0';
		i++;
	}
	return (n * sign);
}

t_table	*table(void)
{
	static t_table	table;

	return (&table);
}

