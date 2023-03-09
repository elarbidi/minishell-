/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 03:27:38 by aelarbid          #+#    #+#             */
/*   Updated: 2023/01/22 18:01:26 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_fd(t_fd *temp)
{
	temp->fdin = 0;
	temp->fdout = 1;
}

void	close_fd(t_files *tmp, t_fd *temp)
{
	int	fd;

	if ((temp->fdin != 0 || temp->fdout != 1) && tmp->next)
	{
		fd = temp->fdin;
		if (temp->fdout != 1)
		fd = temp->fdout;
		close(fd);
	}
}

void	err_func(t_fd *temp, t_files *tmp)
{
	if ((temp->fdin < 0 || temp->fdout < 0))
	{
		open_err(tmp->filename);
		free(temp);
		exit(1);
	}
}

void	file_openner(t_files *tmp, t_fd *temp)
{
	if ((tmp->type == redirIn || tmp->type == heredoc))
		temp->fdin = open(tmp->filename, O_RDONLY);
	else if (tmp->type == redirOut)
		temp->fdout = open(tmp->filename, O_WRONLY
				| O_CREAT | O_TRUNC, 0666);
	else if (tmp->type == append)
		temp->fdout = open(tmp->filename, O_WRONLY
				| O_CREAT | O_APPEND, 0666);
}

t_fd	*open_file(t_files *files)
{
	t_files	*tmp;
	t_fd	*temp;

	tmp = files;
	temp = malloc(sizeof(t_fd));
	init_fd(temp);
	while (tmp && ft_strcmp(tmp->filename, "error", 0))
	{
		close_fd(tmp, temp);
		file_openner(tmp, temp);
		err_func(temp, tmp);
		tmp = tmp->next;
	}
	if (tmp && !ft_strcmp(tmp->filename, "error", 0))
	{
		if (temp->fdin != 0)
			close(temp->fdin);
		if (temp->fdout != 1)
			close(temp->fdout);
		free(temp);
		return (0);
	}
	return (temp);
}
