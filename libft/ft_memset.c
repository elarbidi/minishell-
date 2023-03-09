/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:40:23 by zait-che          #+#    #+#             */
/*   Updated: 2021/11/22 08:29:34 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int val, size_t count)
{
	size_t	i;

	i = -1;
	while (++i < count)
		*(unsigned char *)(ptr + i) = val;
	return (ptr);
}
