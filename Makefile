NAME= philo
SRC= srcs/main.c \
	srcs/baguettes_init.c \
	srcs/philos_init.c \
	srcs/philosophing.c
OBJ= $(SRC:.c=.o)
HDR_PATH= ./libft/includes/
CC= gcc
CC_FLAGS= -Ofast -v -Weverything -Wall -Werror -Wextra  -g3 -fsanitize=address -fsanitize-blacklist=my_ignores.txt #-Werror
#VPATH=./srcs:./obj:./includes/

all: submodule $(NAME)

submodule:
	@make -C libft/

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $^ -L./libft -lft -o $(NAME)
%.o : %.c
	$(CC) $(CC_FLAGS) $< -c -I$(HDR_PATH) -I./includes -o $@

clean:
	rm -f $(OBJ)
	make -C libft/ clean
fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
