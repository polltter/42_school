/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:25:22 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/02/01 21:39:35 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "pthread.h"
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
	pthread_mutex_t ate;
	int 			times_eaten;
	int				index;
	int 			n_forks;
};

struct s_table
{
	void	*philos;
	int 	times[5];
	char 	*msg[5];
	int 	start_time;
	int 	times_to_eat_each;
	int 	times_to_eat;
	int 	eat;
	int		n_philo;
	pthread_mutex_t	total_times_to_eat;
};

//utils
int		ft_atoi(char *s);
t_table	*table(void);
int 	break_while(void);
void	*check_if_dead_each(void *begin);
pthread_t	*get_thread_dead(void);
void	increase_times_eaten(void);
int	check_times_eaten(void);
int	check_if_dead(t_elems *elems);

//for_each_utils
void	init(t_elems *elem, void *o);
void	join_for_each(t_elems *elem, void *o);
void	detach_each(t_elems *elem, void *o);
void	mutex_destroy_each(t_elems *elem, void *o);
//time_utils
int		get_time_mili(void);
void	my_usleep(int mili_sec);
int		get_time_dif(int last_ate);
void	set_philo_time(t_philo *philo);

//parsing
int		check_args(int ac, char **av);
void	init_table(int n_philo, int t_eat, int t_sleep, int t_die, int times_to_eat);
void	give_forks(t_elems *elem, void *o);

//runnig
void	*run_threads(void *elem);
#endif