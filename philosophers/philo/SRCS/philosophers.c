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

int dead(void)
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

int full(void)
{
	pthread_mutex_lock(&table()->total_times_to_eat);
	if (table()->eat == table()->n_philo)
	{
		pthread_mutex_unlock(&table()->total_times_to_eat);
		return (0);
	}
	pthread_mutex_unlock(&table()->total_times_to_eat);
	return (1);
}

int	action(t_philo *philo, int status)
{

	if (!dead())
		return (0);
	if (!full())
		return (0);
	printf("%d %d %s\n", get_time_dif(table()->start_time), philo->index, table()->msg[status]);
	if (table()->times[status])
		my_usleep(table()->times[status]);
	if (status == EAT)
		release_fork(philo);
	return (1);
}

void	increase_times_to_eat(void)
{
	pthread_mutex_lock(&table()->total_times_to_eat);
	table()->eat++;
	pthread_mutex_unlock(&table()->total_times_to_eat);
}

void	*run_threads(void *elem)
{
	t_philo	*philo;

	philo = (t_philo *)elem;
	if (table()->n_philo == 1)
		return (philo);
	if (philo->index % 2)
		usleep(150);
	while (dead() && full())
	{
		printf("%d\n", philo->index);
		get_fork(philo);
		printf("%d\n", philo->index);
		if (!action(philo, FORK))
			break;
		set_philo_time(philo);
		if (!action(philo, EAT))
			break;
		philo->times_eaten++;
		if (philo->times_eaten == table()->times_to_eat)
			increase_times_to_eat();
		if (!action(philo, SLEEP))
			break;
		if (!action(philo, THINK))
			break;
		usleep(10);
	}
	return (philo);
}

int	main(int ac, char **av)
{
	if ((ac == 5 || ac == 6) && check_args(ac, av))
	{
		if (ac == 5)
			init_table(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]), -1);
		else
			init_table(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]), ft_atoi(av[5]));
		array(table()->philos)->for_each(give_forks, NULL);
		table()->start_time = get_time_mili();
		array(table()->philos)->for_each(init, NULL);
		while (check_if_dead(array(table()->philos)->begin))
			;
		array(table()->philos)->for_each(join_for_each, NULL);
		array(table()->philos)->destroy();
	}
	return (0);
}
