/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:09:16 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/17 15:36:17 by mvenanci@st      ###   ########.fr       */
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
char		**split(char *s);

//moving

#endif