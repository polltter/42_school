/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:22:21 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/21 16:25:08 by mvenanci@st      ###   ########.fr       */
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

void	my_usleep(int mili_sec)
{
	long start;
	long end;
	struct timeval tv;

	gettimeofday(&tv, NULL);
	start = ( tv.tv_sec * 1000 + tv.tv_usec / 1000);
	end  = start;
	start += mili_sec;
	while (end < start)
	{
		gettimeofday(&tv, NULL);
		end = ( tv.tv_sec * 1000 + tv.tv_usec / 1000);
	}
}