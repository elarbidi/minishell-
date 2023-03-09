/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_cmdline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:14:31 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/23 03:23:20 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// tested normed

int	is_builtin(char	*cmd)
{
	return (!ft_strcmp(cmd, "echo", 0) || !ft_strcmp(cmd, "unset", 0)
		|| !ft_strcmp(cmd, "export", 0) || !ft_strcmp(cmd, "cd", 0)
		|| !ft_strcmp(cmd, "pwd", 0) || !ft_strcmp(cmd, "env", 0)
		|| !ft_strcmp(cmd, "exit", 0) || !ft_strcmp(cmd, "history", 0));
}

int	is_redir(int type)
{
	return (type == append || type == redirIn
		|| type == redirOut || type == heredoc);
}

void	add_redir(char *content, int type, t_cmdline *cmdline, t_data *data)
{
	t_files	*tmp;

	tmp = ft_lstlast3(cmdline->files);
	if (type == heredoc
		&& ((tmp && tmp->type == heredoc && g_exit_status != 130) || !tmp))
	{
		ft_lstadd_back3(&cmdline->files,
			create_node2(_heredoc(content, data), type));
	}
	else if (type == heredoc)
	{
		ft_lstadd_back3(&cmdline->files,
			create_node2(ft_strdup("error"), type));
	}
	else
		ft_lstadd_back3(&cmdline->files,
			create_node2(ft_strdup(content), type));
}

void	make_cmd(t_data *data)
{
	t_lexer		*head;
	t_cmdline	*current;

	current = ft_lstadd_back2(&data->cmd_lst, create_node());
	head = data->token_lst;
	while (head)
	{
		if (is_redir(head->type))
			add_redir(head->content, head->type, current, data);
		else if (head->type == pip)
		{
			if (!add_pipe(&current, head, data))
				break ;
		}
		else
		{
			if (!check_syntax_err(head->type, current, head, data))
				break ;
			current->cmd_args = ft_strsjoin(current->cmd_args,
					ft_split(head->content, 0));
		}
		if (current->cmd_args && current->cmd_args[0])
			current->is_builtin = is_builtin(current->cmd_args[0]);
		head = head->next;
	}
}
