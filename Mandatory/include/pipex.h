/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:40:34 by djin              #+#    #+#             */
/*   Updated: 2023/08/07 17:35:55 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define ENV_PATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:"
# define FORK_FAIL "Fail to fork"

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <sys/types.h>
# include "../../libft/libft.h"

typedef struct s_pipex
{
	int		fd[2];
	int		outfile;
	int		infile;
	char	**split_path;
	char	*cmd;
	char	**split_cmd;
	char	*cmd_path;
	char	**result;
	pid_t	pid;
}			t_pipex;

void	parent_process(t_pipex pipe, char *argv, char **envp, char *outfile);
void	child_process(t_pipex pipe, char *argv, char **envp, char *infile);
char	*find_cmd_path(char *cmd, char **envp, t_pipex *pipe);
char	**split_string(t_pipex pipe);
int		len_quotes(char *str);
int		check_quotes(char quotes);
void	execute(char *cmd, char **envp);
void	free_string(char **str);
void	error_exit(char *str);

#endif