/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:33:47 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/08 18:19:38 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/fractol.h"

int	is_digit(char *s)
{
	while (*s)
	{
		if (!(*s <= '9' && *s >= '0'))
			return (0);
		s++;
	}
	return (1);
}

int	is_double(char *s)
{
	if (*s == '-')
		s++;
	while (*s)
	{
		if (*s == '.')
		{
			s++;
			break ;
		}
		else if (!(*s <= '9' && *s >= '0'))
			return (0);
		s++;
	}
	while (*s)
	{
		if (!(*s <= '9' && *s >= '0'))
			return (0);
		s++;
	}
	return (1);
}

void	error_handle(void)
{
	int	a;

	a = write(1, "\nIncorrect inputs!\n", 19);
	a = write(1, "==========================================\n", 43);
	a = write(1, "The first parameter shoud be one of the following:\n", 51);
	a = write(1, "M for the Mandlebrot set\n", 25);
	a = write(1, "J for the Julia set\n", 20);
	a = write(1, "K for the Koch triangle\n", 24);
	a = write(1, "==========================================\n", 43);
	a = write(1, "The second parameter shoud be the number of iterations, \
a positive int.\n", 77);
	a = write(1, "==========================================\n", 43);
	a = write(1, "The third and fourth parameters shoud be the initial seed \
for the julia set. Both are doubles.\n\n", 95);
	(void)a;
	exit (0);
}

int	verify_input(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (i == 1 && av[1][0] != 'M' && av[1][0] != 'J' && av[1][0] != 'K')
			return (0);
		else if (i == 2 && !is_digit(av[i]))
			return (0);
		else if (i == 2 && is_digit(av[i]) && ft_atoi(av[i]) <= 0)
			return (0);
		else if (i > 2 && !is_double(av[i]))
			return (0);
	}
	return (1);
}
