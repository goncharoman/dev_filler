/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:07:06 by ujyzene           #+#    #+#             */
/*   Updated: 2019/10/03 13:19:44 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <get_next_line.h>
# define STCK_OUT -2147483648
# define MAX(n1, n2) (n1 >= n2 ? n1 : n2)
# define ABS(n) ((n < 0) ? -n : n)

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_stack
{
	int				top;
	size_t			size;
	int				*array;
}					t_stack;

typedef union
{
	double			n;
	struct
	{
		uintmax_t	mnts : 52;
		uint32_t	exp : 11;
		uint32_t	sign : 1;
	}				spec;
}					t_float_cast;

typedef union		u_double
{
	long double		n;
	struct
	{
		uintmax_t	mnts : 64;
		uint32_t	exp : 15;
		uint32_t	sign : 1;
	}				spec;
}					t_double_cast;

intmax_t			ft_abs(intmax_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_isdigit(int c);
int					ft_isspace(char c);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(long long n);
char				*ft_itoa_base(intmax_t n, unsigned int base, int sign);
void				ft_putchar(int c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(int c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strrev(char *str);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_atoi_base(const char *str, int base);
size_t				ft_lstlen(t_list *list);
void				ft_lstappend(t_list **alst, t_list *new);
t_stack				*ft_stnew(size_t size);
int					ft_stpop(t_stack *stack);
void				ft_stpush(t_stack *stack, int item);
void				ft_stremove(t_stack *stack);
char				*ft_uitoa_base(uintmax_t n, unsigned int base);
int					ft_islower(char c);
int					ft_isupper(char c);
void				ft_chcase(char **str, int (func)(int));
long				ft_pow(long x, unsigned int n);
char				*ft_ftoa(double n, unsigned int prec, int sign);
char				*ft_ftoe(double n, size_t prec, int sign);
char				*ft_lftoa(long double n, unsigned int prec, int sign);
int					ft_strarrlen(char **strarr);
void				ft_strarrdel(char ***strarr);
char				*ft_readline(int fd);
#endif
