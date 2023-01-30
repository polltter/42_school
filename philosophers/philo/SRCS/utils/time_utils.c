//
// Created by mvenanci on 1/27/23.
//

#include "../../INCS/philo.h"

int	get_time_dif(int last_ate)
{
	return (get_time_mili() - last_ate);
}

int	get_time_mili(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
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

void	set_philo_time(t_philo *philo)
{
	pthread_mutex_lock(&table()->mutex);
	philo->last_ate = get_time_mili();
	pthread_mutex_unlock(&table()->mutex);
}
