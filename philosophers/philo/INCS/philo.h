/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:25:22 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/21 16:27:14 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include "../SRCS/list_utils/list_utils.h"

typedef struct s_philo t_philo;
typedef unsigned int t_usec;

struct s_philo
{
	int		philo_id;
	int		has_fork;
	t_usec	t_sleep;
	t_usec	t_die;
	t_usec	t_eat;
};

int		ft_atoi(char *s);

#endif