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

int dead(void)
{
	int status;

	pthread_mutex_lock(&table()->mutex);
	status = table()->dead;
	pthread_mutex_unlock(&table()->mutex);
	return (status);
}

void	print_philo(t_philo *philo, int status)
{
	if (!dead())
		printf("%d %d %s\n", get_time_dif(table()->start_time), philo->index, table()->msg[status]);
}

void	get_fork(t_philo *philo)
{
	philo->n_forks = 0;
	while (philo->n_forks != 2 && !dead())
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
			else
			{
				philo->n_forks--;
				pthread_mutex_lock(&philo->left);
				table()->fork[philo->index] = 1;
				pthread_mutex_unlock(&philo->left);
			}
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
	while (!dead())
	{
		get_fork(philo);
		set_philo_time(philo);
		print_philo(philo, EAT);
		my_usleep(table()->times[EAT]);
		pthread_mutex_lock(&philo->left);
		table()->fork[philo->index] = 1;
		pthread_mutex_unlock(&philo->left);
		pthread_mutex_lock(philo->rigth);
		if (philo->index == table()->n_philo)
			table()->fork[1] = 1;
		else
			table()->fork[philo->index + 1] = 1;
		pthread_mutex_unlock(philo->rigth);
		print_philo(philo, SLEEP);
		my_usleep(table()->times[SLEEP]);
		print_philo(philo, THINK);
	}
	return (philo);
}

int	main(int ac, char **av)
{
	pthread_t	dead;

	if ((ac == 5 || ac == 6) && check_args(ac, av))
	{
		if (ac == 5)
			init_table(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]), 0);
		else
			init_table(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]), ft_atoi(av[5]));
		array(table()->philos)->for_each(give_forks, NULL);
		table()->start_time = get_time_mili();
		array(table()->philos)->for_each(init, NULL);
		pthread_create(&dead, NULL, check_if_dead_each, array(table()->philos)->begin);
		array(table()->philos)->for_each(join_for_each, NULL);
		pthread_join(dead, NULL);
	}
	return (0);
}
