/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:47:12 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/27 18:48:08 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../header.h"
# include "gnl_remastered/get_next_line.h"

int		move_code(char *move);
void	checker_rotate(t_list **a, t_list **b, char c);
void	checker_rev_rotate(t_list **a, t_list **b, char c);
void	checker_swap(t_list **a, t_list **b, char c);
void	checker_push(t_list **from, t_list **to);
void	cut_lines(t_list **stack_a, t_list **stack_b);
void	aply_moves(t_list **a, t_list **b, char *move);

#endif