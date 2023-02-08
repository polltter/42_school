/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:01:43 by mvenanci          #+#    #+#             */
/*   Updated: 2023/02/05 16:19:00 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philo.h"

int	get_fork(t_philo *philo)
{
	philo->n_forks = 0;
	pthread_mutex_lock(&philo->left);
	if (table()->availabe_fork[philo->index] && ++philo->n_forks)
	{
		table()->availabe_fork[philo->index] = 0;
		pthread_mutex_unlock(&philo->left);
		pthread_mutex_lock(philo->rigth);
		if (philo->index == table()->n_philo && \
		table()->availabe_fork[1] && ++philo->n_forks)
			table()->availabe_fork[1] = 0;
		else if (table()->availabe_fork[philo->index + 1] && ++philo->n_forks)
			table()->availabe_fork[philo->index + 1] = 0;
		else
		{
			philo->n_forks--;
			pthread_mutex_lock(&philo->left);
			table()->availabe_fork[philo->index] = 1;
			pthread_mutex_unlock(&philo->left);
		}
		pthread_mutex_unlock(philo->rigth);
	}
	else
		pthread_mutex_unlock(&philo->left);
	return (philo->n_forks);
}

void	release_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->left);
	table()->availabe_fork[philo->index] = 1;
	pthread_mutex_unlock(&philo->left);
	pthread_mutex_lock(philo->rigth);
	if (philo->index == table()->n_philo)
		table()->availabe_fork[1] = 1;
	else
		table()->availabe_fork[philo->index + 1] = 1;
	pthread_mutex_unlock(philo->rigth);
}

int	dead(void)
{
	pthread_mutex_lock(&table()->dead);
	if (table()->any_dead)
	{
		pthread_mutex_unlock(&table()->dead);
		return (0);
	}
	pthread_mutex_unlock(&table()->dead);
	return (1);
}
