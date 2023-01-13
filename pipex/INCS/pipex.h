/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:14:07 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/13 19:04:05 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include "../SRCS/ft_printf/ft_printf.h"
# include "../SRCS/list_utils/list_utils.h"

typedef struct s_cmd t_cmd;

struct s_cmd{
	char	*path;
	char	**args;
	int		fd[2];	
};

//
int		str_len(char *s);
char	**split(char *s, char c);
char	*str_join(char *s1, char *s2, char sep);
char	*str_dup(char *s);

//commands
t_cmd	*create_cmd(char *path);
void	del_cmd(void *cmd);
void	**cmds(void);

//parsing
char	*find_path_var(char **env);
void	find_cmds(char **paths, char **av);
#endif