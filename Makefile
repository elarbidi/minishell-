# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 00:21:11 by zait-che          #+#    #+#              #
#    Updated: 2023/01/23 04:19:00 by aelarbid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= minishell
CC		:= gcc
#where should we look for files to include
#ANAS VARS
INCLUDE	:= -I. -I./Libft -I /Users/aelarbid/homebrew/opt/readline/include/
CFLAGS	:= -Wall -Werror -Wextra $(INCLUDE) -g -fsanitize=address
LIBS	:= -L./Libft -lft -lreadline  -L /Users/aelarbid/homebrew/opt/readline//lib
#ZINB VARS
#INCLUDE	:= -I. -I./Libft -I /Users/zait-che/.brew/opt/readline/include
#CFLAGS	:= -Wall -Werror -Wextra $(INCLUDE) -g -fsanitize=address
#where should we look for libraries to link with and What libraries should be linked with
#LIBS	:= -L./Libft -lft -lreadline  -L /Users/zait-che/.brew/opt/readline/lib
#a dependency
LIBFT	:= ./Libft/libft.a
#where object files are stored
SRCS	:= src/0_minishell.c src/1_tokenizer.c src/2_expansions.c\
			src/3_parser.c src/4_cmdline.c src/5_heredoc.c\
			src/6_signal_handling.c\
			src/lst_utils/lexer_lst.c src/lst_utils/cmd_lst.c src/lst_utils/file_lst.c\
			src/builtins/export.c src/builtins/unset.c \
			src/builtins/cd.c src/builtins/echo.c \
			src/builtins/env.c src/builtins/exit.c \
			src/builtins/pwd.c src/builtins/history.c \
			src/exec/index.c src/exec/duping.c\
			src/exec/exec_built_in.c src/exec/final_close.c\
			src/exec/fork_to_child.c src/exec/node_len.c\
			src/exec/open_files.c src/exec/path_finder.c\
			src/exec/path_join.c src/exec/print_err.c \
			src/utils/utils.c src/utils/0_expansion.c \
			src/utils/0_filename.c src/utils/1_filename.c \
			src/utils/0_export.c src/utils/0_heredoc.c src/utils/0_cmdline.c \
			src/utils/0_tokenizer.c src/exec/index_utils.c \
			src/exec/path_finder_utils.c
			
			
OBJS	:= $(SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): ./Libft/*.c
	$(MAKE) -C ./Libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

clean:
	$(MAKE) clean -C ./Libft
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C ./Libft

re: fclean all
