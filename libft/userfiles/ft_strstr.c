/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:23:17 by mvenanci          #+#    #+#             */
/*   Updated: 2022/09/20 09:20:59 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	count;

	i = 0;
	if (little[0] == '\0')
		return (big);
	while (big[i] != '\0' && i < len)
	{
		count = 0;
		while (big[i + count] != '\0' && big[i + count] == little[count] \
		&& i + count < len)
		{
			if (little[count + 1] == '\0')
				return (&big[i]);
			count++;
		}
		i++;
	}
	return (0);
}
