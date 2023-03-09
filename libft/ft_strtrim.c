/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:01:58 by zait-che          #+#    #+#             */
/*   Updated: 2021/11/19 23:30:30 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1)
{
	int		i;
	char	*str;
	int		len;
	char	*start;

	if (s1 == NULL)
		return (NULL);
	while (*s1 && ft_isspace(*s1))
		s1++;
	if (*s1 == 0)
		return (NULL);
	start = (char *)s1;
	s1 = &start[ft_strlen(s1) - 1];
	while (*s1 && ft_isspace(*s1))
		s1--;
	len = s1 - start + 1;
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = start[i];
	str[i] = '\0';
	return (str);
}
