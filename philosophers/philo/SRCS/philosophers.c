/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:40:55 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/26 13:37:19 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philo.h"

t_table	*table(void)
{
	static t_table	table;

	return (&table);
}

void	*run_threads(void *elem)
{
	t_philo	*philo;

	philo = (t_philo *)elem;
	
	pthread_mutex_lock(philo->rigth);
	pthread_mutex_lock(&philo->left);
	printf("%d %ld\n", table()->dead++, ((t_philo *)philo)->id);
	pthread_mutex_unlock(&philo->left);
	pthread_mutex_unlock(philo->rigth);
	return (philo);
}

void	init(t_elems *elem, void *o)
{
	(void)o;
	pthread_create(&(((t_philo *)(elem->content))->id), NULL, run_threads, elem->content);
}

void	print_fork(t_elems *elem, void *o)
{
	(void)o;
	printf("left: %p, right: %p\n", &(((t_philo *)(elem->content))->left), ((t_philo *)(elem->content))->rigth);
}

void	join_for_each(t_elems *elem, void *o)
{
	(void)o;
	pthread_join(((t_philo *)(elem->content))->id, NULL);
}

int	main(int ac, char **av)
{
	if ((ac == 5 || ac == 6) && check_args(ac, av))
	{
		if (ac == 5)
			init_table(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]), 0);
		else
			init_table(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]), ft_atoi(av[5]));
		array(table()->philos)->for_each(give_forks, NULL);
		array(table()->philos)->for_each(print_fork, NULL);
		array(table()->philos)->for_each(init, NULL);
		array(table()->philos)->for_each(join_for_each, NULL);
	}
	return (0);
}
