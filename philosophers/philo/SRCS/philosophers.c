/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:40:55 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/21 18:02:01 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philo.h"

void	my_usleep(int mili_sec)
{
	long start;
	long end;
	struct timeval tv;

	gettimeofday(&tv, NULL);
	start = ( tv.tv_sec * 1000 + tv.tv_usec / 1000);
	end  = start;
	start += mili_sec;
	while (end < start)
	{
		gettimeofday(&tv, NULL);
		end = ( tv.tv_sec * 1000 + tv.tv_usec / 1000);
	}
}

t_table	**table(void)
{
	static t_table	*table;

	return (&table);
}

void	*create_philosopher(unsigned long id)
{
	t_philo	*philo;

	philo = ft_calloc(sizeof(t_philo));
	philo->id = id;
	return (philo);
}

t_table	*create_table(int n_philo, int t_eat, int t_sleep, int t_die)
{
	static t_table	table;

	table.philos = creat_array();
	while (n_philo-- > 0)
		array(table.philos)->add(create_philosopher(n_philo));
	table.times[EAT] = t_eat;
	table.times[SLEEP] = t_sleep;
	table.times[DIE] = t_die;
	table.msg[EAT] = "is eating";
	table.msg[SLEEP] = "is sleeping";
	table.msg[DIE] = "died";
	table.msg[THINK] = "is thinking";
	table.msg[FORK] = "has taken a fork";
	return (&table);
}

int	main(void)
{
	*table() = create_table(2, 200, 200, 200);
	return (0);
}
