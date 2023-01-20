/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci <mvenanci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:15:44 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/20 00:19:50 by mvenanci         ###   ########.fr       */
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

void	parse_here_doc(int *fd_in, int *fd_out, char *av, int *flag)
{
	int		fd_temp;
	char	buffer[100];
	char	*s;
	
	buffer[0] = 0;
	*fd_in = open("temp", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	while (ft_strncmp(s, av, str_len(av)))
	{
		while(str_char(buffer, '\n'))
		{
			read(0,buffer, 100);
			write(*fd_in, buffer, 100);
		}
		s = getnextline(fd_temp);
	}
	
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
