/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:09:16 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/15 17:55:12 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "SOURCES/ft_printf/ft_printf.h"

typedef struct s_stack{
	int		*arr;
	int		len;
	char	c;
}	t_stack;

//utils
int			is_d(char *c);
long int	ft_atoi(char *s, t_stack *stack_a, int index);
char		**split(char *s);
void		cut_lines_2(t_stack *a, t_stack *b);
void		cut_lines(t_stack *a, t_stack *b);
void		helper(t_stack *a, t_stack *b, int i);
void		helper_2(t_stack *a, t_stack *b);
int			word_count(char *s);

//moves
void		print_arr(t_stack *stack);
void		rotate(t_stack *stack);
void		rev_rotate(t_stack *stack);
void		swap(t_stack *stack);
void		push(t_stack *from, t_stack *to);

//sorts
void		sort_3(t_stack *stack);
void		sort_2(t_stack *stack);
void		sort_5(t_stack *a, t_stack *b);
void		cut_lines_2(t_stack *a, t_stack *b);
void		cut_lines(t_stack *a, t_stack *b);

#endif