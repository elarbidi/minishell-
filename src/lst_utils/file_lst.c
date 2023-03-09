/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:02:23 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/21 09:16:32 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_files	*create_node2(char *filename, int type)
{
	t_files	*node;

	node = malloc(sizeof(t_files));
	if (!node)
		return (0);
	node->next = NULL;
	if (!filename)
		node->filename = ft_strdup("error");
	else
		node->filename = filename;
	node->type = type;
	return (node);
}

t_files	*ft_lstlast3(t_files *lst)
{
	t_files	*tmp;

	if (lst == NULL)
		return (lst);
	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_back3(t_files **alst, t_files *new)
{
	t_files	*tmp;

	if (!new)
		return ;
	if (!(*alst))
	{
		new->next = (*alst);
		(*alst) = new;
	}
	else
	{
		tmp = ft_lstlast3(*alst);
		tmp->next = new;
	}
}

void	ft_lstclear3(t_files **lst)
{
	t_files	*tmp;
	t_files	*current;

	tmp = (*lst);
	while (tmp != NULL)
	{
		current = tmp;
		tmp = tmp->next ;
		if (current->filename)
			free(current->filename);
		free(current);
		current = NULL;
	}
	*lst = NULL;
}
