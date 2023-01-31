/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:40:55 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/26 14:54:43 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philo.h"

void	print_philo(t_philo *philo, int status)
{
	printf("%d %d %s\n", get_time_dif(table()->start_time), philo->index, table()->msg[status]);
	my_usleep(table()->times[status]);
}

void	unlock_fork(pthread_mutex_t *lock, int pos)
{
	pthread_mutex_lock(lock);
	table()->fork[pos] = 1;
	pthread_mutex_unlock(lock);
}

void	get_fork(t_philo *philo)
{
	philo->n_forks = 0;
	while (philo->n_forks != 2)
	{
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
	}
	print_philo(philo, FORK);
}

void	*run_threads(void *elem)
{
	t_philo	*philo;

	philo = (t_philo *)elem;
	while (1)
	{
		get_fork(philo);
		set_philo_time(philo);
		print_philo(philo, EAT);
		unlock_fork(&philo->left, philo->index);
		if (philo->index == table()->n_philo)
			unlock_fork(philo->rigth, 1);
		else
			unlock_fork(philo->rigth, philo->index + 1);
		print_philo(philo, SLEEP);
		print_philo(philo, THINK);
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
			init_table(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]), 0);
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
