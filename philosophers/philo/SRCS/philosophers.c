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

void	check_if_dead(t_elems *elems, void *o)
{
	(void)o;
	if (get_time_dif(((t_philo *)(elems->content))->last_ate) > table()->times[DIE])
	{
		table()->dead = 1;
		printf("%d %d %s\n", get_time_dif(table()->start_time), ((t_philo *)(elems->content))->index, table()->msg[DIE]);
	}

}

void	*check_if_dead_each(void *o)
{
	(void)o;
	while (!table()->dead)
		array(table()->philos)->for_each(check_if_dead, NULL);
	return (o);
}

void	*run_threads(void *elem)
{
	t_philo	*philo;

	philo = (t_philo *)elem;
	if (!(philo->index % 2))
		my_usleep(50);
	while (!table()->dead)
	{
		printf("%d %d %s\n", get_time_dif(table()->start_time), ((t_philo *)philo)->index, table()->msg[THINK]);
		pthread_mutex_lock(philo->rigth);
		printf("%d %d %s\n", get_time_dif(table()->start_time), ((t_philo *)philo)->index, table()->msg[FORK]);
		pthread_mutex_lock(&philo->left);
		printf("%d %d %s\n", get_time_dif(table()->start_time), ((t_philo *)philo)->index, table()->msg[EAT]);
		my_usleep(table()->times[EAT]);
		philo->last_ate = get_time_mili();
		pthread_mutex_unlock(philo->rigth);
		pthread_mutex_unlock(&philo->left);
		printf("%d %d %s\n", get_time_dif(table()->start_time), ((t_philo *)philo)->index, table()->msg[SLEEP]);
		my_usleep(table()->times[SLEEP]);

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
		pthread_create(&dead, NULL, check_if_dead_each, NULL);
		array(table()->philos)->for_each(join_for_each, NULL);
	}
	return (0);
}
