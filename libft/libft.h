/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:22:30 by zait-che          #+#    #+#             */
/*   Updated: 2023/01/22 08:35:39 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include "../src/minishell.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

size_t		ft_strlcat(char *dest, const char *src, size_t	size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		*ft_itoa(int n);
size_t		ft_strlen(const char *s);
char		*ft_strtrim(char const *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isdigit(int c);
void		*ft_memchr(const void *data, int searchedChar, size_t size);
int			ft_memcmp(const void *ptr1, const void *ptr2, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t size);
void		*ft_memmove(void *dest, const void *src, size_t size);
void		*ft_memset(void *ptr, int val, size_t count);
void		ft_bzero(void *s, size_t n);
int			ft_toupper(int ch);
int			ft_tolower(int ch);
char		*ft_strchr(const char *string, int searchedCha);
char		*ft_strrchr(const char *string, int searchedChar);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dest, const char *src, size_t	size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
long long	ft_atoi(const char *str);
char		*ft_strdup(const char	*src);
void		*ft_calloc( size_t elementCount, size_t elementSize);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_isspace(char c);
char		*get_next_line(int fd);
char		*ft_strndup(const char	*src, unsigned int n);
char		**ft_strsjoin(char **arr1, char **arr2);
void		ft_free(char **arr);
int			ft_strcmp(const char *s1, char *s2, int i);
int			ft_strslen(char **str);
char		*ft_chrjoin(char *s, char c);

#endif
