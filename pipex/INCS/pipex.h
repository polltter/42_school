/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:14:07 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/20 09:07:34 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include "../SRCS/ft_printf/ft_printf.h"
# include "../SRCS/list_utils/list_utils.h"
# include "../bonus/gnl_remastered/get_next_line.h"
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_cmd	t_cmd;

struct s_cmd{
	char	*path;
	char	**args;
	int		fd[2];
	int		pid;
};

//strs
int		str_len(char *s);
char	**split(char *s, char c);
char	*str_join(char *s1, char *s2, char sep);
char	*str_dup(char *s);
void	free_split(char **split);
int		ft_strncmp(char *s1, char *s2, int n);
int		str_char(char *s, char c);
//commands
t_cmd	*create_cmd(char *arg, char **paths);
void	del_cmd(void *cmd);
void	**cmds(void);
void	init_cmds(int size, char **paths, char **args, int fd_last);

//parsing
char	*find_path_var(char **env);
char	*find_cmds(char **paths, char *av);
void	parse_here_doc(int *fd_in, char *av, int *flag);

//gnl
char	*get_next_line(int fd);
#endif