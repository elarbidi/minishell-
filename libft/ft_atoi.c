/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:39:51 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/22 13:21:31 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	unsigned long long	n;
	int					ng;
	int					i;

	ng = 1;
	n = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ng *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - 48);
		if ((n > 9223372036854775808u && ng < 0)
			|| (n > 9223372036854775807 && ng > 0))
			num_error((char *)str);
		i++;
	}
	return (n * ng);
}
