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

int	action(t_philo *philo, int status)
{
	pthread_mutex_lock(&table()->dead);
	if (table()->any_dead)
	{
		pthread_mutex_unlock(&table()->dead);
		return (0);
	}
	pthread_mutex_unlock(&table()->dead);
	printf("%d %d %s\n", get_time_dif(table()->start_time), philo->index, table()->msg[status]);
	if (table()->times[status])
		my_usleep(table()->times[status]);
	return (1);
}

void	*run_threads(void *elem)
{
	t_philo	*philo;

	philo = (t_philo *)elem;
	if (table()->n_philo == 1)
		return (philo);
	if (philo->index % 2)
		usleep(150);
	while (1)
	{
		get_fork(philo);
		if (!action(philo, FORK))
			return (philo);
		set_philo_time(philo);
//		if (table()->eat && philo->times_eaten < table()->times_to_eat_each)
//		{
//			philo->times_eaten++;
//			increase_times_eaten();
//		}
		if (!action(philo, EAT))
			return (philo);
		release_fork(philo);
		if (!action(philo, SLEEP))
			return (philo);
		if (!action(philo, THINK))
			return (philo);
		usleep(10);
	}
}

int	main(int ac, char **av)
{
	if ((ac == 5 || ac == 6) && check_args(ac, av))
	{
		if (ac == 5) {
			init_table(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]), -1);
		}
		else {
			init_table(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]), ft_atoi(av[5]));
		}
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
