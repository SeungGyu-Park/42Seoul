NAME		=	libftprintf.a
CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror

SRCS		=	ft_printf.c\
				ft_printf_utils.c
OBJS		=	$(SRCS:.c=.o)

RM			=	rm -f
AR			=	ar rcs

%.o		:	%.c
			$(CC) $(CFLAG) -c -o $*.o $<
$(NAME)		: 	$(OBJS)
			@ $(AR) $(NAME) $(OBJS)
all			:	$(NAME)
clean		:
				$(RM) $(OBJS)
fclean		:	clean
				$(RM) $(NAME)
re			:	fclean all
.PHONY		:	all clean fclean re