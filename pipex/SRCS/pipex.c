/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:43:33 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/15 19:41:07 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/pipex.h"

void	redirect(t_elems *elem, int fd_in, char **env)
{
	t_cmd	*cmd;
	int		fd_out;
	char	status;

	if (!elem->next)
	{
		waitpid(-1, (int *)&status, 0);
		return ;
	}
	cmd = (t_cmd *)elem->content;
	dprintf(2, "%s %d %d\n", cmd->path, cmd->fd[0], cmd->fd[1]);
	cmd->pid = fork();
	fd_out = cmd->fd[1];
	if (!elem->next->next)
		fd_out = ((t_cmd *)(elem->next->content))->fd[1];
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
	char	**paths;
	int		fd_in;

	if (ac > 4)
	{
		fd_in = open(av[1], O_RDONLY);
		if (fd_in++ == -1)
			ft_printf("no such file or directory: %s\n", av[1]);
		*cmds() = creat_array();
		paths = split(find_path_var(env), ':');
		av += 2;
		while (*av)
		{
			(array(*cmds()))->add(create_cmd(*av, paths))->del = del_cmd;
			av++;
		}
		((t_cmd *)(array(*cmds())->end->content))->fd[1] = \
		open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		redirect(array(*cmds())->begin, fd_in, env);
		array(*cmds())->destroy();
		free_split(paths);
	}
}
