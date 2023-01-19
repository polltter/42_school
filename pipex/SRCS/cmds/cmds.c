/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:01:28 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/19 22:01:11 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/pipex.h"

void	**cmds(void)
{
	static void	*cmds;

	return (&cmds);
}

void	del_cmd(void *cmd)
{
	t_cmd	*tmp;
	int		i;

	tmp = (t_cmd *)cmd;
	i = -1;
	free(tmp->path);
	while (*(tmp->args + ++i))
		free(*(tmp->args + i));
	free(tmp->args);
	free(tmp);
}

void	init_cmds(int size, char **paths, char **args, int fd_out)
{
	int	i;

	i = -1;
	*cmds() = creat_array();
	while (++i < size)
		(array(*cmds()))->add(create_cmd(args[i], paths))->del = del_cmd;
	((t_cmd *)((array(*cmds()))->end->prev->content))->fd[1] = fd_out;
	free_split(paths);
}

t_cmd	*create_cmd(char *arg, char **paths)
{
	t_cmd	*new;

	new = ft_calloc(sizeof(t_cmd));
	new->args = split(arg, ' ');
	new->path = find_cmds(paths, *new->args);
	new->fd[0] = -1;
	new->fd[1] = -1;
	pipe(new->fd);
	return (new);
}
