NAME= libft.a
CC= gcc
FLAGS= -Wall -Wextra -Werror -g3 -fsanitize=address -fsanitize-blacklist=blacklist.txt
SRC=	 ft_pow.c \
		ft_atoi.c \
		ft_atol.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_max.c \
		ft_distance.c \
		ft_strchr_index.c \
		ft_log2.c \
		ft_is_little_endian.c \
		ft_is_power_of_two.c \
		ft_lsttotab.c \
		get_next_line.c \
		ft_lstlen.c \
		ft_print_page.c \
		ft_random.c \
		ft_sort.c \
		ft_strreplace.c \
		ft_strjoin_f.c \
		get_next_line.c \
		ft_get_cancer.c \
		ft_strndup.c \
		ft_static_put.c \
		ft_static_put_fd.c \
		ft_t_string_concat.c \
		ft_t_string_expand.c \
		ft_t_string_new.c \
		ft_t_string_concat_len.c \
		ft_implode_strings.c \
		ft_sort_strings.c \
		ft_error.c \
		ft_error_exit.c \
		ft_t_string_free.c \
		ft_get_file_content.c \
		ft_mem_block_push_back_elem.c \
		ft_create_mem_block.c \
		ft_ulltoa.c \
		ft_static_ulltoa.c \
		ft_static_ulltoa_base.c \
		ft_static_lltoa.c \
		ft_getopt.c

OBJ= $(SRC:.c=.o)
HDR_PATH= includes
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) $< -I $(HDR_PATH) -c

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
