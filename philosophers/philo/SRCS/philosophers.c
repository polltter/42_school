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

void	check_if_dead(t_elems *elems)
{
	while (elems)
	{
		pthread_mutex_lock(&table()->mutex);
		if (get_time_dif(((t_philo *)(elems->content))->last_ate) > table()->times[DIE])
		{
			table()->dead = 1;
			printf("%d %d %s\n", get_time_dif(table()->start_time), ((t_philo *)(elems->content))->index, table()->msg[DIE]);
		}
		pthread_mutex_unlock(&table()->mutex);
		elems = elems->next;
	}
}

void	set_philo_time(t_philo *philo)
{
	pthread_mutex_lock(&table()->mutex);
	philo->last_ate = get_time_mili();
	pthread_mutex_unlock(&table()->mutex);
}

void	*check_if_dead_each(void *begin)
{
	while (!table()->dead)
		check_if_dead(begin);
	return (begin);
}

void	print_philo(t_philo *philo, int status)
{
	pthread_mutex_lock(&table()->print);
	pthread_mutex_lock(&table()->mutex);
	if (!table()->dead)
		printf("%d %d %s\n", get_time_dif(table()->start_time), philo->index, table()->msg[status]);
	pthread_mutex_unlock(&table()->mutex);
	pthread_mutex_unlock(&table()->print);
}

void	*run_threads(void *elem)
{
	t_philo	*philo;

	philo = (t_philo *)elem;
	if (!(philo->index % 2))
		my_usleep(150);
	while (1)
	{
		pthread_mutex_lock(&philo->left);
		pthread_mutex_lock(philo->rigth);
		print_philo(philo, FORK);
		print_philo(philo, EAT);
		set_philo_time(philo);
		my_usleep(table()->times[EAT]);
		pthread_mutex_unlock(&philo->left);
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
	}
	return (0);
}
