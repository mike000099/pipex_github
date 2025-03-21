/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseddouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:52:22 by yseddouk          #+#    #+#             */
/*   Updated: 2025/03/21 22:36:17 by yseddouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// pipex.c
void	pipex(int infile, int outfile, char **argv, char **envp);
void	execute_first_child(int *pipefd, int infile, char *cmd, char **envp);
void	execute_second_child(int *pipefd, int outfile, char *cmd, char **envp);

// commmands.

char	*get_command_path(char *cmd, char **envp);
void	execute_command(char *cmd, char **envp);
void	print_command_not_found(char *cmd);
// file_utils.c

int		handle_infile(char *infile, int pipe_fd[2], char *cmd, char **envp);
int		handle_outfile(char *outfile, int pipe_fd[2], char *cmd, char **envp);

// utils.c

char	*get_env_var(char *var, char **envp);
char	*ft_strjoin_three(char *s1, char *s2, char *s3);
void	free_args(char **args);

// processes.c
void	run_pipex(int infile, int outfile, char *argv[], char **envp);
void	execute_command_with_pipes(char *cmd, int pipe_fd[2], int fd_in,
			int fd_out);

#endif
