/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:15:44 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/20 17:31:39 by mvenanci@st      ###   ########.fr       */
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

void	parse_here_doc(int *fd_in, char *lim, int *flag)
{
	char	*s;

	*fd_in = open("temp", O_WRONLY | O_TRUNC | O_CREAT, 0666);
	s = ft_calloc(1);
	lim = str_join(lim, "", '\n');
	while (ft_strncmp(s, lim, str_len(lim)))
	{
		free(s);
		s = get_next_line(0);
		if (!ft_strncmp(s, lim, str_len(lim)))
			break ;
		write(*fd_in, s, str_len(s));
	}
	free(s);
	free(lim);
	close(*fd_in);
	*fd_in = open("temp", O_RDONLY);
	*flag += 1;
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
