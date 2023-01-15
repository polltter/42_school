/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:43:33 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/15 20:52:24 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/pipex.h"

void	redirect(t_elems *elem, int fd_in, char **env)
{
	t_cmd	*cmd;
	int		fd_out;

	if (!elem->next)
	{
		waitpid(-1, &fd_in, 0);
		return ;
	}
	cmd = (t_cmd *)elem->content;
	fd_out = cmd->fd[1];
	cmd->pid = fork();
	if (cmd->pid == -1)
		exit(0);
	else if (!cmd->pid)
	{	
		dup2(fd_out, 1);
		close(fd_out);
		dup2(fd_in, 0);
		close(fd_in);
		execve(cmd->path, cmd->args, env);
		perror("");
		exit(127);
	}
	close(fd_in);
	close(fd_out);
	redirect(elem->next, cmd->fd[0], env);
}

void	**cmds(void)
{
	static void	*cmds;

	return (&cmds);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (*(++i + split))
		free((*(i + split)));
	free(split);
}

int	main(int ac, char **av, char **env)
{
	int		fd_in;
	int		fd_out;

	if (ac > 4)
	{
		fd_in = open(av[1], O_RDONLY);
		if (fd_in == -1)
			exit(ft_printf("no such file or directory: %s\n", av[1]));
		fd_out = open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd_in == -1)
			exit(ft_printf("no such file or directory: %s\n", av[ac - 1]));
		init_cmds(ac - 2, split(find_path_var(env), ':'), av + 2, fd_out);
		redirect(array(*cmds())->begin, fd_in, env);
		array(*cmds())->destroy();

	}
}
