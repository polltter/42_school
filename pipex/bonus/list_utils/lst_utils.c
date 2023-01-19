/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:22:19 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/19 22:13:34 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils.h"

t_array	**__this(void);

void	__del(t_elems *elem)
{
	if ((*__this())->begin == elem)
	{
		(*__this())->begin = (*__this())->begin->next;
		(*__this())->begin->prev = 0;
	}
	else
	{
		elem->prev->next = elem->next;
		if (elem->next)
			elem->next->prev = elem->prev;
	}
	if (elem->del)
		elem->del(elem);
	free(elem);
	(*__this())->size--;
}

void	__for_each(void (*func)(t_elems *elem, void *p), void *o)
{
	t_elems	*temp;

	temp = (*__this())->begin;
	while (temp)
	{
		func(temp, o);
		temp = temp->next;
	}
}

static void	default_content_destroy(void *content)
{
	free(content);
}

t_elems	*__add(void *content)
{
	t_elems	*new;

	if (!content)
		return (NULL);
	new = ft_calloc(sizeof(t_elems));
	new->del = default_content_destroy;
	new->content = content;
	if (!(*__this())->begin)
		(*__this())->begin = new;
	else
	{
		new->prev = (*__this())->end;
		(*__this())->end->next = new;
	}
	(*__this())->end = new;
	(*__this())->size++;
	return (new);
}

void	__destroy(void)
{
	t_elems	*temp;
	t_elems	*temp2;

	temp = (*__this())->begin;
	while (temp)
	{
		temp2 = temp->next;
		if (temp->del)
			temp->del(temp->content);
		free(temp);
		temp = temp2;
	}
	free(*__this());
	*__this() = NULL;
}
