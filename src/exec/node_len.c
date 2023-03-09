/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 03:23:10 by aelarbid          #+#    #+#             */
/*   Updated: 2023/01/21 07:47:09 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	node_len(t_cmdline *cmd)
{
	t_cmdline	*tmp;
	int			i;

	tmp = cmd;
	i = 0;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
