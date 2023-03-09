/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_expansion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 05:57:19 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/21 08:38:28 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_join(char *str, char *str2, int i, int j)
{
	char	*tmp;
	char	*temp;
	char	*ret;

	if (!str2 && !i && (size_t)j == ft_strlen(str))
		return (str2);
	if (!str)
		return (ft_strdup(str2));
	if (str2)
	{
		tmp = ft_strndup(str, i);
		ret = ft_strjoin(tmp, str2);
		free(tmp);
	}
	else
		ret = ft_strndup(str, i);
	if (str[j - 1] == '$')
		j++;
	temp = ret;
	ret = ft_strjoin(temp, str + j);
	free(temp);
	if (str2)
		free(str2);
	return (ret);
}

char	*get_varname(char *str, int i)
{
	int		j;

	j = i;
	if (str[j] == '$')
		j = ++i;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	return (ft_strndup(str + j, i - j));
}

void	mini_join3(char **ret, int i, char *str)
{
	int	j;

	if ((i > 0 || (size_t)i < ft_strlen(str)) && str)
	{
		j = i + 1;
		while (str[j] && (ft_isalnum(str[j]) || str[j] == '_'))
			j++;
		*ret = ft_join(str, *ret, i, j);
	}
}
