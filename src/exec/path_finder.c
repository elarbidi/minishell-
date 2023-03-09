/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 03:25:43 by aelarbid          #+#    #+#             */
/*   Updated: 2023/01/23 04:54:52 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exiting(char *s, char *path)
{
	if (access(path, F_OK))
	{
		exec_err(s, "command not found");
		g_exit_status = 127;
		if (!path || !*path)
			g_exit_status = 126;
		exit(g_exit_status);
	}
}

char	*path_finder(t_cmdline *cmd, t_data *data)
{
	char	**paths;
	char	*path;
	int		j;

	path = get_env(data);
	paths = NULL;
	dot(cmd);
	dir(cmd->cmd_args[0]);
	if (!path || ft_strchr(cmd->cmd_args[0], '/'))
		return (cmd->cmd_args[0]);
	if (cmd->cmd_args[0] && cmd->cmd_args && !ft_strchr(cmd->cmd_args[0], '/'))
	{
		paths = ft_split(path, ':');
		j = 0;
		while (paths[j])
		{
			paths[j] = path_join(paths[j], ft_strdup(cmd->cmd_args[0]));
			if (access(paths[j], X_OK) == 0)
				path = ft_strdup(paths[j]);
			j++;
		}
	}
	exiting(cmd->cmd_args[0], path);
	return (path);
}

// char    *path_finderrr(t_cmdline *cmd, t_data *data){
//     char **paths = NULL;
//     char *path;
//     //char *str
//     path = get_env(data);
//     if(!*path || (!access(cmd->cmd_args[0],X_OK) || !cmd->cmd_args[0])){
//         printf("lelle");
//         return cmd->cmd_args[0];
//     }
//     printf(" num = > %d\n",check_if_path(cmd->cmd_args[0]));
//     if(cmd->cmd_args[0] && cmd->cmd_args && !check_if_path(cmd->cmd_args[0]))
//     {
//         paths =ft_split(path, ':');
//         int j = 0;
//         while(paths[j]){
//             paths[j] = path_join(paths[j],ft_strdup(cmd->cmd_args[0]));
//             int acc = access(paths[j],X_OK);
//             if(acc == 0)
//             {
//                 path = ft_strdup(paths[j]);
//             }
//             free(paths[j]);
//             j++;
//         }
//     }else if(access(cmd->cmd_args[0],X_OK) < 0){
//         printf("here\n");
//         perror("minishell  ");
//         exit(126);
//     }
//     free(paths);
//     return(path);
// }