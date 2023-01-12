/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:15:44 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/11 20:47:04 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/pipex.h"

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

