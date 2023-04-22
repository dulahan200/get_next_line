SRCS = get_next_line.c get_next_line_utils.c
#SRCSBONUS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS = ${SRCS:.c=.o}
OBJSBONUS = ${SRCSBONUS:.c=.o}
HEADER = get_next_line.h #get_next_line_bonus.h

BUFF = 1000
CC = gcc
RM = rm -f
#CFLAGS = -Wall -Wextra -Werror 
EXTRAFLAGS = -D BUFFER_SIZE=${BUFF} -fsanitize=address -g 




%.o : %.c	$(HEADER)
	@${CC} ${CFLAGS} -c $< -o $@

all:	${OBJS} $(HEADER)
	@${CC} ${CFLAGS} ${EXTRAFLAGS} main.c ${OBJS} $(HEADER) 
	@./a.out
bonus:	${OBJS} ${OBJSBONUS} $(HEADER)
	@touch $@

clean:
	@${RM} ${OBJS} #${OBJSBONUS} bonus

fclean:			clean

re:		fclean all

.PHONY: all clean fclean re sani
