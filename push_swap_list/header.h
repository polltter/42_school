/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:09:16 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/18 14:45:51 by mvenanci         ###   ########.fr       */
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

#endif