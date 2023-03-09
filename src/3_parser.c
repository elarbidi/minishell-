/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:28:37 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/23 04:13:17 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid(int type1, int type2)
{
	return ((type1 == word || type1 == dquotes || type1 == squotes)
		&& type2 != pip);
}

void	parser(t_data *data)
{
	t_lexer	*new;
	t_lexer	*current;
	t_lexer	*tmp;
	char	*temp;

	new = NULL;
	tmp = data->token_lst->next;
	current = ft_lstadd_back(&new, token_init(data->token_lst->index,
				ft_strdup(data->token_lst->content), data->token_lst->type));
	while (tmp)
	{
		if (!ft_isspace(data->line[tmp->index - 1])
			&& is_valid(tmp->type, current->type))
		{
			temp = current->content;
			current->content = ft_strjoin(temp, tmp->content);
			free(temp);
		}
		else
			current = ft_lstadd_back(&new,
					token_init(tmp->index, ft_strdup(tmp->content), tmp->type));
		tmp = tmp->next;
	}
	data->token_lst = new;
}
