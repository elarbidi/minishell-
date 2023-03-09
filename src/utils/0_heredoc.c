/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_heredoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:29:03 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/23 04:44:51 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_quotes(char *limiter)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (limiter[++i])
	{
		if (limiter[i] == '\'' || limiter[i] == '\"')
			count++;
	}
	return (count);
}

char	*remove_quotes(char *limiter)
{
	char	*tmp;
	char	*ret;
	int		i;

	ret = NULL;
	i = -1;
	while (limiter[++i])
	{
		if (limiter[i] != '\'' && limiter[i] != '\"')
		{
			tmp = ret;
			ret = ft_chrjoin(tmp, limiter[i]);
			if (tmp)
				free(tmp);
		}
	}
	return (ret);
}

void	expand_heredoc(char *line, int fd, char	**envp)
{
	char	*tmp;

	while (ft_strchr(line, '$'))
	{
		tmp = line;
		line = expand_dollar(tmp, envp);
		free(tmp);
	}
	ft_putendl_fd(line, fd);
	free(line);
}
