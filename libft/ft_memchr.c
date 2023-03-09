/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:29:29 by zait-che          #+#    #+#             */
/*   Updated: 2021/11/15 20:55:53 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *data, int searchedChar, size_t size)
{
	void			*ptr;
	size_t			i;
	unsigned char	chr;

	i = 0;
	chr = (unsigned char) searchedChar;
	while (i < size)
	{
		if (*(unsigned char *)data == chr)
		{
			ptr = (void *)data ;
			return (ptr);
		}
		data++;
		i++;
	}
	return (NULL);
}
