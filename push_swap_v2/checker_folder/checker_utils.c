/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:40:52 by mvenanci          #+#    #+#             */
/*   Updated: 2022/11/27 17:42:58 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	move_code(char *move)
{
	int	code;
	int	i;

	i = -1;
	code = 0;
	while (move[++i] && move[i] != '\n')
		code += move[i];
	return (code);
}