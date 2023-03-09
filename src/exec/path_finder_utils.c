/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:43:58 by aelarbid          #+#    #+#             */
/*   Updated: 2023/01/23 00:44:48 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_env(t_data *data)
{
	int		i;
	char	**tmp;
	char	*res;

	i = 0;
	while (data->envp[i])
	{
		tmp = ft_split(data->envp[i], '=');
		if (!ft_strcmp("PATH", tmp[0], 0))
		{
			res = ft_strdup(tmp[1]);
			ft_free(tmp);
			return (res);
		}
		ft_free(tmp);
		i++;
	}
	return (NULL);
}

void	dot(t_cmdline *cmd)
{
	if (cmd->cmd_args && cmd->cmd_args[0]
		&& cmd->cmd_args[0][0] == '.' && cmd->cmd_args[0][1] == '\0')
	{
		exec_err(cmd->cmd_args[0], ":filename argument required\n");
		exit(2);
	}
}

int	isdir(char *name)
{
	struct stat	statbuf;

	if (stat(name, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}

int	file_exists(const char *filename)
{
	struct stat	buffer;

	if (stat(filename, &buffer) == 0)
		return (1);
	return (0);
}

void	dir(char *s)
{
	if (!ft_strchr(s, '/'))
		return ;
	if (isdir(s))
	{
		exec_err(s, " :is a Derictory\n");
		exit(126);
	}
	else if (!file_exists(s))
	{
		exec_err(s, " :No such file or directory\n");
		exit(127);
	}
	else if (access(s, X_OK))
	{
		exec_err(s, " : Permission denied\n");
		exit(126);
	}
}
