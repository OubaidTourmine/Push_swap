NAME = push_swap
CHEKER = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = Push_swap.c\
	parsing.c\
	split.c\
	utils1.c\
	utils2.c\
	sort1.c\
	sort2.c\
	sort3.c\
	sort4.c\
	1large_sort.c\
	2large_sort.c\
	3large_sort.c\
	4small_sort.c\
	./bonus_checker/checker_utils.c\

SRCS_BONUS = ./bonus_checker/checker.c\
				./bonus_checker/checker_utils.c\
				./bonus_checker/intsructions1.c\
				./bonus_checker/intsructions2.c\
				./bonus_checker/intsructions3.c\
				./bonus_checker/intsructions4.c\
				parsing.c\
				split.c\
				utils1.c\
				utils2.c\
				1large_sort.c\
				2large_sort.c\
				3large_sort.c\
				4small_sort.c\
				./get_next_line/get_next_line.c\
				./get_next_line/get_next_line_utils.c\

OBJS = ${SRC:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

bonus: ${CHEKER}
	
${CHEKER}: ${OBJS_BONUS}
	${CC} ${CFLAGS} ${OBJS_BONUS} -o ${CHEKER}
	
clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME} ${CHEKER}

re: fclean all

.PHONY: all clean fclean re bonus