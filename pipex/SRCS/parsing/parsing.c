/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:15:44 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/19 22:00:45 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/pipex.h"

char	*find_path_var(char **env)
{
	while (*env)
	{
		if (!ft_strncmp(*env, "PATH=", 5))
			return (*env + 5);
		env++;
	}
	return (NULL);
}

char	*find_cmds(char **paths, char *av)
{
	char	*temp;

	if (!av)
		return (ft_calloc(1));
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
