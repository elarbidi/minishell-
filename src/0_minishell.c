/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_minishell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:41:52 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/23 04:46:59 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_copy(char **env)
{
	char	**envp;
	int		i;

	i = -1;
	envp = malloc(sizeof(char *) * (ft_strslen(env) + 1));
	while (env[++i])
		envp[i] = ft_strdup(env[i]);
	envp[i] = NULL;
	return (envp);
}

t_data	*data_init(char	**env, int ac, char **av)
{
	t_data	*data;

	(void)ac;
	(void)av;
	data = malloc(sizeof(t_data));
	if (!data)
	{
		print_error("minishell: memory allocation failed", 0, 1);
		return (0);
	}
	data->envp = env_copy(env);
	data->line = NULL;
	g_exit_status = 0;
	data->token_lst = NULL;
	data->cmd_lst = NULL;
	return (data);
}

char	*launch(t_data *data, char *str)
{
	ft_add_history(str);
	data->line = ft_strtrim(str);
	free(str);
	if (!data->line)
		return (0);
	lexer(data, ft_strlen(data->line), 0);
	if (!data->token_lst)
		return (ft_free2(data->line));
	expansion(data);
	if (!data->token_lst)
		return (ft_free2(data->line));
	parser(data);
	free(data->line);
	if (!data->token_lst)
		return (0);
	make_cmd(data);
	check_cmd(data);
	if (data->cmd_lst)
		exe_main(data->cmd_lst, data);
	cleanup(1, 1, data);
	return (0);
}

char	*display(char **envp)
{
	char	*tmp;
	char	*prompt;
	char	*line;

	tmp = getcwd(NULL, 0);
	if (!tmp)
	{
		tmp = check_env("PWD", 0, envp);
		if (!tmp)
			tmp = ft_strdup("");
	}
	prompt = ft_strjoin("\x1b[36m", tmp);
	free(tmp);
	tmp = prompt;
	prompt = ft_strjoin(tmp, "\x1b[0m$");
	free(tmp);
	line = readline(prompt);
	free(prompt);
	return (line);
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;
	char	*tmp;

	data = data_init(env, ac, av);
	if (!data)
		return (1);
	ft_restore_history();
	while (42)
	{
		main_signals();
		tmp = display(data->envp);
		if (!tmp)
		{
			ft_putstr_fd(RED"exit"RESET, 1);
			exit(g_exit_status);
		}
		else if (!*tmp)
			free(tmp);
		else
			launch(data, tmp);
	}
	free(data);
	rl_clear_history();
	return (0);
}
