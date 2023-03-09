/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_cmdline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 06:04:25 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/23 04:46:59 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	add_pipe(t_cmdline **current, t_lexer *head, t_data *data)
{
	if (!check_syntax_err(head->type, *current, head, data))
		return (0);
	*current = ft_lstadd_back2(&data->cmd_lst, create_node());
	return (1);
}

int	check_syntax_err(int type, t_cmdline *node1, t_lexer *node2, t_data *data)
{
	if (type == pip && ((!node1->cmd_args && !node1->files) || !node2->next))
	{
		print_error("minishell: syntax error near unexpected token `|'", 0, 1);
		cleanup(1, 1, data);
		return (0);
	}
	if (!node2->content && (type == dquotes || type == squotes))
	{
		cleanup(1, 1, data);
		return (0);
	}
	return (1);
}

char	*ft_isspace2(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && !ft_isspace(str[i]))
		i++;
	if (str && str[i])
		return (ft_strndup(str, i));
	return (0);
}

void	check_cmd(t_data *data)
{
	char		*tmp;
	char		**tmp2;
	t_cmdline	*current;

	current = data->cmd_lst;
	while (current)
	{
		if (current->cmd_args)
			tmp = ft_isspace2(current->cmd_args[0]);
		if (tmp && current->cmd_args)
		{
			tmp2 = ft_strsjoin(ft_split(tmp, 0), ft_split(
						ft_strdup(current->cmd_args[0] + ft_strlen(tmp) + 1),
						0));
			current->cmd_args = ft_strsjoin(tmp2, current->cmd_args + 1);
		}
		current = current->next;
	}
}
