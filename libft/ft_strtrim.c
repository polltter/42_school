/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:38:03 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/31 08:48:34 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		start;
	char	*trim;

	start = 0;
	len = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (len >= 0 && ft_strchr(set, s1[len]))
		len--;
	if (start > len)
	{
		trim = ft_calloc(1, 1);
		return (trim);
	}
	len = len - start + 1;
	trim = (char *)malloc(sizeof(char) * (len + 1));
	if (!trim)
		return (NULL);
	trim[len] = 0;
	trim = ft_memcpy(trim, s1 + start, len);
	return (trim);
}
