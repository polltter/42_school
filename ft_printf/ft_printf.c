/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:19:04 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/16 14:47:26 by mvenanci         ###   ########.fr       */
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

int	*ft_find_order(char *ph, int size)
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
				if (ph[i + 1] != '%' || ph[i + 1])
				{
					order[index] = 2;
					break ;
				}
				i++;
			}
			
		}
	}
	return (order);
}

int	ft_printf(char *ph, ...)
{
	va_list args;
	int		num_args;
	int		i;
	char	*print_params;
	char	**splitted;
	int		num_words;

	i = -1;
	num_args = num_params(ph);
	print_params = params(ph);
	va_start(args, ph);
	splitted = ft_split_mod(ph, '%');
	num_words = word_counter(ph, '%');
	while (++i < num_args && i < num_args)
	{
		ft_putstr_fd(splitted[i], 1);
		print_vars(args, print_params, i);
	}
	if (num_words < num_args)
	{
		while (i < num_args)
		{
			print_vars(args, print_params, i);
			i++;
		}
		
	}
	else if (num_words > num_args)
	{
		while (i < num_args)
		{
			ft_putstr_fd(splitted[i], 1);
			i++;
		}
	}
	return (1);
}