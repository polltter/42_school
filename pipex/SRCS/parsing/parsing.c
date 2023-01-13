/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:15:44 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/13 09:51:58 by mvenanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/pipex.h"

int	check_if_path(char *s)
{
	int	i;

	i = 0;
	if (s[++i] == 'A')
		if (s[++i] == 'T')
			if (s[++i] == 'H')
				return (1);
	return (0);
}

char	*find_path_var(char **env)
{
	while (*env)
	{
		if ((*env)[0] == 'P')
			if (check_if_path(*env))
				return (*env + 5);
		env++;
	}
	return (NULL);
}

int	str_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

void	find_cmds(char **paths, char **av, void *cmds)
{
	char	*temp;
	
	while (*(av + 1))
	{
		while (*paths)
		{
			temp = str_join(*paths, *av, '/');
			if (!access(temp, F_OK))
			{
				array(cmds)->add(temp);
				break ;
			}
			free(temp);
			paths++;
		}
		av++;
	}
}