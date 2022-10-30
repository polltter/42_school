/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:48:03 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/30 15:10:13 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	str_len;

	str_len = ft_strlen(s);
	if (start > str_len)
	{
		sub = (char *)malloc(sizeof(char));
		*sub = 0;
		return (sub);
	}
	if (len >= str_len)
		len = str_len - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	sub[len] = 0;
	return (ft_memcpy(sub, s + start, len));
}
