NAME ?= libftprintf.a
CC ?= gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_SRC_FILES = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putunbr_fd.c \
		ft_putnbr_16.c \
		ft_putnbr_16_caps.c \
		ft_revstr.c \
		ft_straddchar.c

LIB_SRC = $(addprefix libft/, $(LIBFT_SRC_FILES))
SRCS = 	ft_printf.c \
		printers/pf_putchar.c \
		printers/pf_putstr.c \
		printers/pf_putnbr.c \
		printers/pf_putunbr.c \
		printers/pf_putpointer.c \
		flags/spaces.c \
		$(LIB_SRC)

OBJS = ${SRCS:.c=.o}

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

