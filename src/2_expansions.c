/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_expansions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:50:53 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/23 03:47:22 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_env(char *str, int i, char **envp)
{
	int		j;
	char	*tmp;
	char	**temp;

	tmp = get_varname(str, i);
	j = -1;
	while (envp[++j])
	{
		if (ft_strnstr(envp[j], tmp, ft_strlen(tmp)))
		{
			temp = ft_split(envp[j], '=');
			if (ft_strcmp(temp[0], tmp, 0))
			{
				ft_free(temp);
				continue ;
			}
			ft_free2(tmp);
			tmp = ft_strdup(temp[1]);
			ft_free(temp);
			return (tmp);
		}
	}
	ft_free2(tmp);
	return (NULL);
}

char	*expand_dollar(char *str, char **envp)
{
	char	*ret;
	int		i;

	i = ft_strchr(str, '$') - str;
	ret = NULL;
	if (i && str[i - 1] == '\\')
	{
		if (ft_strchr(str + i + 1, '$'))
			i = ft_strchr(str + i + 1, '$') - str;
		else
			return (ft_strdup(str));
	}
	if (str && str[i + 1] == '?')
		ret = ft_itoa(g_exit_status);
	else if (str && ft_isdigit(str[i + 1]))
		return (ft_strdup(str + 2));
	else if (str && str[i + 1] && str[i + 1] != '\"' && str[i + 1] != '\'')
		ret = check_env(str, i, envp);
	mini_join3(&ret, i, str);
	return (ret);
}

void	helper_func(t_lexer *head, int *i, char **envp)
{
	char	*tmp;
	int		j;

	j = (ft_strchr(head->content + *i, '$') - head->content);
	if ((!ft_isalnum(head->content[j + 1])
			&& ((head->content[j + 1] != '?'
					&& head->content[j + 1] != '$') || !head->content[j + 1]))
		|| (j > 0 && head->content[j - 1] == '\\'))
	{
		*i = *i + 1;
		return ;
	}
	if (!head->content[*i])
		return ;
	tmp = head->content;
	head->content = expand_dollar(tmp, envp);
	free(tmp);
	tmp = NULL;
}

int	expansion(t_data *data)
{
	t_lexer	*head;
	int		i;

	head = data->token_lst;
	while (head)
	{
		i = 0;
		while ((head->type == word || head->type == dquotes)
			&& ft_strchr(head->content + i, '$'))
			helper_func(head, &i, data->envp);
		head = head->next;
	}
	return (0);
}
