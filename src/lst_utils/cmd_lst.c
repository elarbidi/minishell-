/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:50:26 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/21 11:25:11 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmdline	*create_node(void)
{
	t_cmdline	*node;

	node = malloc(sizeof(t_cmdline));
	if (!node)
		return (0);
	node->next = NULL;
	node->cmd_args = NULL;
	node->files = NULL;
	return (node);
}

t_cmdline	*ft_lstlast2(t_cmdline *lst)
{
	t_cmdline	*tmp;

	if (lst == NULL)
		return (lst);
	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

t_cmdline	*ft_lstadd_back2(t_cmdline **alst, t_cmdline *new)
{
	t_cmdline	*tmp;

	if (!new)
		return (0);
	if (!(*alst))
	{
		new->next = (*alst);
		(*alst) = new;
	}
	else
	{
		tmp = ft_lstlast2(*alst);
		tmp->next = new;
	}
	return (new);
}

void	ft_lstclear2(t_cmdline **lst)
{
	t_cmdline	*tmp;
	t_cmdline	*current;

	tmp = (*lst);
	while (tmp != NULL)
	{
		if (tmp->files)
		{
			ft_lstclear3(&tmp->files);
			tmp->files = NULL;
		}
		current = tmp;
		tmp = tmp->next ;
		if (current->cmd_args)
			ft_free(current->cmd_args);
		free(current);
		current = NULL;
	}
	*lst = NULL;
}
