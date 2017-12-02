/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:35:25 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/02 02:16:34 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define GETOPT_ON
# include "ft_getopt.h"

# define PHASZERO(x) ((((x + (0x7f7f7f7f7f7f7f7f)) ^ ~x) & 0x818080808080808080)
# define PHASN(x, n) (Phaszero(x ^ ((~0UL / 255L) * n)))
# define STATIC_BUF_SIZE 4096
# define BUFF_SIZE 4096
# define STATIC_PUT_FLUSH 1

# define NORETURN __attribute__((noreturn)) void

# define ERROR_NAME_HEADER "philo: "

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

typedef struct	s_string
{
	uint64_t	capacity;
	uint64_t	len;
	char		*string;
}				t_string;

typedef struct	s_mem_block
{
	uint64_t			capacity;
	uint64_t			offset;
	void				*block;
	struct s_mem_block	*next;
}				t_mem_block;

/*
** Mem_block handling
*/

# define MEM_BLOCK_LIMIT 256
# define DEFAULT_MEM_BLOCK_SIZE (10000)

void			*ft_mem_block_push_back_elem(t_mem_block *mem_block
									, void *elem, uint32_t size);
t_mem_block		*ft_create_mem_block(uint64_t capacity);

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strndup(char *str, size_t len);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_implode_strings(char **strings);
int				ft_atoi(const char *str);
uint64_t		ft_atol(const char *str);
int				ft_toupper(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
char			*ft_strreplace(char const *str, uint32_t start
						, uint32_t end, char const *src);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_itoa(int n);
char			*ft_ulltoa(uint64_t nbr);
char			*ft_static_lltoa(int64_t nbr);
char			*ft_static_ulltoa(uint64_t nbr);
char			*ft_static_ulltoa_base(uint64_t nbr, char *base);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_f(char *a, char *b, int32_t mode);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
void			ft_putchar(unsigned char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(void const *content, size_t content_size);
unsigned int	ft_lstlen(t_list *lst);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			*ft_lsttotab(t_list *lst, unsigned int len);

unsigned long	ft_pow(int nbr, unsigned int exponent);

void			ft_print_page(void *addr);
uint32_t		ft_static_put(char *str, uint32_t len, uint32_t flags);
uint32_t		ft_static_put_fd(char *str, uint32_t len, uint32_t flags
								, int fd);
unsigned int	ft_strchr_index(char *str, char c);

unsigned int	ft_log2(unsigned long long nbr);
uint64_t		ft_distance(uint64_t a, uint64_t b);
unsigned int	ft_max(unsigned int a, unsigned int b);
unsigned int	ft_is_power_of_two(unsigned long long nbr);
unsigned int	ft_is_little_endian(void);

uint64_t		ft_random(void);
void			ft_sort(int64_t	*tab, uint32_t len);
void			ft_sort_strings(char **strings, uint32_t n);

int				get_next_line(const int fd, char **line);
void			ft_get_cancer(char *str);

void			ft_t_string_expand(t_string *string);
t_string		*ft_t_string_concat(t_string *string, char *str);
t_string		*ft_t_string_new(uint32_t capacity);
void			ft_t_string_free(t_string *string);
t_string		*ft_t_string_concat_len(t_string *string
									, char *str, uint32_t str_len);

/*
** File handling
*/

char			*ft_get_file_content(char *filename);

/*
** Error Handling
*/

# define ERR_GET_FILE_CONTENT_MALLOC "malloc() failed in get_file_content()"
# define ERR_FILE_OPEN "Failed to open file: "
# define MALLOC_FAILURE "malloc() failed due to insufficient ressources"

int32_t			ft_error(uint32_t n, char **str, int32_t return_status);
NORETURN		ft_error_exit(uint32_t n, char **str, int32_t exit_status);

#endif
