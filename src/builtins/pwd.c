/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 02:59:30 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/23 04:46:59 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(char **envp)
{
	char	*path;

	g_exit_status = 0;
	path = getcwd(NULL, 0);
	if (!path)
	{
		free(path);
		path = check_env("PWD", 0, envp);
		if (!path)
		{
			print_error("minishell: pwd: getcwd failed", NULL, 1);
			return ;
		}
	}
	ft_putendl_fd(path, 1);
	free(path);
}
