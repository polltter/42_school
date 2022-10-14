/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:23:17 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/13 16:37:35 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	count;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		count = 0;
		while (big[i + count] != '\0' && big[i + count] == little[count] \
		&& i + count < len)
		{
			if (little[count + 1] == '\0')
				return ((char *)&big[i]);
			count++;
		}
		i++;
	}
	return (0);
}
