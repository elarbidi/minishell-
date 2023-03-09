/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:50:38 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/22 13:38:47 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstdelone(t_lexer *node)
{
	free(node->content);
	free(node);
	node = NULL;
}

t_lexer	*ft_lstlast(t_lexer *lst)
{
	t_lexer	*tmp;

	if (lst == NULL)
		return (lst);
	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

t_lexer	*ft_lstadd_back(t_lexer **alst, t_lexer *new)
{
	t_lexer	*tmp;

	if (!new)
		return (0);
	if ((*alst) == NULL)
	{
		new->next = (*alst);
		(*alst) = new;
	}
	else
	{
		tmp = ft_lstlast(*alst);
		tmp->next = new;
	}
	return (new);
}

void	ft_lstclear(t_lexer **lst)
{
	t_lexer	*tmp;
	t_lexer	*current;

	tmp = (*lst);
	while (tmp != NULL)
	{
		current = tmp;
		tmp = tmp->next ;
		free(current->content);
		free(current);
		current = NULL;
	}
	*lst = NULL;
}

t_lexer	*token_init(int i, char *ctn, int type)
{
	t_lexer	*node;

	node = malloc(sizeof(t_lexer));
	node->content = ctn;
	node->index = i;
	node->type = type;
	node->next = NULL;
	return (node);
}
