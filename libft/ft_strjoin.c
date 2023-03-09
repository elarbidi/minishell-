/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:09:52 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/19 01:16:06 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(char const *s1, char const *s2)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s1[i++])
		len++;
	i = 0;
	while (s2 && s2[i++])
		len++;
	return (len + 1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
		return ((char *)s2);
	str = (char *) malloc(sizeof(char) * len(s1, s2));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[j++] = s1[i];
	i = -1;
	while (s2 && s2[++i])
		str[j++] = s2[i];
	str[j] = '\0';
	return (str);
}
