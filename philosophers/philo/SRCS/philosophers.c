/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:40:55 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/02/05 16:36:30 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philo.h"

int	action(t_philo *philo, int status, char *s)
{
	if (!dead() || !full())
		return (0);
	printf("%d %d %s\n", get_time_dif(table()->start_time), \
	philo->index, s);
	if (table()->times[status])
		my_usleep(table()->times[status]);
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
	if (table()->n_philo <= 1)
		return (philo);
	while (dead() && full())
	{
		if (get_time_dif(philo->last_ate) <= 2 * table()->times[EAT])
			usleep(200);
		if (get_fork(philo) == 2)
		{
			if (!action(philo, FORK, FORKING))
				break ;
			philo->times_eaten++;
			set_philo_time(philo);
			if (!action(philo, EAT, EATING))
				break ;
			release_fork(philo);
			if (philo->times_eaten == table()->times_to_eat)
				increase_times_to_eat();
			if (!action(philo, SLEEP, SLEEPING) || !action(philo, THINK, T))
				break ;
		}
	}
	return (philo);
}

int	main(int ac, char **av)
{
	if ((ac == 5 || ac == 6) && check_args(ac, av))
	{
		if (!ft_atoi(av[1]) || (ac == 6 && !ft_atoi(av[5])))
			return (0);
		init_table(ft_atoi(av[1]), ft_atoi(av[2]), \
			ft_atoi(av[3]), ft_atoi(av[4]));
		if (ac == 5)
			table()->times_to_eat = -1;
		else
			table()->times_to_eat = ft_atoi(av[5]);
		(array(table()->philos))->for_each(give_forks, NULL);
		table()->start_time = get_time_mili();
		(array(table()->philos))->for_each(init, NULL);
		while (check_if_dead(array(table()->philos)->begin))
			;
		(array(table()->philos))->for_each(join_for_each, NULL);
		(array(table()->philos))->destroy();
	}
	return (0);
}
