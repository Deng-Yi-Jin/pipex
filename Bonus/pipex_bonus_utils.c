/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:23:55 by djin              #+#    #+#             */
/*   Updated: 2023/08/31 08:24:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"

/*
Child Process: calls the process to write or read
dup2: Use to duplicate file descripter.
*/
void	child_process(t_pipex pipe, char *argv, char **envp)
{
	close(pipe.fd[0]);
	printf("hi %d\n", pipe.fd[1]);
	dup2(pipe.fd[1], STDOUT_FILENO);
	printf("bye\n");
	exec(argv, envp);
	printf("execute failed\n");
}

/*
Parent Process: Process is passed in by child process to execute onwards
				at the end of the process
waitpid: Allows you to pause the parent process and wait for the child to
			run finish the process
*/
void	parent_process(t_pipex pipe, char *argv, char **envp)
{
	printf("waitin for child\n");
	waitpid(pipe.pid, NULL, 0);
	printf("chidl done\n");
	close(pipe.fd[1]);
	dup2(pipe.fd[0], STDIN_FILENO);
}

/*checks for quotes or space
  if checker finds ' ' or '\t return 0
  else if checker finds '\'' or '\"" return (1)
*/
int	checker(char c)
{
	if (c == ' ' || c == '\t')
		return (0);
	if (c == '\'' || c == '\"')
		return (1);
	return (2);
}

void	error_exit(char *str)
{
	perror(str);
	exit(1);
}

//free string
void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
