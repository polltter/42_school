/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:38:03 by mvenanci          #+#    #+#             */
/*   Updated: 2022/10/15 16:13:52 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_instr(char const *str, char c);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	char	*trim;

	start = 0;
	len = ft_strlen(s1) - 1;
	while (ft_instr(set, s1[start]))
		start++;
	while (ft_instr(set, s1[len]))
		len--;
	len = len - start + 1;
	trim = (char *)malloc(sizeof(char) * (len + 1));
	trim[len] = 0;
	trim = ft_memcpy(trim, s1 + start, len);
	return (trim);
}

int	ft_instr(char const *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}
