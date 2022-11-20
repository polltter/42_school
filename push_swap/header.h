/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:09:16 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/20 20:45:27 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "SOURCES/libft/libft.h"
# include "SOURCES/ft_printf/ft_printf.h"

int			is_d(char *c);
long int	ft_atoi(char *s, t_list **stack_a);
int			check_doubles(t_list *stack_a, t_list *curr);
char		**split(char *s, char c);

//moving and list utils
void		print_lst(t_list *a);
void		push(t_list **from, t_list **to, char c);
void		swap(t_list **a, t_list **b, char c);
void		rev_rotate(t_list **a, t_list **b, char c);
void		rotate(t_list **a, t_list **b, char c);

//sorting
int			cost(t_list **a, t_list **b, t_list *elem, int *path);
void		sort_2(t_list **a);
void		sort_3(t_list **stack);
int			**lst_to_arr(t_list *stack);
int			is_sorted(t_list *lst);
void		sort(t_list **a, t_list **b);


//sorting utils
t_list		*find_nearest(t_list *a, t_list *elem);
void		rev_rotate_until(t_list **a, t_list **b, \
t_list *elem, t_list *nearest);
void		rotate_until(t_list **a, t_list **b, t_list *elem, t_list *nearest);
void		rot_a_rev_b(t_list **a, t_list **b, t_list *elem, t_list *nearest);
void		rev_a_rot_b(t_list **a, t_list **b, t_list *elem, t_list *nearest);


#endif