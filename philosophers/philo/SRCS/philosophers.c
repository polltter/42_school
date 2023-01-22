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

t_table	**table(void)
{
	static t_table	*table;

	return (&table);
}

void	*run_threads(void *philo)
{
	int i;

	i = 0;
	printf("%d %ld\n", i++, ((t_philo *)philo)->id);
	return (philo);
}

int	main(int ac, char **av)
{
	t_elems	*elem;

	if ((ac == 5 || ac == 6) && check_args(ac, av))
	{
		if (ac == 5)
			*table() = create_table(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]), 0);
		else
			*table() = create_table(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]), ft_atoi(av[5]));
		elem = array(*table())->begin;
		printf("%p %p\n", elem, elem->next);
		//exit(0);
//		while (elem)
//		{
////			pthread_create(&(((t_philo *)(elem->content))->id), NULL, run_threads, elem->content);
//
//			printf("%p", elem->content);
//			elem = elem->next;
//		}
	}
	return (0);
}
