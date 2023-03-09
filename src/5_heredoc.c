/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_heredoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:28:30 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/23 04:45:11 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*open_heredoc(int *fd)
{
	int		i;
	char	*filename;
	char	*tmp;
	char	*tmp2;

	i = 0;
	filename = ft_strdup("/tmp/.temp");
	while (!access(filename, F_OK))
	{
		tmp = filename;
		tmp2 = ft_itoa(i);
		filename = ft_strjoin(tmp, tmp2);
		free(tmp2);
		free(tmp);
		tmp = NULL;
		i++;
	}
	*fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (*fd < 0)
	{
		free(filename);
		return (0);
	}
	return (filename);
}

static void	ft_read(char *line, char *limiter, char **envp, int fd)
{
	while (42)
	{
		line = readline("> ");
		if (!line)
		{
			close(fd);
			exit(0);
		}
		if (!ft_strcmp(line, remove_quotes(limiter), 1))
		{
			free(line);
			close(fd);
			exit(0);
		}
		if (ft_strchr(line, '$') && !ft_strchr(limiter, '\'')
			&& !ft_strchr(limiter, '\"'))
			expand_heredoc(line, fd, envp);
		else
		{
			ft_putendl_fd(line, fd);
			free(line);
		}		
	}
}

int	heredoc_parent(pid_t pid)
{
	waitpid(pid, &g_exit_status, 0);
	g_exit_status = WEXITSTATUS(g_exit_status);
	if (g_exit_status == 130 || g_exit_status == 1)
		return (0);
	return (1);
}

char	*_heredoc(char *limiter, t_data *data)
{
	pid_t	pid;
	int		fd;
	char	*filename;

	if (!limiter || (limiter
			&& (ft_strchr(limiter, '\"') || ft_strchr(limiter, '\''))
			&& (count_quotes(limiter) % 2)))
		return (0);
	filename = open_heredoc(&fd);
	if (!filename)
		return (0);
	pid = fork();
	heredoc_signals();
	if (!pid)
	{
		signal(2, sigdoc_handler);
		ft_read(0, limiter, data->envp, fd);
	}
	else
	{
		if (!heredoc_parent(pid))
			return (ft_free2(filename));
	}
	return (filename);
}
