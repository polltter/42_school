/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:57:32 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/15 20:58:56 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/pipex.h"

char	*str_join(char *s1, char *s2, char sep)
{
	char	*path;
	int		i;
	int		j;

	j = -1;
	i = -1;
	path = ft_calloc(str_len(s1) + str_len(s2) + 2);
	while (s1 && s1[++i])
		path[i] = s1[i];
	path[i++] = sep;
	while (s2 && s2[++j])
		path[i + j] = s2[j];
	return (path);
}

int	str_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*str_dup(char *s)
{
	char	*new;
	int		i;

	i = -1;
	new = ft_calloc(str_len(s) + 1);
	while (s[++i])
		new[i] = s[i];
	return (new);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (*(++i + split))
		free((*(i + split)));
	free(split);
}
