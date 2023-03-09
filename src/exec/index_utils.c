/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:38:36 by aelarbid          #+#    #+#             */
/*   Updated: 2023/01/23 04:46:59 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	rederction(t_cmdline *cmd, t_data *data)
{
	data->fds = open_file(cmd->files);
	if (!data->fds)
		exit(1);
	if (data->fds->fdin != 0)
	{
		dup2(data->fds->fdin, 0);
		close(data->fds->fdin);
	}
	if (data->fds->fdout != 1)
	{
		dup2(data->fds->fdout, 1);
		close(data->fds->fdout);
	}
}

void	exect(t_cmdline *cmd, t_data *data)
{
	char	*path;

	if (cmd->is_builtin == 1)
	{
		exec_builtin(cmd, data);
	}
	else if (cmd->cmd_args)
	{
		path = path_finder(cmd, data);
		if (execve(path, cmd->cmd_args, data->envp) < 0)
		{
			perror("minishell");
		}
	}
}

void	exec_one_cmd(t_cmdline *cmd, t_data *data)
{
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		rederction(cmd, data);
		if (!cmd->cmd_args)
		{
			if (cmd->files->type == heredoc && g_exit_status == 0)
				exit(0);
			exit(1);
		}
		exect(cmd, data);
		if (access(cmd->cmd_args[0], X_OK))
			exit(126);
		exit(127);
	}
	wait(&g_exit_status);
	exit_status();
}
