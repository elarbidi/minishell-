/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_tokenizer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:49:11 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/23 02:54:47 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*check_quotes(char *line, int *i, char c)
{
	int		j;

	*i += 1;
	j = *i;
	while (line[*i] && line[*i] != c)
		*i += 1;
	if (!line[*i])
	{
		print_error("minishell: unpaired quotes", 0, 258);
		return (0);
	}
	return (ft_strndup(line + j, *i - j));
}

int	quotes_conditin(t_data *data, int i)
{
	return (((i && data->line[i - 1] != '\\') || !i)
		&& (data->line[i] == '\"' || data->line[i] == '\''));
}

int	redir_conditin(t_data *data, int i)
{
	return (((i && data->line[i - 1] != '\\') || !i)
		&& (data->line[i] == '>' || data->line[i] == '<'));
}

int	pipe_conditin(t_data *data, int i)
{
	return (((i && data->line[i - 1] != '\\') || !i)
		&& data->line[i] == '|');
}
