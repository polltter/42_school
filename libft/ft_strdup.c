/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:19:31 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/15 16:19:31 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		len_s;

	len_s = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * len_s + 1);
	if (!dest)
		return (NULL);
	dest[len_s] = 0;
	while (--len_s >= 0)
		dest[len_s] = s[len_s];
	return (dest);
}
