/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:04:40 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/21 10:41:01 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedCha)
{
	int	i;
	int	len;

	if (!string)
		return (NULL);
	len = ft_strlen(string);
	i = 0;
	while (i <= len)
	{
		if (string[i] == (unsigned char)searchedCha)
			return ((char *)(string + i));
		i++;
	}
	return (0);
}
