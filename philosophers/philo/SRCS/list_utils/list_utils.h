/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:03:30 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/19 22:18:20 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTILS_H
# define LIST_UTILS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_elems	t_elems;
typedef struct s_array	t_array;

struct s_elems{
	void	*content;
	void	(*del)(void *content);
	t_elems	*next;
	t_elems	*prev;
};

struct s_array{
	t_elems	*begin;
	t_elems	*end;
	int		size;
	t_elems	*(*add)(void *content);
	void	(*remove)(t_elems *elem_to_del);
	void	(*for_each)(void (*func)(t_elems	*elem, void *o), void *o);
	void	(*destroy)(void);
};

t_array	*array(void *lst);
void	*ft_calloc(size_t size);
void	*creat_array(void);

#endif