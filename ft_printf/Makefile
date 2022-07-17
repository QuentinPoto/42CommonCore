CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
RM =		rm -f
SRCS =		ft_printf.c \
			utils/add_modulo.c \
			utils/ft_strjoin_free.c \
			utils/get_format.c \
			utils/format_list.c

OBJS =		${SRCS:.c=.o}
NAME =     libftprintf.a

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re


VALGRIND = valgrind -q --leak-check=full --track-origins=yes

testc:
	${RM} test

test: testc
	gcc main.c -L. -lftprintf -lft -o test
