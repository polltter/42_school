/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:15:44 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/15 20:58:23 by mvenanci@st      ###   ########.fr       */
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
		if ((*env)[0] == 'P' && check_if_path(*env))
			return (*env + 5);
		env++;
	}
	return (NULL);
}

char	*find_cmds(char **paths, char *av)
{
	char	*temp;

	while (*paths)
	{
		temp = str_join(*paths, av, '/');
		if (!access(temp, F_OK))
			return (temp);
		free(temp);
		paths++;
	}
	return (str_dup(av));
}
