/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:33:27 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/21 13:33:43 by mvenanci@st      ###   ########.fr       */
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

void	*create_philosopher(unsigned long id)
{
	t_philo	*philo;

	philo = ft_calloc(sizeof(t_philo));
	philo->id = id;
	return (philo);
}

t_table	*create_table(int n_philo, int t_eat, int t_sleep, int t_die, int times_to_eat)
{
	static t_table	table;

	table.philos = creat_array();
	while (n_philo--)
		array(table.philos)->add(create_philosopher(n_philo));
	table.times[EAT] = t_eat;
	table.times[SLEEP] = t_sleep;
	table.times[DIE] = t_die;
	table.msg[EAT] = "is eating";
	table.msg[SLEEP] = "is sleeping";
	table.msg[DIE] = "died";
	table.msg[THINK] = "is thinking";
	table.msg[FORK] = "has taken a fork";
	table.times_to_eat = times_to_eat;
	return (&table);
}
