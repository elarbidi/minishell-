/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:53:42 by zait-che          #+#    #+#             */
/*   Updated: 2021/11/15 21:18:59 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (*(unsigned char *)(ptr1 + i) != *(unsigned char *)(ptr2 + i))
			return (*(unsigned char *)(ptr1 + i)
				- *(unsigned char *)(ptr2 + i));
		i++;
	}
	return (0);
}
