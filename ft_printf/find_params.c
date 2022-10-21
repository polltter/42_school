/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:32:51 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/20 11:16:03 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_params(const char *s)
{
	int	i;
	int count;

	count = 0;
	i = -1;
	while (s[++i])
		if (s[i] == '%')
		{
			i++;
			count++;
		}
	return (count);
}

char	*params(const char *s)
{
	char	*params;
	int		n_params;
	int		i;
	int		count;

	count = 0;
	i = -1;
	n_params = num_params(s);	
	params = (char *)malloc(sizeof(char) * (n_params + 1));
	params[n_params] = 0;
	while (s[++i] && count < n_params)
		if (s[i] == '%')
		{
			params[count] = s[++i];
			count++;
		}
	return (params);
}
