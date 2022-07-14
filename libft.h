/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:22:48 by qjungo            #+#    #+#             */
/*   Updated: 2022/07/11 21:22:48 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define INT_MIN -2147483648

typedef struct s_list {
	void			*content;
	struct s_list	*next;
}	t_list;

char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmem, size_t size);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *string);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *string);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_strlen(const char *string);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_is_in_charset(char c, const char *charset);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strlen_until(const char *string, const char *charset);
void	ft_memset(void *s, int c, size_t n);
void	*ft_realloc(void *ptr, size_t size);
char	*ft_char_to_str(char c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t count);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strrchr(char *str, int c);
char	*ft_strchr(char *str, int c);

/// Bonus
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));


#endif
