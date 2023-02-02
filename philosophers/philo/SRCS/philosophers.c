/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:40:55 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/02/01 21:51:54 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philo.h"

void	print_philo(t_philo *philo, int status)
{
	printf("%d %d %s\n", get_time_dif(table()->start_time), philo->index, table()->msg[status]);
	if (table()->times[status])
		my_usleep(table()->times[status]);
}

void	unlock_fork(pthread_mutex_t *lock, int pos)
{
	pthread_mutex_lock(lock);
	table()->fork[pos] = 1;
	pthread_mutex_unlock(lock);
}

int	get_fork(t_philo *philo)
{
	philo->n_forks = 0;

	pthread_mutex_lock(&philo->left);
	if (table()->fork[philo->index] && ++philo->n_forks)
	{
		table()->fork[philo->index] = 0;
		pthread_mutex_unlock(&philo->left);
		pthread_mutex_lock(philo->rigth);
		if (philo->index == table()->n_philo && table()->fork[1] && ++philo->n_forks)
			table()->fork[1] = 0;
		else if (table()->fork[philo->index + 1] && ++philo->n_forks)
			table()->fork[philo->index + 1] = 0;
		else if (philo->n_forks--)
			unlock_fork(&philo->left, philo->index);
		pthread_mutex_unlock(philo->rigth);
	}
	else
		pthread_mutex_unlock(&philo->left);
	return (philo->n_forks);

}

void	increase_times_eaten(void)
{
	pthread_mutex_lock(&table()->total_times_to_eat);
	--(table()->times_to_eat);
	pthread_mutex_unlock(&table()->total_times_to_eat);
}

int	check_times_eaten(void)
{
	pthread_mutex_lock(&table()->total_times_to_eat);
	if (!table()->times_to_eat)
		return (0);
	pthread_mutex_unlock(&table()->total_times_to_eat);
	return (1);
}

void	*run_threads(void *elem)
{
	t_philo	*philo;

	philo = (t_philo *)elem;
	while (1)
	{
		if (get_fork(philo))
		{
			print_philo(philo, FORK);
			set_philo_time(philo);
			if (table()->times_to_eat && philo->times_eaten < table()->times_to_eat_each)
			{
				philo->times_eaten++;
				increase_times_eaten();
			}
			print_philo(philo, EAT);
			unlock_fork(&philo->left, philo->index);
			if (philo->index == table()->n_philo)
				unlock_fork(philo->rigth, 1);
			else
				unlock_fork(philo->rigth, philo->index + 1);
			print_philo(philo, SLEEP);
			print_philo(philo, THINK);
		}
	}
	return (philo);
}

int	main(int ac, char **av)
{
	 pthread_t	thread_dead;

	 *get_thread_dead() = thread_dead;
	if ((ac == 5 || ac == 6) && check_args(ac, av))
	{
		if (ac == 5)
			init_table(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]), -1);
		else
			init_table(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]), ft_atoi(av[5]));
		array(table()->philos)->for_each(give_forks, NULL);
		table()->start_time = get_time_mili();
		array(table()->philos)->for_each(init, NULL);
		pthread_create(&thread_dead, NULL, check_if_dead_each, array(table()->philos)->begin);
		pthread_join(thread_dead, NULL);
	}
	return (0);
}
