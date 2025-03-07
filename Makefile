NAME        := libftprintf.a
CC        := gcc
FLAGS    := -Wall -Wextra -Werror 

SRCS        :=      ft_printf.c \
                          ft_printf_utils.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}


${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
			@ ${RM} *.o */*.o */*/*.o

fclean:		clean
			@ ${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re


