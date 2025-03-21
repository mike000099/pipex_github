/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseddouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:10:48 by yseddouk          #+#    #+#             */
/*   Updated: 2025/03/21 20:07:20 by yseddouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	execute_command_with_pipes(char *cmd, int pipe_fd[2], int fd_in,
		int fd_out)
{
	char	*args[2];

	args[0] = cmd;
	args[1] = NULL;
	close(pipe_fd[0]);
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_in);
	close(fd_out);
	execve(cmd, args, NULL);
	perror("execve");
	exit(1);
}
