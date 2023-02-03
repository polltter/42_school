//
// Created by mvenanci on 2/2/23.
//

#include "../INCS/philo.h"

void	get_fork(t_philo *philo)
{
	if (philo->index % 2)
	{
		pthread_mutex_lock(&philo->left);
		pthread_mutex_lock(philo->rigth);
	}
	else
	{
		pthread_mutex_lock(philo->rigth);
		pthread_mutex_lock(&philo->left);
	}
}

void	release_fork(t_philo *philo)
{
	if (philo->index % 2)
	{
		pthread_mutex_unlock(&philo->left);
		pthread_mutex_unlock(philo->rigth);
	}
	else
	{
		pthread_mutex_unlock(philo->rigth);
		pthread_mutex_unlock(&philo->left);
	}
}