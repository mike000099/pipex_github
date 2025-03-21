/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseddouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:10:55 by yseddouk          #+#    #+#             */
/*   Updated: 2025/03/20 23:56:47 by yseddouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	handle_infile(char *infile, int pipe_fd[2], char *cmd, char **envp)
{
	int	infile_fd;

	(void)envp;
	infile_fd = open(cmd, O_RDONLY);
	if (infile < 0)
	{
		perror("Error opening infile");
		return (-1);
	}
	if (dup2(infile_fd, 0) < 0)
	{
		perror("Error redirectly infile to stdin");
		return (-1);
	}
	if (dup2(pipe_fd[1], 1) < 0)
	{
		perror("Error redirecting pipe");
		return (-1);
	}
	close(infile_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	return (infile_fd);
}

int	handle_outfile(char *outfile, int pipe_fd[2], char *cmd, char **envp)
{
	int	outfile_fd;

	(void)envp;
	(void)cmd;
	outfile_fd = open(outfile, O_RDONLY | O_CREAT | O_TRUNC);
	if (outfile_fd < 0)
	{
		perror("Error opening outfile");
		return (-1);
	}
	if (dup2(outfile_fd, 1) < 0)
	{
		perror("Error redirecting pipe write end to stdout");
		close(outfile_fd);
		return (-1);
	}
	close(outfile_fd);
	if (dup2(pipe_fd[0], 0) < 0)
	{
		perror("Error redirecting pipe write end to stdout");
		return (-1);
	}
	close(pipe_fd[1]);
	return (outfile_fd);
}
