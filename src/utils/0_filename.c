/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_filename.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 03:56:47 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/23 04:46:59 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*function(char *str, char **envp)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (ft_strchr(str + i, '$'))
	{
		j = ft_strchr(str, '$') - str;
		if ((!ft_isalnum(str[j + 1]) && str[j + 1] != '?'
				&& str[j + 1] != '$') || (j && str[j - 1] == '\\'))
		{
			i++;
			continue ;
		}
		tmp = str;
		str = expand_dollar(tmp, envp);
		if (tmp)
			ft_free2(tmp);
	}
	return (str);
}

int	another_function(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && !ft_isspace(str[i]))
		i++;
	if (str[i])
		return (0);
	return (1);
}

char	*remove_quote(int *i, char *line, char **ret, char **envp)
{
	char	*tmp;

	if (line[*i] == '\"')
	{
		tmp = check_quotes(line, i, line[*i]);
		if (!tmp)
			return (ft_free2(*ret));
		*i = *i + 1;
		tmp = function(tmp, envp);
		mini_join(ret, tmp);
	}
	else if (line[*i] == '\'')
	{
		tmp = check_quotes(line, i, line[*i]);
		if (!tmp)
			return (ft_free2(*ret));
		*i = *i + 1;
		mini_join(ret, tmp);
	}
	return (*ret);
}

char	*expand_filename(int *i, char*line, char **ret, char **envp)
{
	int		j;
	char	*tmp1;

	j = *i;
	while (line[*i] && !ft_strchr("|<>", line[*i]) && !ft_isspace(line[*i]))
		*i = *i + 1;
	tmp1 = ft_strndup(line + j, *i - 1);
	tmp1 = function(tmp1, envp);
	if (!tmp1 || !another_function(tmp1))
		return (ft_free2(*ret));
	mini_join(ret, tmp1);
	return (*ret);
}

int	check_filename(char *line, int *i, int type)
{
	*i += 1;
	if (type == append || type == heredoc)
		*i += 1;
	while (line[*i] && ft_isspace(line[*i]))
		*i += 1;
	if (!line[*i])
	{
		print_error("minishell: syntax error near unexpected token", 0, 258);
		return (0);
	}
	return (1);
}
