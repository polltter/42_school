/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:09:16 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/12 10:33:51 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack{
	int	*arr;
	int	len;
}	t_stack;

int			is_d(char *c);
long int	ft_atoi(char *s, t_stack *stack_a, int index);
int			check_doubles(int *stack, int i, int a);
void		rotate(t_stack *stack);

#endif