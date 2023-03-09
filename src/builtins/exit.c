/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 02:59:09 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/23 04:46:59 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	num_error(char	*val)
{
	print_error("minishell: exit: ", ft_strsjoin(ft_split(val, ' '),
			ft_split(": numeric argument required", '=')), 255);
	exit(g_exit_status);
	ft_putendl_fd("exit", 2);
}

void	print_exit(int stat)
{
	g_exit_status = stat;
	ft_putendl_fd("exit", 1);
	exit(g_exit_status);
}

void	ft_exit(char **args)
{
	int	exit_code;
	int	i;

	if (!*args)
		print_exit(g_exit_status);
	else
	{
		i = -1;
		if (args[0][0] == '-' || args[0][0] == '+')
			i = 0;
		while (args[0][++i])
		{
			if (!ft_isdigit(args[0][i]))
				num_error(args[0]);
		}
		if (ft_strslen(args) >= 2)
			print_error("exit\ntest: exit: too many arguments", NULL, 1);
		else
		{
			exit_code = ft_atoi(args[0]);
			print_exit(exit_code % 256);
		}
	}
}
