NAME = pipex
CC	=	cc
SRCS_DIR = srcs/
SRCS =	$(SRCS_DIR)*.c

OBJECTS	=	*.o
CFLAGS	=	-Wall -Wextra -Werror

%.o:%.c	${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

$(NAME)	:	$(OBJECTS)
		$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

all	:	$(NAME)

clean	:
	rm -rf $(OBJECTS)

fclean	:	clean
	rm -rf  $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re