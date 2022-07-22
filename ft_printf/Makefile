CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
RM =		rm -f
SRCS =		ft_printf.c \
		utils/add_modulo.c \
		utils/ft_strjoin_free.c \
		utils/get_format.c \
		utils/format_list.c 
		

OBJS =		${SRCS:.c=.o}
NAME =		libftprintf.a

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
	${RM} print_out

test:	re testc
	gcc tester/main.c -L. -lftprintf -L./libft -lft -o test 
	${VALGRIND} ./test
ulibft:	
	cd ../libft/ && make re
	cp ../libft/libft.h ./libft/libft.h
	cp ../libft/libft.a ./libft/libft.a
#gcc tester/print_out.c -L. -lftprintf -L./libft -lft -o print_out
