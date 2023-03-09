/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:44:23 by zait-che          #+#    #+#             */
/*   Updated: 2021/11/21 08:55:33 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	long long	i;

	if (src == NULL && dest == NULL)
		return (NULL);
	i = -1;
	while ((size_t)++i < size && src > dest)
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
	i = size;
	while (--i >= 0 && src < dest)
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
	return (dest);
}
