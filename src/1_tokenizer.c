/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_tokenizer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 01:14:18 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/23 02:55:48 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_redir(t_data *data, int *i, int j, int len)
{
	if (data->line[*i] == '>')
	{
		if (*i + 1 < len && data->line[*i + 1] == '>')
			ft_lstadd_back(&data->token_lst, token_init(j,
					get_filename(data->line, i, append, data->envp), append));
		else
			ft_lstadd_back(&data->token_lst, token_init(j,
					get_filename(data->line, i, redirOut, data->envp), 3));
	}
	else if (data->line[*i] == '<')
	{
		if (*i + 1 < len && data->line[*i + 1] == '<')
			ft_lstadd_back(&data->token_lst, token_init(j,
					get_filename(data->line, i, heredoc, data->envp), heredoc));
		else
			ft_lstadd_back(&data->token_lst, token_init(j,
					get_filename(data->line, i, redirIn, data->envp), redirIn));
	}
}

int	init_quotes(t_data *data, int *i, int j)
{
	t_lexer	*current;

	current = NULL;
	if (data->line[*i] == '\"')
		current = ft_lstadd_back(&data->token_lst, token_init(j,
					check_quotes(data->line, i, data->line[*i]), dquotes));
	else if (data->line[*i] == '\'')
		current = ft_lstadd_back(&data->token_lst, token_init(j,
					check_quotes(data->line, i, data->line[*i]), squotes));
	if (data->line[*i])
		*i = *i + 1;
	if (!current->content)
		return (0);
	return (1);
}

void	init_word(t_data *data, int *i, int j)
{
	while (data->line[*i] && data->line[*i] != ' '
		&& (!ft_strchr("|<>\"\'", data->line[*i])
			|| (*i && data->line[*i - 1] == '\\')))
		*i = *i + 1;
	ft_lstadd_back(&data->token_lst, token_init(j,
			ft_strndup(data->line + j, *i - j), word));
}

void	init_pipe(int j, int *i, t_data *data)
{
	ft_lstadd_back(&data->token_lst, token_init(j,
			ft_strndup(data->line + j, 1), pip));
	*i = *i + 1;
}

void	lexer(t_data *data, int len, int j)
{
	int		i;

	i = 0;
	while (data->line[i])
	{
		j = i;
		if (ft_isspace(data->line[i]))
			i++;
		else if (redir_conditin(data, i))
			init_redir(data, &i, j, len);
		else if (quotes_conditin(data, i))
		{
			if (!init_quotes(data, &i, j))
			{
				ft_lstclear(&data->token_lst);
				return ;
			}
		}
		else if (pipe_conditin(data, i))
			init_pipe(j, &i, data);
		else
			init_word(data, &i, j);
		if (!data->line[i])
			break ;
	}
}
