/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:33:27 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/02/05 16:33:37 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philo.h"

int	is_digit(char *s)
{
	while (s && *s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!is_digit(av[i]))
			return (printf("Invalid argument\n") == 0);
		if (i == 1 && ft_atoi(av[1]) > 200)
			return (printf("Invalid number of philosophers\n") == 0);
	}
	return (1);
}

void	*create_philosopher(unsigned long id, int index)
{
	t_philo	*philo;

	philo = ft_calloc(sizeof(t_philo));
	philo->id = id;
	philo->index = index;
	philo->n_forks = 0;
	philo->times_eaten = 0;
	return (philo);
}

void	give_forks(t_elems *elem, void *o)
{
	(void)o;
	if (!elem->next)
		((t_philo *)(elem->content))->rigth = \
		&(((t_philo *)(array(table()->philos)->begin->content))->left);
	else
		((t_philo *)(elem->content))->rigth = \
		&(((t_philo *)(elem->next->content))->left);
}

void	init_table(int n_philo, int t_die, int t_eat, int t_sleep)
{
	int	index;

	index = 0;
	table()->philos = creat_array();
	table()->n_philo = n_philo;
	table()->eat = 0;
	array(table()->philos)->add(create_philosopher(n_philo, index);
	while (n_philo-- && ++index)
	{
		pthread_mutex_init(&(((t_philo *)array(table()->philos) \
		->add(create_philosopher(n_philo, index))->content)->left), NULL);
		pthread_mutex_init(&((t_philo *)(((t_array *)(table()->philos)) \
		->end->content))->ate, NULL);
		((t_philo *)(((t_array *)(table()->philos))->end->content))\
		->last_ate = get_time_mili();
		table()->availabe_fork[index] = 1;
	}
	table()->times[EAT] = t_eat;
	table()->times[SLEEP] = t_sleep;
	table()->times[DIE] = t_die;
	pthread_mutex_init(&table()->total_times_to_eat, NULL);
	pthread_mutex_init(&table()->print, NULL);
}
