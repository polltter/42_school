/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:25:22 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/02/05 16:37:56 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "pthread.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include "../SRCS/list_utils/list_utils.h"

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;
typedef struct s_args	t_args;
typedef unsigned int	t_usec;

# define EATING "is eating"
# define SLEEPING "is sleeping"
# define T "is thinking"
# define FORKING "has taken a fork"
# define DYING "died"

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
	pthread_mutex_t	left;
	pthread_mutex_t	*rigth;
	pthread_mutex_t	ate;
	int				times_eaten;
	int				index;
	int				n_forks;
};

struct s_table
{
	void			*philos;
	int				times[5];
	int				availabe_fork[300];
	char			*msg[5];
	int				start_time;
	int				times_to_eat;
	int				any_dead;
	int				eat;
	int				n_philo;
	pthread_mutex_t	total_times_to_eat;
	pthread_mutex_t	dead;
	pthread_mutex_t	print;
};

//utils
int			ft_atoi(char *s);
t_table		*table(void);
int			check_if_dead(t_elems *elems);
int			get_fork(t_philo *philo);
void		release_fork(t_philo *philo);
int			dead(void);
int			full(void);

//for_each_utils
void		init(t_elems *elem, void *o);
void		join_for_each(t_elems *elem, void *o);

//time_utils
int			get_time_mili(void);
void		my_usleep(int mili_sec);
int			get_time_dif(int last_ate);
void		set_philo_time(t_philo *philo);

//parsing
int			check_args(int ac, char **av);
void		init_table(int n_philo, int t_eat, int t_sleep, int t_die);
void		give_forks(t_elems *elem, void *o);

//runnig
void		*run_threads(void *elem);
#endif