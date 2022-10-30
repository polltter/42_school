/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:14:31 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/15 16:14:31 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*temp_s;
	size_t	i;

	i = -1;
	temp_s = (char *)s;
	while (++i < n)
		if (temp_s[i] == (char)c)
			return (&temp_s[i]);
	return (NULL);
}
