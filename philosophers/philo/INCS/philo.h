/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:25:22 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/22 11:09:07 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include "../SRCS/list_utils/list_utils.h"

typedef struct s_table t_table;
typedef struct s_philo t_philo;
typedef struct s_args t_args;
typedef unsigned int t_usec;

enum e_status {
	EAT,
	SLEEP,
	THINK,
	FORK,
	DIE
};

struct s_philo
{
	pthread_t		id;
	t_usec			last_ate;
	pthread_mutex_t left;
	pthread_mutex_t *rigth;
	int 			eaten;
	int				index;
};

struct s_table
{
	void	*philos;
	int 	times[5];
	char 	*msg[5];
	int 	dead;
	int 	times_to_eat;
	pthread_mutex_t fork;
};

//utils
int		ft_atoi(char *s);
void	my_usleep(int mili_sec);
t_table	*table(void);
void	give_forks(t_elems *elem, void *o);
int		get_time_mili(void);
//parsing
int		check_args(int ac, char **av);
void	init_table(int n_philo, int t_eat, int t_sleep, int t_die, int times_to_eat);

#endif