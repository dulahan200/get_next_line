SRCS = get_next_line.c get_next_line_utils.c
#SRCSBONUS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS = ${SRCS:.c=.o}
OBJSBONUS = ${SRCSBONUS:.c=.o}
HEADER = get_next_line.h #get_next_line_bonus.h

CC = gcc
RM = rm -f
#CFLAGS = -Wall -Wextra -Werror 
LEAKFLAGS = -fsanitize=address -g 
DEBUGFLAGS = -g

#TESTFOLDER = test_files/
TESTFOLDER = pacotest/

%.o : %.c	$(HEADER)
	@${CC} ${CFLAGS} -c $< -o $@

all:	${OBJS} $(HEADER)
	@${CC} ${CFLAGS} ${OBJS} $(HEADER) main.c
	@./a.out ${TESTFOLDER}${TEST}

sani:	${OBJS} $(HEADER)
	${CC} ${CFLAGS} ${LEAKFLAGS} ${OBJS} $(HEADER) main.c
	./a.out ${TESTFOLDER}${TEST}

debug:	$(HEADER)
	${CC} -g ${CFLAGS} ${DEBUGFLAGS} $(HEADER) ${SRCS} main.c
	lldb ./a.out ${TESTFOLDER}${TEST}

bonus:	${OBJS} ${OBJSBONUS} $(HEADER)
	@touch $@

clean:
	@${RM} ${OBJS} #${OBJSBONUS} bonus

fclean:			clean

re:		fclean all

.SILENT:


.PHONY: all clean fclean re sani
