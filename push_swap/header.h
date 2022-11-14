/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:09:16 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/14 13:28:46 by mvenanci         ###   ########.fr       */
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
	int	*arr;
	int	len;
}	t_stack;

//utils
int			is_d(char *c);
long int	ft_atoi(char *s, t_stack *stack_a, int index);
char		**split(char *s);

//moves
void		print_arr(int *arr, int len);
void		rotate(int **arr, int len);
void		rev_rotate(int **arr, int len);
void		swap(int **arr);

//sorts
void		sort_3(int *arr);
void		sort_2(int *arr);

#endif