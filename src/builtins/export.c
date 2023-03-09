/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 02:59:17 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/23 04:48:26 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	checkvarname(char *content, char *var_name)
{
	int	i;

	i = 0;
	while (var_name[i] && (ft_isalpha(var_name[i]) || (var_name[i] == '_'
				|| var_name[i] == '\\' || (i && ft_isdigit(var_name[i])))))
		i++;
	if (var_name[i] && (!ft_isalpha(var_name[i])
			|| (var_name[i] == '+' && var_name[i + 1])))
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

static char	*get_varname2(char *content, int *add)
{
	int		i;

	i = 0;
	*add = 0;
	if (content[0] == '=')
	{
		print_error("minishell: export: not a valid identifier", 0, 1);
		return (0);
	}
	while (content[i] && content[i] != '=')
		i++;
	if (!content[i])
		return (ft_strdup(content));
	if (content[i - 1] == '+')
	{
		*add = 1;
		i--;
	}
	return (ft_strndup(content, i));
}

void	add_env(t_data *data, char *content, char *var_name, int add)
{
	int		i;

	i = 0;
	while (data->envp[i]
		&& !ft_strnstr(data->envp[i], var_name, ft_strlen(var_name)))
		i++;
	if (!add)
		update_var2(content, data, i);
	else if (data->envp[i] && add > 0)
		update_var(var_name, content, data, i);
	else if (data->envp[i] && add < 0)
		update_path(var_name, content, data, i);
}

void	sorted_print(char **envp)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	while (envp[++i])
	{
		j = i;
		while (envp[++j])
		{
			if (ft_strcmp(envp[i], envp[j], 0) > 0)
			{
				tmp = envp[i];
				envp[i] = envp[j];
				envp[j] = tmp;
			}
		}
	}
	i = -1;
	while (envp[++i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putendl_fd(envp[i], 1);
	}
	ft_free(envp);
}

void	export(char **content, t_data *data)
{
	char	*var_name;
	int		add;
	int		i;

	g_exit_status = 0;
	if (!*content)
	{
		sorted_print(env_copy(data->envp));
		return ;
	}
	i = -1;
	while (content[++i])
	{
		var_name = get_varname2(content[i], &add);
		if (!var_name)
			continue ;
		if (!checkvarname(content[i], var_name))
		{
			free(var_name);
			return ;
		}
		add_env(data, content[i], var_name, add);
		free(var_name);
	}
}
