NAME ?= libftprintf.a
CC ?= gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = 	ft_printf.c

OBJS = ${SRCS:.c=.o}

BONUS =	# ft_lstadd_front.c

BONUS_OBJS = $(BONUS:.c=.o)

all: ${NAME}

${NAME}: ${OBJS}
	make -C ./libft
	ar rcs ${NAME} ${OBJS}

bonus:	${OBJS} ${BONUS_OBJS}
	ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

%.o: %.c
	${CC} ${CFLAGS} -o ${@} -c ${@:.o=.c}

re: fclean all

fclean: clean
	rm -f ${NAME}

clean:
	rm -f ${OBJS} ${BONUS_OBJS}

.PHONY: clean fclean re all

