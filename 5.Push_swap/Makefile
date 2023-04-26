NAME		=	push_swap

NAME2		=	checker

LIB_PATH	=	libft/

LIB			=	${LIB_PATH}libft.a

NEW_LIB_PATH=	new_libft/

SORT_PATH	=	sortings/

OPER_PATH	=	operations/

SRCS		=	push_swap.c ft_check_error.c ft_lstorder.c ft_free.c ft_atoi2.c\
				${SORT_PATH}bubblesort.c ${SORT_PATH}sort_small_stack.c ${SORT_PATH}sort_big_stack.c \
				${wildcard ${OPER_PATH}*.c}

SRCS2		=	checker.c checker_utils.c ft_check_error.c ft_lstorder.c \
				get_next_line.c ft_strcmp.c ft_free.c \
				ft_atoi2.c ${SORT_PATH}bubblesort.c \
				${wildcard ${OPER_PATH}*.c}

HEADER		=	push_swap.h
OBJ			=	${SRCS:.c=.o}
OBJ2		=	${SRCS2:.c=.o}

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

RM			=	rm -rf

all			:	libft ${NAME} ${NAME2}

libft	:	
				@make -C ${LIB_PATH} all

${NAME}		: 	${OBJ} ${HEADER}
				@${CC} ${CFLAGS} -I ${HEADER} ${OBJ} ${LIB} -o ${NAME}

${NAME2}	: 	${OBJ2} ${HEADER}
				@${CC} ${CFLAGS} -I ${HEADER} ${OBJ2} ${LIB} -o ${NAME2}

clean		:
				@make -C ${LIB_PATH} clean
				@${RM} ${OBJ} checker.o checker_utils.o get_next_line.o ft_strcmp.o

fclean		:	
				@make -C ${LIB_PATH} fclean
				@${RM} ${OBJ} checker.o checker_utils.o get_next_line.o ft_strcmp.o
				@${RM} ${NAME} ${NAME2}

re			:	fclean all

.PHONY		:	all libft clean fclean re