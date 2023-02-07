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
		if (!is_digit(av[i]))
			return (printf("Invalid argument\n") == 0);
	return (1);
}

void	*create_philosopher(int index)
{
	t_philo	*philo;

	philo = ft_calloc(sizeof(t_philo));
	philo->index = index;
	philo->times_eaten = 0;
	return (philo);
}

void	init_table(int n_philo, int t_die, int t_eat, int t_sleep)
{
	int	index;

	index = 0;
	table()->philos = creat_array();
	table()->n_philo = n_philo;
	table()->eat = 0;
	sem_unlink("/forks");
	table()->forks = sem_open("/forks", O_CREAT, 0666, n_philo);
	while (n_philo-- && ++index)
	{
		((t_philo *)array(table()->philos) \
		->add(create_philosopher(index))->content)->last_ate = get_time_mili();
	}
	table()->times[EAT] = t_eat;
	table()->times[SLEEP] = t_sleep;
	table()->times[DIE] = t_die;
}
