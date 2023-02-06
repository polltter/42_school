/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_each_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:30:00 by mvenanci          #+#    #+#             */
/*   Updated: 2023/02/05 16:36:57 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/philo.h"

void	init(t_elems *elem, void *o)
{
	(void)o;
	pthread_create(&(((t_philo *)(elem->content))->id), \
	NULL, run_threads, elem->content);
}

void	join_for_each(t_elems *elem, void *o)
{
	(void)o;
	pthread_join(((t_philo *)(elem->content))->id, NULL);
}

void	detach_each(t_elems *elem, void *o)
{
	(void)o;
	pthread_detach(((t_philo *)(elem->content))->id);
}

void	mutex_destroy_each(t_elems *elem, void *o)
{
	(void)o;
	pthread_mutex_destroy(&((t_philo *)(elem->content))->left);
}
