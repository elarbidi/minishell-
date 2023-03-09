/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:32:39 by zait-che          #+#    #+#             */
/*   Updated: 2021/11/21 08:27:41 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = -1;
	if (src == NULL && dest == NULL && size != 0)
		return (NULL);
	while (++i < size)
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
	return (dest);
}
