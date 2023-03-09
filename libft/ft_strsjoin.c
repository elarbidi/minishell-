/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:42:55 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/22 08:35:31 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strcount(char **arr)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (arr[++i])
		count++;
	return (count);
}

char	**ft_strsjoin(char **arr1, char **arr2)
{
	char	**arr;
	int		i;
	int		j;

	if (!arr1 || !*arr1)
		return (arr2);
	if (!arr2 || !*arr2)
		return (arr1);
	arr = malloc(sizeof(char *) * (strcount(arr1) + strcount(arr2) + 1));
	if (!arr)
		return (NULL);
	i = -1;
	j = -1;
	while (arr1[++i])
		arr[++j] = ft_strdup(arr1[i]);
	i = -1;
	while (arr2[++i])
		arr[++j] = ft_strdup(arr2[i]);
	arr[++j] = NULL;
	ft_free(arr2);
	ft_free(arr1);
	return (arr);
}
