/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:19:04 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/16 08:38:41 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *ph, ...)
{
	va_list args;
	int		num_args;
	int		i;

	i = -1;
	num_args = num_params(ph);
	va_start(args, ph);
	while (++i < num_args)
	{
		
	}
	
}