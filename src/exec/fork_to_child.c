/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_to_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 03:28:13 by aelarbid          #+#    #+#             */
/*   Updated: 2023/01/22 22:11:48 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_part(t_cmdline *cmd, t_data *data)
{
	char	*path;
	int		err;

	if (cmd->is_builtin == 1)
	{
		exec_builtin(cmd, data);
	}
	else if (cmd->cmd_args)
	{
		path = path_finder(cmd, data);
		err = execve(path, cmd->cmd_args, data->envp);
		if (err < 0)
		{
			exec_err(cmd->cmd_args[0], strerror(errno));
			if (access(cmd->cmd_args[0], X_OK))
				exit(126);
			exit(127);
		}
	}
}

void	first_cmd(t_cmdline *cmd, t_data *data, int fd[2][2])
{
	int	i;

	i = 0;
	data->fds = open_file(cmd->files);
	if (data->fds && data->fds->fdout != 1)
	{
		close(fd[i % 2][1]);
		fd[i % 2][1] = data->fds->fdout;
	}
	if (data->fds && data->fds->fdin != 0)
	{
		close(fd[i % 2][0]);
		fd[i % 2][0] = data->fds->fdin;
		dup2(fd[i % 2][0], 0);
		close(fd[i % 2][0]);
	}
	dup_core1(fd[i % 2]);
}

void	last_cmd(t_cmdline *cmd, t_data *data, int fd[2][2], int i)
{
	data->fds = open_file(cmd->files);
	if (data->fds && data->fds->fdin != 0)
	{
		close(fd[(i + 1) % 2][0]);
		fd[(i + 1) % 2][0] = data->fds->fdin;
	}
	if (data->fds && data->fds->fdout != 1)
	{
		close(fd[(i + 1) % 2][1]);
		fd[(i + 1) % 2][1] = data->fds->fdout;
		dup2(fd[(i + 1) % 2][1], 1);
		close(fd[(i + 1) % 2][1]);
	}
	dup_core2(fd[(i + 1) % 2]);
}

void	midle_cmd(t_cmdline *cmd, t_data *data, int fd[2][2], int i)
{
	data->fds = open_file(cmd->files);
	if (data->fds && data->fds->fdin != 0)
	{
		close(fd[(i + 1) % 2][0]);
		fd[(i + 1) % 2][0] = data->fds->fdin;
	}
	if (data->fds && data->fds->fdout != 1)
	{
		close(fd[i % 2][1]);
		fd[i % 2][1] = data->fds->fdout;
	}
	dup_core2(fd[(i + 1) % 2]);
	dup_core1(fd[i % 2]);
}

void	child_fork(t_cmdline *cmd, t_data *data, int fd[2][2], int i[2])
{
	int	pid;

	pid = fork();
	if (!data->fds)
		return ;
	if (pid == 0)
	{
		if (i[0] == 0)
			first_cmd(cmd, data, fd);
		else if (i[0] == i[1] - 1)
			last_cmd(cmd, data, fd, i[0]);
		else
			midle_cmd(cmd, data, fd, i[0]);
		exec_part(cmd, data);
	}
}
