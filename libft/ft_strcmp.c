/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:05:06 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/23 04:44:47 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, char *s2, int j)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s2[i] && s1[i] && (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	i = (unsigned char)s1[i] - (unsigned char)s2[i];
	if (j)
		free(s2);
	return (i);
}
