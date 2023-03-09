/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 01:10:24 by zait-che          #+#    #+#             */
/*   Updated: 2021/12/14 19:11:50 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*gnl(char **stat, int end_r)
{
	int		len;
	char	*line;
	char	*tmp;

	if (!(*stat) || end_r < 0)
		return (0);
	len = 0;
	tmp = *stat;
	while (tmp[len] != '\n' && tmp[len])
		len++;
	line = ft_substr(*stat, 0, len + 1);
	tmp = ft_substr(*stat, len + 1, ft_strlen(*stat) - len);
	free(*stat);
	if (!*tmp)
	{
		*stat = 0;
		free(tmp);
	}
	else
		*stat = tmp;
	return (line);
}

static int	ft_read(char *buffer, char **line, int fd)
{
	int			end_r;
	char		*tmp;

	end_r = read(fd, buffer, BUFFER_SIZE);
	while (end_r > 0)
	{
		buffer[end_r] = 0;
		if (!line[fd])
			line[fd] = ft_strdup(buffer);
		else if (buffer)
		{
			tmp = ft_strjoin(line[fd], buffer);
			free(line[fd]);
			line[fd] = tmp;
		}
		if (ft_strchr(line[fd], '\n'))
			break ;
		end_r = read(fd, buffer, BUFFER_SIZE);
	}
	return (end_r);
}

char	*get_next_line(int fd)
{
	static char	*line[FOPEN_MAX];
	char		*buffer;
	int			end_r;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (0);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	end_r = ft_read(buffer, line, fd);
	free(buffer);
	return (gnl(&line[fd], end_r));
}
