CFLAGS = -Wall -Wextra -Werror -I./includes -c
FILES = srcs/*.c
NAME = libft.a
OBJ	= *.o

all: $(NAME) clean

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
		gcc $(CFLAGS) $(FILES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
