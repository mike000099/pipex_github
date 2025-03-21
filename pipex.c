/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseddouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:19:57 by yseddouk          #+#    #+#             */
/*   Updated: 2025/03/21 22:42:17 by yseddouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	pipex(int infile, int outfile, char **argv, char **envp)
{
	int	pipefd[2];

	if (pipe(pipefd) < 0)
	{
		perror("Pipe error");
		return ;
	}
	execute_first_child(pipefd, infile, argv[2], envp);
	execute_second_child(pipefd, outfile, argv[3], envp);
	close(pipefd[0]);
	close(pipefd[1]);
}

void	execute_first_child(int *pipefd, int infile, char *cmd, char **envp)
{
	pid_t	pid1;

	pid1 = fork();
	if (pid1 < 0)
	{
		perror("Fork error");
		return ;
	}
	if (pid1 == 0)
	{
		close(pipefd[0]);
		dup2(infile, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		execute_command(cmd, envp);
	}
}

void	execute_second_child(int *pipefd, int outfile, char *cmd, char **envp)
{
	pid_t	pid2;

	pid2 = fork();
	if (pid2 < 0)
	{
		perror("Fork error");
		return ;
	}
	if (pid2 == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(pipefd[0]);
		execute_command(cmd, envp);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	int	infile;
	int	outfile;

	if (argc != 5)
	{
		write(2, "Error: check arguments\n", 23);
		exit(1);
	}
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		write(2, "zsh: no such file or directory: infile\n", 39);
		return (1);
	}
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		write(2, "Error opening outfile\n", 22);
		return (1);
	}
	pipex(infile, outfile, argv, envp);
	close(infile);
	close(outfile);
	return (0);
}
