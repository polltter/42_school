/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:15:59 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/15 16:15:59 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	size_t			i;

	i = -1;
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	while (++i < n)
	{
		temp_dest[i] = temp_src[i];
	}
	return (dest);
}
