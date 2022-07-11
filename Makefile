CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
RM =		 rm -f
SRCS =		ft_split.c \
            ft_calloc.c \
            ft_itoa.c \
            ft_strmapi.c \
            ft_strtrim.c \
            ft_substr.c \
            ft_strjoin.c \
            ft_strdup.c \
            ft_atoi.c \
            ft_isalnum.c \
            ft_isalpha.c \
            ft_isascii.c \
            ft_isdigit.c \
            ft_isprint.c \
            is_in_charset.c \
            ft_strlcpy.c \
            ft_strlen.c \
            ft_strncmp.c \
            ft_putchar_fd.c \
            ft_putendl_fd.c \
            ft_putstr_fd.c \
            ft_putendl_fd.c
OBJS =		${SRCS:.c=.o}
NAME =     libft.a

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar -rc ${NAME} ${OBJS}
#ar rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

test: ${NAME}
	${CC} ${CFLAGS} main.c -L. -lft -o test


#gcc -o yourprog yourprog.c -lstatic

re: fclean all

.PHONY: all clean fclean re