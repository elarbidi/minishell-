/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 06:28:01 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/22 08:36:23 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update_path(char *var_name, char *content, t_data *data, int i)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_chrjoin(var_name, '=');
	tmp2 = tmp;
	tmp = ft_strjoin(tmp2, content);
	free(tmp2);
	free(data->envp[i]);
	data->envp[i] = tmp;
}

void	update_var(char *var_name, char *content, t_data *data, int i)
{
	char	*tmp;
	char	*tmp2;
	int		len;

	len = ft_strlen(var_name) + 2;
	tmp = ft_strndup(content + len, ft_strlen(content) - len);
	tmp2 = data->envp[i];
	data->envp[i] = ft_strjoin(tmp2, tmp);
	free(tmp2);
	free(tmp);
}

void	update_var2(char *content, t_data *data, int i)
{
	char	**tmp;
	char	*tmp2;

	if (!data->envp[i])
	{
		tmp = data->envp;
		data->envp = ft_strsjoin(tmp, ft_split(content, 0));
	}
	else
	{
		tmp2 = data->envp[i];
		data->envp[i] = ft_strdup(content);
		free(tmp2);
	}
}
