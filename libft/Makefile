# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 16:57:58 by zait-che          #+#    #+#              #
#    Updated: 2023/01/10 02:26:03 by zait-che         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=  	ft_atoi.c ft_bzero.c ft_calloc.c\
			ft_isalnum.c ft_isalpha.c ft_isascii.c\
			ft_isdigit.c ft_isprint.c ft_itoa.c\
			ft_memchr.c ft_memcmp.c ft_memcpy.c\
			ft_memmove.c ft_memset.c ft_putchar_fd.c\
			ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
			ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c\
			ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
			ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
			ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\
			ft_isspace.c get_next_line.c ft_strndup.c ft_free.c\
			ft_strsjoin.c ft_strcmp.c ft_strslen.c ft_chrjoin.c

OBJS	= $(SRCS:.c=.o)

CC 		= cc

NAME	= libft.a

CFLAGS	=  -Wall -Wextra -Werror

all:		$(NAME)		

$(NAME):	$(OBJS)

clean:
		rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re: 		fclean all

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
	ar rc $(NAME) $@

.PHONY: 	all clean fclean re
