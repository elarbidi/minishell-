/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:16:24 by zait-che          #+#    #+#             */
/*   Updated: 2021/11/21 08:26:54 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	split_digit(int *tab, int n)
{
	int				i;
	unsigned int	nb;

	i = 0;
	if (n < 0)
		nb = -1 * n;
	else
		nb = n;
	while (nb != 0)
	{
		tab[i] = nb % 10;
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		tab[10];
	int		i;
	char	*str;
	int		j;

	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	j = split_digit(tab, n);
	if (n > 0)
		str = (char *) malloc(sizeof(char) * (j + 1));
	else
		str = (char *) malloc(sizeof(char) * (j + 2));
	if (!str)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		str[i++] = '-';
	while (--j >= 0)
		str[i++] = tab[j] + 48;
	str[i] = '\0';
	return (str);
}
