/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 03:31:33 by aelarbid          #+#    #+#             */
/*   Updated: 2023/01/21 07:47:09 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*path_join(char *s1, char *s2)
{
	char	*res;
	char	*tmp;

	tmp = ft_strjoin(s1, "/");
	free(s1);
	res = ft_strjoin(tmp, s2);
	free(tmp);
	free(s2);
	return (res);
}
