/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:43:33 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/20 17:37:49 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/pipex.h"

int	dup_and_close(int fd_in, int fd_out)
{
	if (dup2(fd_out, 1) < 0)
		return (-1);
	close(fd_out);
	if (dup2(fd_in, 0) < 0)
		return (-1);
	if (fd_in)
		close(fd_in);
	return (1);
}

void	error_handle(char *cmd)
{
	if (!*cmd)
		write(2, "Permission denied\n", 18);
	else
	{
		write(2, "command not found: ", 19);
		while (*cmd)
		{
			write(2, cmd, 1);
			cmd++;
		}
		write(2, "\n", 1);
	}
}

void	execute(t_elems *elem, int fd_in, char **env, int ac)
{
	t_cmd	*cmd;
	int		fd_out;

	if (!elem->next)
	{
		while (ac--)
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
		if (dup_and_close(fd_in, fd_out) >= 0)
			execve(cmd->path, cmd->args, env);
		error_handle(cmd->path);
		exit(127);
	}
	close(fd_in);
	close(fd_out);
	execute(elem->next, cmd->fd[0], env, ac);
}

int	treat_infile(char *av)
{
	int	fd[2];

	perror(av);
	pipe(fd);
	close(fd[1]);
	return (fd[0]);
}

int	main(int ac, char **av, char **env)
{
	int		fd_in;
	int		fd_out;
	int		flag;

	if (ac > 4)
	{
		flag = 2;
		if (!ft_strncmp(av[1], "here_doc", 9))
		{
			parse_here_doc(&fd_in, *(av + 2), &flag);
			fd_out = open(av[ac - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
		}
		else
		{
			fd_in = open(av[1], O_RDONLY);
			if (fd_in == -1 && flag++ && fd_in++)
				fd_in = treat_infile(av[1]);
			fd_out = open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		}
		if (fd_out == -1)
			exit(ft_printf("Couldn't open %s\n", av[ac - 1]));
		init_cmds(ac - flag, split(find_path_var(env), ':'), av + flag, fd_out);
		execute(array(*cmds())->begin, fd_in, env, ac - flag);
		array(*cmds())->destroy();
	}
}
