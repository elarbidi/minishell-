/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:20:32 by zait-che          #+#    #+#             */
/*   Updated: 2021/11/21 08:36:29 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	size_t	i;
	char	*ptr;
	size_t	len;

	i = -1;
	ptr = 0;
	len = ft_strlen(string);
	while (++i <= len)
	{
		if (string[i] == (unsigned char)searchedChar)
			ptr = (char *)(string + i);
	}
	return (ptr);
}
