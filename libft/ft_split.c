/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:52:17 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/21 07:49:39 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free2(char **str, int j)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
	str = NULL;
	return (str);
}

static int	strcount(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
		{
			if (s[i + 1] != c && s[i + 1] != '\0')
				count++;
			i++;
		}
		if (!s[i])
			break ;
		i++;
	}
	return (count + 1);
}

static int	lencount(const char *s, char c, int start)
{
	int	end;

	end = start;
	while (s[end] && s[end] != c)
		end++;
	return (end - start);
}

static char	**func(char const *s, char **str, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		str[j] = malloc(sizeof(char) * (lencount(s, c, i) + 1));
		if (!str[j])
			return (free2(str, j));
		k = 0;
		while (s[i] && s[i] != c)
			str[j][k++] = s[i++];
		str[j][k] = '\0';
		j++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (strcount(s, c) + 1));
	if (!str)
		return (NULL);
	str = func(s, str, c);
	return (str);
}
