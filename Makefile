CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
RM =		 rm -f
SRCS =		is_in_charset_bonus.c \
			ft_char_to_str_bonus.c \
 			ft_strlen_until_bonus.c \
			ft_split.c \
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
 			ft_strlcpy.c \
 			ft_strlen.c \
 			ft_strncmp.c \
 			ft_putchar_fd.c \
 			ft_putendl_fd.c \
 			ft_putstr_fd.c \
 			ft_putendl_fd.c \
 			ft_bzero.c \
 			ft_putnbr_fd.c \
 			ft_memcpy.c \
 			ft_memccpy.c \
 			ft_memcmp.c \
 			ft_memchr.c \
 			ft_memset.c \
 			ft_memmove.c \
 			ft_toupper.c \
 			ft_tolower.c \
 			ft_strlcat.c \
 			ft_strchr.c \
 			ft_strrchr.c \
 			ft_strnstr.c

SRCS_BONUS =	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c


OBJS =			${SRCS:.c=.o}
OBJS_BONUS =	${SRCS_BONUS:.c=.o}
NAME =     		libft.a

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

bonus: ${OBJS} ${OBJS_BONUS}
	ar -rcs ${NAME} ${OBJS} ${OBJS_BONUS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}


testc:
	${RM} test
test: ${NAME} testc
	${CC} ${CFLAGS} main.c -L. -lft -o test && ./test



#gcc -o yourprog yourprog.c -lstatic

re: fclean all

.PHONY: all clean fclean re