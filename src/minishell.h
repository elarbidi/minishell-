/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:51:15 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/23 04:46:59 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>
# include <dirent.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include "../libft/libft.h"

# define CYAN "\x1b[36m"
# define RED "\x1b[31m"
# define RESET "\x1b[0m"
# define MALLOC "minishell: allocation failed"
# define PIPE "minishell: pipe failed to initialize"
# define FORK "minishell: fork failed to initialize"

typedef enum e_token
{
	word,
	append,
	redirIn,
	redirOut,
	heredoc,
	pip,
	dquotes,
	squotes
}	t_token;

typedef struct s_lexer
{
	char			*content;
	unsigned int	index;
	int				type;
	struct s_lexer	*next;
}	t_lexer;

typedef struct s_files
{
	char			*filename;
	int				type;
	struct s_files	*next;
}	t_files;

typedef struct s_cmdline
{
	char				**cmd_args;
	int					is_builtin;
	t_files				*files;
	struct s_cmdline	*next;
}	t_cmdline;

typedef struct s_fd
{
	int	fdin;
	int	fdout;
}	t_fd;

typedef struct s_data
{
	char		*line;
	t_lexer		*token_lst;
	t_cmdline	*cmd_lst;
	char		**envp;
	t_fd		*fds;
}	t_data;

/** global variable **/

int	g_exit_status;

/** debug **/

void		print_tokens(t_lexer *lst);
void		print_cmdline(t_cmdline *lst);

/** utils **/

int			print_error(char *msg, char **content, int stat);
void		cleanup(int i, int j, t_data *data);
void		free_data(t_data *data);
void		mini_join2(char *line, int *i, char **ret);
void		mini_join(char **str1, char *str2);
char		*ft_free2(char *str);
char		**env_copy(char **env);

/** signal handling **/

void		sig_handler(int signum);
void		sigdoc_handler(int signum);
void		heredoc_signals(void);
void		main_signals(void);

/** tokenizer **/

void		lexer(t_data *data, int len, int j);
void		init_word(t_data *data, int *i, int j);
int			init_quotes(t_data *data, int *i, int j);
char		*check_quotes(char *line, int *i, char c);
void		init_redir(t_data *data, int *i, int j, int len);
char		*get_filename(char *line, int *i, int type, char **envp);
int			check_filename(char *line, int *i, int type);
char		*expand_filename(int *i, char*line, char **ret, char **envp);
char		*remove_quote(int *i, char *line, char **ret, char **envp);
char		*function(char *str, char **envp);
int			another_function(char *str);
char		*get_filename(char *line, int *i, int type, char **envp);
int			quotes_conditin(t_data *data, int i);
int			redir_conditin(t_data *data, int i);
int			pipe_conditin(t_data *data, int i);

/** expansions **/

int			expansion(t_data *data);
char		*expand_dollar(char *str, char **envp);
char		*check_env(char *str, int i, char **envp);
void		helper_func(t_lexer *head, int *i, char **envp);
char		*ft_join(char *str, char *str2, int i, int j);
char		*get_varname(char *str, int i);
void		mini_join3(char **ret, int i, char *str);

/** perser **/

void		parser(t_data *data);
int			is_valid(int type1, int type2);
void		ahwmnba3d(t_lexer **lst);

/** cmdline **/

void		make_cmd(t_data *data);
void		add_redir(char *filename, int type, t_cmdline *cmdline,
				t_data *data);
int			is_builtin(char	*cmd);
int			is_redir(int type);
int			add_pipe(t_cmdline **current, t_lexer *head, t_data *data);
int			check_syntax_err(int type, t_cmdline *node1,
				t_lexer *node2, t_data *data);
void		check_cmd(t_data *data);

/** heredoc **/

char		*_heredoc(char *limiter, t_data *data);
void		expand_heredoc(char *line, int fd, char	**envp);
char		*remove_quotes(char *limiter);
char		*open_heredoc(int *fd);
int			count_quotes(char *limiter);

/** built-ins **/

void		env(char **envp);
void		export(char	**content, t_data *data);
void		add_env(t_data *data, char *content, char *var_name, int add);
void		sorted_print(char **envp);
void		update_var2(char *content, t_data *data, int i);
void		update_var(char *var_name, char *content, t_data *data, int i);
void		update_path(char *var_name, char *content, t_data *data, int i);
void		history(void);
void		ft_add_history(char	*line);
void		ft_restore_history(void);
int			count_line(int fd);
void		unset(char	**var_name, t_data *data);
char		**new_envp(char	**old_env, int idx);
int			check_varname(char *content, char *var_name);
int			get_index(char **envp, char *var_name);
void		ft_cd(char **args, t_data *data);
char		*get_newpath(char *path, char **envp);
void		ft_chdir(char *path, t_data *data);
char		*get_path(char *dirname, t_data *data);
void		ft_echo(char **args);
int			is_option(char	*content, int *n);
void		ft_exit(char **args);
void		num_error(char	*val);
void		print_exit(int stat);
void		ft_pwd(char **envp);

/** lst utils **/

t_lexer		*ft_lstlast(t_lexer *lst);
t_lexer		*token_init(int i, char *ctn, int type);
t_lexer		*ft_lstadd_back(t_lexer **alst, t_lexer *new);
void		ft_lstclear(t_lexer **lst);
t_cmdline	*create_node(void);
t_cmdline	*ft_lstlast2(t_cmdline *lst);
t_cmdline	*ft_lstadd_back2(t_cmdline **alst, t_cmdline *new);
void		ft_lstclear2(t_cmdline **lst);
t_files		*create_node2(char *filename, int type);
t_files		*ft_lstlast3(t_files *lst);
void		ft_lstadd_back3(t_files **alst, t_files *new);
void		ft_lstclear3(t_files **lst);

/** execution **/

void		dup_core1(int *fd);
void		dup_core2(int *fd);
void		dup_core3(int *pipeA, int *pipeB);
void		exec_builtin(t_cmdline *cmd, t_data *data);
void		final_close(int *fd);
void		child_fork(t_cmdline *cmd, t_data *data, int fd[2][2], int i[2]);
int			node_len(t_cmdline *cmd);
t_fd		*open_file(t_files *files);
char		*path_finder(t_cmdline *cmd, t_data *data);
char		*path_join(char *s1, char *s2);
void		exec_err(char *cmd, char *msg);
void		open_err(char *cmd);
void		exe_main(t_cmdline *cmd, t_data *data);
void		exec_one_cmd(t_cmdline *cmd, t_data *data);
void		exit_status(void);
char		*get_env(t_data *data);
void		dot(t_cmdline *cmd);
int			isdir(char *name);
void		dir(char *s);

#endif