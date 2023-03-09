/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:12:43 by zait-che          #+#    #+#             */
/*   Updated: 2021/11/19 22:25:07 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t	size)
{
	size_t	i;
	size_t	j;
	size_t	lendest;
	size_t	lensrc;

	if (!size)
		return (ft_strlen(src));
	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	i = lendest;
	j = 0;
	if (size < lendest)
		return (lensrc + size);
	while (i < size - 1 && src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (lendest + lensrc);
}
