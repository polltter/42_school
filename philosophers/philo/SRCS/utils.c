/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:22:21 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/21 16:25:08 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philo.h"

int	ft_atoi(char *s)
{
	int			i;
	int			sign;
	long int	n;

	n = 0;
	i = 0;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		n = n * 10 + s[i] - '0';
		i++;
	}
	return (n * sign);
}

t_table	*table(void)
{
	static t_table	table;

	return (&table);
}

void	check_if_dead(t_elems *elems)
{
	while (elems)
	{
		pthread_mutex_lock(&table()->mutex);
		if (get_time_dif(((t_philo *)(elems->content))->last_ate) > table()->times[DIE])
		{
			table()->dead = 1;
			printf("%d %d %s\n", get_time_dif(table()->start_time), ((t_philo *)(elems->content))->index, table()->msg[DIE]);
			pthread_mutex_unlock(&table()->mutex);
			return ;
		}
		pthread_mutex_unlock(&table()->mutex);
		elems = elems->next;
	}
}

void	*check_if_dead_each(void *begin)
{
	while (!table()->dead)
		check_if_dead(begin);
	return (begin);
}

int break_while(void)
{
	pthread_mutex_lock(&table()->mutex);
	if (table()->dead)
	{
		pthread_mutex_unlock(&table()->mutex);
		return (1);
	}
	pthread_mutex_unlock(&table()->mutex);
	return (0);
}
