/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:19:04 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/17 16:02:04 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_vars(va_list args, char *print_params, int i)
{
	if (print_params[i] == 'd' || print_params[i] == 'i')
		print_nbr(print_params[i], va_arg(args, int));
	else if (print_params[i] == 'u')
		print_nbr(print_params[i], va_arg(args, unsigned int));
	else if (print_params[i] == 's')
		print_chars(print_params[i], va_arg(args, char *));
	else if (print_params[i] == 'c')
		print_chars(print_params[i], va_arg(args, int));
	else if (print_params[i] == 'x' || print_params[i] == 'X')
		ft_print_x(print_params[i], va_arg(args, unsigned int));
	else if (print_params[i] == 'p')
		ft_print_p(va_arg(args, long unsigned int));
	else if (print_params[i] == '%')
		write(1, "%%", 1);
}

int	*ft_find_order(const char *ph, int size)
{
	int	*order;
	int i;
	int	index;	

	index = 0;
	i = -1;
	order = (int *)malloc(sizeof(int) * size);
	while (ph[++i])
	{
		if (ph[i] == '%')
		{
			order[index] = 1;
			index++;
			i++;
		}
		else
		{
			while (ph[i] != '%' && ph[i])
			{
				if (ph[i + 1] == '%' || !ph[i + 1])
				{
					order[index] = 2;
					index++;
					break ;
				}
				i++;
			}
			
		}
	}
	return (order);
}

void	print_cutlines(const char *ph, va_list args, char *print_params, \
int *order)
{
	int	i;
	int	words;
	int	params;
	char	**splitted;
	
	i = -1;
	words = 0;
	params = 0;
	splitted = ft_split_mod(ph, '%');
	while (++i < num_params(ph) + word_counter(ph, '%'))
	{
		if (order[i] == 1)
		{
			print_vars(args, print_params, params);
			params++;
		}
		else
		{
			ft_putstr_fd(splitted[words], 1);
			words++;
		}
	}
}

int	ft_printf(const char *ph, ...)
{
	va_list args;
	char	*print_params;
	int		*order;

	print_params = params(ph);
	order = ft_find_order(ph, num_params(ph) + word_counter(ph, '%'));
	va_start(args, ph);
	print_cutlines(ph, args, print_params, order);
	va_end(args);
	return (1);
}