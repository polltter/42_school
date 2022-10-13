/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:40:32 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/13 15:35:56 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*str;

	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) + (len + 1));	
	str[len] = 0;
	while (--len > 0)	
		str[len] = (*f)(len, s[len]);
	str[len] = (*f)(len, s[len]);
	return (str);
}

char	cap(unsigned int a, char c)
{
	(void) a;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
