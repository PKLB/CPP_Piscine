CC= c++
CFLAGS= -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
RM=rm -f
NAME=btc
SRCS= main.cpp

OBJS=${SRCS:.cpp=.o}

all:    ${NAME}

${NAME}:        ${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

.cpp.o:
	${CC} ${CFLAGS} -c $< -o $@

clean:
		@${RM} ${OBJS}

fclean:         clean
		@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re