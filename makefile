SRC = client.c utils.c

SRC_B = server.c ft_printf.c ft_putnbr.c ft_putchar.c

OBJ = ${SRC:.c=.o}

OBJ_B = ${SRC_B:.c=.o}

CC = cc

NAME = client

NAME_B = server

RM = rm -f

GFLAGS = -Wall -Wextra -Werror

all: ${NAME} ${NAME_B}

%.o: %.c minitalk.h 
	${CC} ${CFLAGS} -c $< -o $@ 

${NAME}: ${OBJ}
	${CC} ${OBJ} -o ${NAME}

${NAME_B}: ${OBJ_B}
	${CC} ${OBJ_B} -o ${NAME_B}

clean: 
	${RM} ${OBJ} ${OBJ_B}

fclean: clean
	${RM} ${NAME} ${NAME_B}

re: fclean all

.PHONY: clean fclean all
