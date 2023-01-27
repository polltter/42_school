//
// Created by mvenanci on 1/27/23.
//

#include "../../INCS/philo.h"

void	init(t_elems *elem, void *o)
{
	(void)o;
	pthread_create(&(((t_philo *)(elem->content))->id), NULL, run_threads, elem->content);
}

void	join_for_each(t_elems *elem, void *o)
{
	(void)o;
	pthread_join(((t_philo *)(elem->content))->id, NULL);
}
