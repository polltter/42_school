/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:14:50 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/15 16:14:50 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(char const *str, int c)
{
	char	*temp;

	temp = (char *)str;
	while (*str)
		str++;
	if (*str == (char)c)
		return ((char *)str);
	while (str != temp)
	{
		if (*str == (char)c)
			return ((char *)str);
		str--;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}
