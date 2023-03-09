/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_filename.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 05:46:16 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/23 03:25:28 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_free2(char *str)
{
	if (!str)
		return (str);
	free(str);
	str = NULL;
	return (str);
}

void	mini_join(char **str1, char *str2)
{
	char	*tmp;

	tmp = *str1;
	*str1 = ft_strjoin(tmp, str2);
	ft_free2(tmp);
}

void	mini_join2(char *line, int *i, char **ret)
{
	char	*tmp;

	tmp = *ret;
	*ret = ft_chrjoin(tmp, line[*i]);
	ft_free2(tmp);
	if (line[*i] && !ft_strchr("|<>", line[*i]))
		*i = *i + 1;
}

char	*get_filename(char *line, int *i, int type, char **envp)
{
	char	*ret;

	if (!check_filename(line, i, type))
		return (0);
	ret = 0;
	while (line[*i])
	{
		if ((line[*i] == '\"' || line[*i] == '\'') && type != heredoc)
		{
			if (!remove_quote(i, line, &ret, envp))
				return (0);
		}
		else if (line[*i] == '$' && type != heredoc)
		{
			if (!expand_filename(i, line, &ret, envp))
				return (0);
		}
		else
			mini_join2(line, i, &ret);
		if (ft_strchr("|<>", line[*i]) || ft_isspace(line[*i]))
			break ;
	}
	return (ret);
}
