/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:26:33 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/22 13:51:00 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cleanup(int i, int j, t_data *data)
{
	if (i && data->token_lst)
	{
		ft_lstclear(&data->token_lst);
		data->token_lst = NULL;
	}
	if (j && data->cmd_lst)
	{
		ft_lstclear2(&data->cmd_lst);
		data->cmd_lst = NULL;
	}
}

void	free_data(t_data *data)
{
	if (data->envp)
		ft_free(data->envp);
	if (data->line)
		ft_free2(data->line);
	free(data);
}

int	print_error(char *msg, char **content, int stat)
{
	if (content)
	{
		ft_putstr_fd(msg, 2);
		ft_putstr_fd(content[0], 2);
		ft_putendl_fd(content[1], 2);
		g_exit_status = stat;
		ft_free(content);
	}
	else
	{
		ft_putendl_fd(msg, 2);
		g_exit_status = stat;
	}
	return (0);
}
