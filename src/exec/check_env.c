/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 04:01:29 by aelarbid          #+#    #+#             */
/*   Updated: 2023/01/22 17:39:00 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*check_env(char *str, int i, char **envp)
{
	int		j;
	char	*tmp;
	char	**temp;

	j = i;
	if (str[j] == '$')
		j = ++i;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	tmp = ft_strndup(str + j, i - j);
	return (get_env(tmp, i, envp));
}

char	*get_env(char *tmp, int i, char **envp)
{
	int		j;
	char	**temp;

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
			free(tmp);
			tmp = ft_strdup(temp[1]);
			ft_free(temp);
			return (tmp);
		}
	}
	free(tmp);
	return (NULL);
}
