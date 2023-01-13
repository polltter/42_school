/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:15:44 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/13 19:07:27 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/pipex.h"

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
		if ((*env)[0] == 'P' && check_if_path(*env))
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

void	find_cmds(char **paths, char **av)
{
	char	*temp;
	char	**og_path;
	
	og_path = paths;
	while (*(av + 1))
	{
		while (*paths)
		{
			temp = str_join(*paths, *av, '/');
			if (!access(temp, F_OK))
			{
				array(*cmds())->add(create_cmd(temp));
				break ;
			}
			free(temp);
			paths++;
		}
		if (!*paths)
			array(*cmds())->add(create_cmd(str_dup(*av)));
		array(*cmds())->end->del = del_cmd;
		av++;
		paths = og_path;
	}
}
