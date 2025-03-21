/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseddouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:11:54 by yseddouk          #+#    #+#             */
/*   Updated: 2025/03/21 22:35:00 by yseddouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*get_command_path(char *cmd, char **envp)
{
	char	*path_env;
	char	**paths;
	char	*full_path;
	int		i;

	path_env = get_env_var("PATH", envp);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin_three(paths[i], "/", cmd);
		if (access(full_path, X_OK) == 0)
		{
			free_args(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_args(paths);
	return (NULL);
}

void	cleanup_and_exit(char *cmd_path, char **args, int exit_code)
{
	if (cmd_path)
		free(cmd_path);
	if (args)
		free_args(args);
	if (exit_code != 0)
		exit(exit_code);
}

void	print_command_not_found(char *cmd)
{
	write(2, "zsh: command not found: ", 23);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
}

void	execute_command(char *cmd, char **envp)
{
	char	**args;
	char	*cmd_path;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		print_command_not_found(cmd);
		return ;
	}
	cmd_path = get_command_path(args[0], envp);
	if (!cmd_path)
	{
		print_command_not_found(args[0]);
		cleanup_and_exit(NULL, args, 1);
		return ;
	}
	if (execve(cmd_path, args, envp) == -1)
	{
		print_command_not_found(args[0]);
		cleanup_and_exit(cmd_path, args, 1);
	}
	cleanup_and_exit(cmd_path, args, 0);
}
