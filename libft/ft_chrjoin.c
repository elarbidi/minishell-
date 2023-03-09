/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:25:14 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/21 07:07:48 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chrjoin(char *s, char c)
{
	char	*ret;
	int		i;

	ret = malloc(ft_strlen(s) + 2);
	if (ret && ((s && !s[0]) || !s))
	{
		ret[0] = c;
		ret[1] = '\0';
		return (ret);
	}
	i = -1;
	while (ret && s && s[++i])
	{
		ret[i] = s[i];
		if (!s[i + 1])
		{
			ret[i + 1] = c;
			ret[i + 2] = '\0';
			return (ret);
		}
	}
	if (ret)
		free(ret);
	return (NULL);
}
