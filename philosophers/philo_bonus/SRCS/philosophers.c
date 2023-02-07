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
	printf("%d %d %s\n", get_time_dif(table()->start_time), \
	philo->index, s);
	if (table()->times[status])
		my_usleep(table()->times[status]);
	return (1);
}

int start_processes(t_elems *elems)
{
	t_philo	*philo;

	while (elems)
	{
		philo = (t_philo *)elems->content;
		table()->pid[philo->index] = fork();
		if (table()->pid[philo->index] == -1)
			return (0);
		else if  (!table()->pid[philo->index])
		{
			while (get_time_dif(philo->last_ate) <= table()->times[DIE])
			{
				sem_wait(table()->forks);
				sem_wait(table()->forks);
				action(philo, FORK, FORKING);
				action(philo, EAT, EATING);
				sem_post(table()->forks);
				sem_post(table()->forks);
				action(philo, SLEEP, SLEEPING);
				action(philo, THINK, T);
			}
		}
		else
			elems = elems->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int status;

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
		table()->start_time = get_time_mili();
		start_processes(array(table()->philos)->begin);
		waitpid(-1, &status, 0);
		(array(table()->philos))->destroy();
	}
	return (0);
}
