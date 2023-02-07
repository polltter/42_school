/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:49:56 by mvenanci          #+#    #+#             */
/*   Updated: 2023/02/01 21:55:31 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/philo.h"

int	get_time_dif(int last_ate)
{
	return (get_time_mili() - last_ate);
}

int	get_time_mili(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	my_usleep(int mili_sec)
{
	long			end;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	end = tv.tv_sec * 1000 + tv.tv_usec / 1000 + mili_sec;
	while (tv.tv_sec * 1000 + tv.tv_usec / 1000 < end)
	{
		gettimeofday(&tv, NULL);
		usleep(50);
	}
}

void	set_philo_time(t_philo *philo)
{
	philo->last_ate = get_time_mili();
}
