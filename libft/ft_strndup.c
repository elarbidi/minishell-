/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:12:47 by zait-che          #+#    #+#             */
/*   Updated: 2021/11/11 23:07:27 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char	*src, unsigned int n)
{
	char			*str;
	unsigned int	i;

	i = -1;
	str = (char *) malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	while (src[++i] && i < n)
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}
