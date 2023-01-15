/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:01:28 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/15 19:38:09 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/pipex.h"

void	del_cmd(void *cmd)
{
	t_cmd	*tmp;
	int		i;

	tmp = (t_cmd *)cmd;
	i = -1;
	while (*(tmp->args + ++i))
		free(*(tmp->args + i));
	free(tmp->args);
	free(tmp);
}

t_cmd	*create_cmd(char *arg, char **paths)
{
	t_cmd	*new;

	new = ft_calloc(sizeof(t_cmd));
	new->args = split(arg, ' ');
	new->path = find_cmds(paths, *new->args);
	pipe(new->fd);
	return (new);
}
