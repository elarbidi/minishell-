/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 02:58:56 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/20 07:55:03 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_option(char	*content, int *n)
{
	int	i;

	i = 0;
	if (content[i] != '-')
		return (0);
	while (content[++i])
	{
		if (content[i] != 'n')
			return (0);
	}
	if (*n == 0)
		*n = 1;
	return (1);
}

void	ft_echo(char **args)
{
	int	i;
	int	n;

	g_exit_status = 0;
	if (!args)
	{
		ft_putendl_fd("", 1);
		return ;
	}
	i = 0;
	n = 0;
	while (args[i] && is_option(args[i], &n))
		i++;
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		i++;
		if (args[i])
			ft_putstr_fd(" ", 1);
	}
	if (!n)
		ft_putendl_fd("", 1);
}
