/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:13:45 by edetoh            #+#    #+#             */
/*   Updated: 2024/11/26 11:30:29 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int				ft_atoi(const char *nptr);
size_t			ft_strlen(const char *s);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memcpy(void *dest, const \
				void *src, size_t n);
int				ft_isprint(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
void			ft_bzero(void *s, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, unsigned int size);
size_t			ft_strlcat(char *dest, const char *src, \
				size_t size);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
int				ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
int				ft_putnbr_fd(int n, int fd);

// >>>>>>> BONUS <<<<<<<
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
				void (*del)(void *));

// EN PLUS

char			*ft_unsigned_itoa(unsigned int n);
int				ft_putadress(void *ptr);
int				ft_puthexlow(unsigned int num);
int				ft_puthexup(unsigned int num);
int				ft_put_unsigned_nbr_fd(unsigned int n, int fd);

// PRINT F
int				ft_printf(const char *str, ...);

//GET NEXT LINE
typedef struct s_list_gnl
{
	char				*content;
	struct s_list_gnl	*next;
}					t_list_gnl;

t_list_gnl		*ft_lstlast_gnl(t_list_gnl *lst);
int				found_newline(t_list_gnl *list);
void			polish_list(t_list_gnl **list);
void			ft_lstadd_backbuffer(t_list_gnl **lst, char *buffer);
void			dealloc(t_list_gnl **list, t_list_gnl *clean_node, char *buf);
void			create_list(t_list_gnl **list, int fd);

char			*get_next_line(int fd);

#endif
