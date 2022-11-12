/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:09:16 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/12 19:19:31 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack{
	int				data;
	struct s_stack	*next;
}	t_stack;

int			is_d(char *c);
long int	ft_atoi(char *s, t_stack **stack_a);
int			check_doubles(t_stack *stack_a, t_stack *curr);

//moving
void		rotate(t_stack **stack);
void		rev_rotate(t_stack **stack);
void		push_a(t_stack **stack_a, t_stack **stack_b);
void		push_b(t_stack **stack_a, t_stack **stack_b);
void		swap(t_stack **stack);

//lists
t_stack		*create_node(int data);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstclear(t_stack **lst);
t_stack		*ft_lstlast(t_stack *lst);
void		delete_last(t_stack **stack);

#endif