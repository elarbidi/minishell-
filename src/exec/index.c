/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:00:33 by aelarbid          #+#    #+#             */
/*   Updated: 2023/01/23 00:38:31 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exit_status(void)
{
	if (WIFSIGNALED(g_exit_status))
	{
		g_exit_status = 128 + WTERMSIG(g_exit_status);
	}
	else
		g_exit_status = WEXITSTATUS(g_exit_status);
}

void	if_one_cmd(t_cmdline *cmd, t_data *data)
{
	if (cmd->cmd_args && cmd->cmd_args[0]
		&& !ft_strcmp("exit", cmd->cmd_args[0], 0))
		ft_exit(cmd->cmd_args + 1);
	else if (cmd->cmd_args && cmd->cmd_args[0]
		&& !ft_strcmp("export", cmd->cmd_args[0], 0))
		export(cmd->cmd_args + 1, data);
	else if (cmd->cmd_args && cmd->cmd_args[0]
		&& !ft_strcmp("cd", cmd->cmd_args[0], 0))
		ft_cd(cmd->cmd_args + 1, data);
	else if (cmd->cmd_args && cmd->cmd_args[0]
		&& !ft_strcmp("unset", cmd->cmd_args[0], 0))
		unset(cmd->cmd_args + 1, data);
	else
		exec_one_cmd(cmd, data);
}

void	if_more_cmd(t_cmdline *tmp, t_data *data, int n)
{
	int	fd[2][2];
	int	i[2];
	int	wpid;

	i[0] = 0;
	i[1] = n;
	while (i[0] < i[1])
	{
		pipe(fd[i[0] % 2]);
		child_fork(tmp, data, fd, i);
		if (i[0] != 0)
		{
			final_close(fd[(i[0] + 1) % 2]);
		}
		tmp = tmp->next;
		i[0]++;
	}
	wpid = waitpid(-1, &g_exit_status, 0);
	while (wpid > 0)
		wpid = waitpid(-1, &g_exit_status, 0);
	exit_status();
}

void	exe_main(t_cmdline *cmd, t_data *data)
{
	t_cmdline	*tmp;
	int			n;
	int			i;

	tmp = cmd;
	n = node_len(cmd);
	i = 0;
	if (n == 1)
		if_one_cmd(cmd, data);
	else
		if_more_cmd(tmp, data, n);
}
