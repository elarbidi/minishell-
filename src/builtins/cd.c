/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 02:58:47 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/23 04:46:59 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_newpath(char *path, char **envp)
{
	if (!path)
	{
		path = check_env("PWD", 0, envp);
		if (!path)
			path = ft_strdup("/");
	}
	return (path);
}

void	ft_chdir(char *path, t_data *data)
{
	char		*new_path;
	struct stat	st;

	new_path = get_newpath(getcwd(NULL, 0), data->envp);
	if (chdir(path) < 0)
	{
		if (stat(path, &st) < 0)
			print_error("minishell: cd: ", ft_strsjoin(ft_split(path, ' '),
					ft_split(": No such file or directory", '=')), 1);
		else
			print_error("minishell: cd: ", ft_strsjoin(ft_split(path, ' '),
					ft_split(strerror(errno), '=')), 1);
		return ;
	}
	add_env(data, new_path, "OLDPWD", -1);
	free(new_path);
	new_path = get_newpath(getcwd(NULL, 0), data->envp);
	add_env(data, new_path, "PWD", -1);
	free(new_path);
	g_exit_status = 0;
}

char	*get_path(char *dirname, t_data *data)
{
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	if (!ft_strncmp(dirname, "~/", 2))
	{
		path = check_env("HOME", i, data->envp);
		if (!*path)
			print_error("minishell: cd: HOME not set", NULL, 1);
		else
		{
			tmp = path;
			path = ft_strjoin(tmp, ft_strchr(dirname, '/'));
			free(tmp);
		}
		return (path);
	}
	else
		return (dirname);
}

void	ft_cd(char **args, t_data *data)
{
	char	*path;
	int		i;

	if (ft_strslen(args) > 1)
		print_error("minishell: cd: too many arguments", NULL, 1);
	i = 0;
	if (!*args || !ft_strcmp(args[0], "~", 0) || !ft_strcmp(args[0], "--", 0))
	{
		path = check_env("HOME", i, data->envp);
		if (!path)
			print_error("minishell: cd: HOME not set", NULL, 1);
	}
	else if (!ft_strcmp(args[0], "-", 0))
	{
		path = check_env("OLDPWD", i, data->envp);
		if (!path)
			print_error("minishell: cd: OLDPWD not set", NULL, 1);
	}
	else
		path = get_path(args[0], data);
	if (path)
		ft_chdir(path, data);
}
