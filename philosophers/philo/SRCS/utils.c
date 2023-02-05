/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:22:21 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/02/01 21:28:24 by mvenanci         ###   ########.fr       */
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

pthread_t	*get_thread_dead(void)
{
	static pthread_t	thread_dead;

	return (&thread_dead);
}

int	check_if_dead(t_elems *elems)
{
	while (elems)
	{
		pthread_mutex_lock(&((t_philo *)(elems->content))->ate);
		if (get_time_dif(((t_philo *)(elems->content))->last_ate) > table()->times[DIE])
		{
			pthread_mutex_unlock(&((t_philo *)(elems->content))->ate);
			printf("%d %d %s\n", get_time_dif(table()->start_time), ((t_philo *)(elems->content))->index, table()->msg[DIE]);
			pthread_mutex_lock(&table()->dead);
			table()->any_dead = 1;
			pthread_mutex_unlock(&table()->dead);
			return (0);
		}
		pthread_mutex_unlock(&((t_philo *)(elems->content))->ate);
		elems = elems->next;
	}
	return (1);
}