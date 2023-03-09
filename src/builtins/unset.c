/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 02:59:36 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/23 04:55:03 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**new_envp(char	**old_env, int idx)
{
	char	**new_env;
	int		i;
	int		j;

	new_env = malloc(sizeof(char *) * ft_strslen(old_env));
	i = 0;
	j = 0;
	while (old_env[i])
	{
		if (i != idx)
		{
			new_env[j] = ft_strdup(old_env[i]);
			j++;
		}
		i++;
	}
	new_env[j] = NULL;
	return (new_env);
}

int	check_varname(char *content, char *var_name)
{
	int	i;

	i = 0;
	while (var_name[i] && (ft_isalpha(var_name[i]) || (var_name[i] == '_'
				|| var_name[i] == '\\' || (i && ft_isdigit(var_name[i])))))
		i++;
	if (!ft_isalpha(var_name[i]) && var_name[i])
	{
		if (var_name[0] == '-')
			print_error("minishell: export: invalid option", 0, 2);
		else
			print_error("minishell: export: ",
				ft_strsjoin(ft_split(content, ' '),
					ft_split(": not a valid identifier", '0')), 1);
		return (0);
	}
	return (1);
}

int	get_index(char **envp, char *var_name)
{
	char	**tmp;
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], var_name, ft_strlen(var_name)))
		{
			tmp = ft_split(envp[i], '=');
			if (!ft_strcmp(tmp[0], var_name, 0))
			{
				ft_free(tmp);
				return (i);
			}
			ft_free(tmp);
		}
	}
	return (-1);
}

void	unset(char	**var_name, t_data *data)
{
	char	**tmp;
	int		idx;
	int		i;

	i = -1;
	g_exit_status = 0;
	while (var_name[++i])
	{
		if (!check_varname(var_name[i], var_name[i]))
			continue ;
		idx = get_index(data->envp, var_name[i]);
		if (idx < 0)
			return ;
		tmp = data->envp;
		data->envp = new_envp(tmp, idx);
		ft_free(tmp);
	}
}
