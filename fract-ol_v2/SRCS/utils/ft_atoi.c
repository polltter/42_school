/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:52:40 by mvenanci          #+#    #+#             */
/*   Updated: 2023/01/08 17:50:51 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/fractol.h"

int	ft_atoi(char *nptr)
{
	int	sign;
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb *= 10;
		nb += nptr[i] - '0';
		i++;
	}
	return (sign * nb);
}

double	ft_atod(char *s)
{
	int		i;
	double	d;
	int		sign;

	sign = 1;
	d = 0;
	i = ft_atoi(s);
	if (*s == '-')
		sign = -1;
	while (*s)
		s++;
	while (*(--s) >= '0' && *s <= '9')
	{
		d += *s - '0';
		d /= 10.0;
	}
	return (sign * d + i);
}
