/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_signal_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:51:05 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/23 03:23:53 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redisplay(int signum)
{
	if (signum == 2)
	{
		ft_putendl_fd("", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (signum == 3)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	sig_handler(int signum)
{
	pid_t	pid;

	pid = waitpid(-1, NULL, WNOHANG);
	if (pid < 0)
		ft_redisplay(signum);
	else
	{
		if (signum == 2)
			ft_putendl_fd("", 1);
		else if (signum == 3)
		{
			ft_putstr_fd("Quit: ", 1);
			ft_putnbr_fd(signum, 1);
			ft_putendl_fd("", 1);
			g_exit_status = 128 + signum;
		}
	}
	g_exit_status = 128 + signum;
}

void	sigdoc_handler(int signum)
{
	ft_putendl_fd("", 1);
	exit(128 + signum);
}

void	heredoc_signals(void)
{
	signal(3, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}

void	main_signals(void)
{
	signal(2, sig_handler);
	signal(3, sig_handler);
	signal(SIGTSTP, SIG_IGN);
}
