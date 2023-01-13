/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:43:33 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/13 19:17:58 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/pipex.h"

void	redirect(int fd_in, int fd_out)
{
	dup2(fd_in, 0);
	dup2(fd_out, 1);
}

void	**cmds(void)
{
	static void	*cmds;

	return (&cmds);
}

void	free_split(char **split)
{
		int i = -1;
		
		while (*(++i + split))
			free((*(i + split)));
		free(split);
}

int	main(int ac, char **av, char **env)
{
	char	**paths;
	int		pid;
	int		fd_in;
	int		fd_out;
	t_elems	*temp;
	t_cmd	*temp_cmd;
	
	if (ac > 4)
	{
		*cmds() = creat_array();
		paths = split(find_path_var(env), ':');
		find_cmds(paths, av + 2);
		fd_in = open(av[1]);
		temp = array(*cmds())->begin;
		while (temp)
		{
			temp_cmd = (t_cmd *)temp->content;
			pipe(temp_cmd->fd);
			pid = fork();
			if (pid == -1)
				exit(0);
			else if (!pid)
			{
				redirect(fd_in, temp_cmd->fd[1]);
				execve(temp_cmd->path, temp_cmd->args, env);
				perror("");
				exit(0);
			}
			close(temp_cmd->fd[1]);
		}
		array(*cmds())->destroy();
		free_split(paths);
	}
}
