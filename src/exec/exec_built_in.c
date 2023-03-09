/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_built_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 03:27:10 by aelarbid          #+#    #+#             */
/*   Updated: 2023/01/22 17:42:04 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_builtin(t_cmdline *cmd, t_data *data)
{
	if (!ft_strcmp("cd", cmd->cmd_args[0], 0))
		ft_cd(cmd->cmd_args + 1, data);
	else if (!ft_strcmp("echo", cmd->cmd_args[0], 0))
		ft_echo(cmd->cmd_args + 1);
	else if (!ft_strcmp("env", cmd->cmd_args[0], 0))
		env(data->envp);
	else if (!ft_strcmp("pwd", cmd->cmd_args[0], 0))
		ft_pwd(data->envp);
	else if (!ft_strcmp("export", cmd->cmd_args[0], 0))
		export(cmd->cmd_args + 1, data);
	exit(g_exit_status);
}
