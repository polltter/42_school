/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 08:59:56 by mvenanci@st       #+#    #+#             */
/*   Updated: 2022/10/28 11:33:46 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_memcpy(char *dest, char *src, size_t n)
{
	size_t			i;

	i = -1;
	while (++i < n)
	{
		dest[i] = src[i];
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	str[len1 + len2] = 0;
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2);
	free(s1);
	return (str);
}

char	*ft_strchr(char *str, int c)
{
	if (str)
	{
		while (*str)
		{
			if (*str == c)
				return ((char *)str);
			str++;
		}
		if (*str == c)
			return ((char *)str);
	}
	return (NULL);
}
