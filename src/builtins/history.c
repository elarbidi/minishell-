/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 02:59:24 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/23 04:46:59 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_line(int fd)
{
	int		count;
	char	*line;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	return (count);
}

void	ft_add_history(char	*line)
{
	int		fd;
	int		count;
	char	*tmp;

	add_history(line);
	fd = open(".history", O_CREAT | O_RDWR | O_APPEND, 0666);
	if (fd < 0)
	{
		print_error("minishell: failed to save history", 0, 1);
		return ;
	}
	count = count_line(fd);
	tmp = ft_itoa(count);
	ft_putstr_fd(tmp, fd);
	free(tmp);
	ft_putstr_fd(" ", fd);
	ft_putendl_fd(line, fd);
	close(fd);
}

void	ft_restore_history(void)
{
	int		fd;
	int		i;
	char	*line;
	char	*tmp;

	fd = open(".history", O_RDONLY | O_CREAT, 0666);
	if (fd < 0)
	{
		print_error("minishell: failed to load history", 0, 1);
		return ;
	}
	ft_putendl_fd("* History restored *", 1);
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i] != ' ')
			i++;
		tmp = ft_strndup(line + (i + 1), ft_strlen(line) - i - 2);
		add_history(tmp);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	history(void)
{
	int		fd;
	char	*line;

	fd = open(".history", O_RDONLY, 0666);
	if (fd < 0)
	{
		print_error("minishell: failed to load history", 0, 1);
		return ;
	}
	line = get_next_line(fd);
	while (line)
	{
		ft_putendl_fd(line, fd);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
