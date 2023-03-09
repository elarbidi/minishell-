/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:23:30 by zait-che          #+#    #+#             */
/*   Updated: 2021/11/19 22:24:11 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc( size_t elementCount, size_t elementSize)
{
	void	*ptr;

	ptr = malloc(elementSize * elementCount);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, elementCount * elementSize);
	return (ptr);
}
