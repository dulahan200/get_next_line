SRCS = get_next_line.c get_next_line_utils.c
#SRCSBONUS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS = ${SRCS:.c=.o}
OBJSBONUS = ${SRCSBONUS:.c=.o}
HEADER = get_next_line.h #get_next_line_bonus.h

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror 
EXTRAFLAGS = -fsanitize=address -g 




%.o : %.c	$(HEADER)
	@${CC} ${CFLAGS} -c $< -o $@

all:	${OBJS} $(HEADER)
	@${CC} ${CFLAGS} ${EXTRAFLAGS} ${OBJS} $(HEADER) main.c
	@./a.out ${TEST}
bonus:	${OBJS} ${OBJSBONUS} $(HEADER)
	@touch $@

clean:
	@${RM} ${OBJS} #${OBJSBONUS} bonus

fclean:			clean

re:		fclean all

.PHONY: all clean fclean re sani
