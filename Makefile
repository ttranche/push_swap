SRC_COMMON = 	./src/common/actions/actions_1.c \
				./src/common/actions/actions_2.c \
				./src/common/actions/actions_3.c \
				./src/common/args.c \
				./src/common/clean.c \
				./src/common/stack.c \
				./src/common/utils/ft_utils_1.c \
				./src/common/utils/ft_utils_2.c \
				./src/common/utils/ft_utils_3.c

SRC_SORTER =	./src/sorter/looper.c \
				./src/sorter/main.c \
				./src/sorter/sorter.c \
				./src/sorter/utils/five_optimize.c \
				./src/sorter/utils/indexer.c \
				./src/sorter/utils/rotator.c \
				./src/sorter/utils/sorter_utils.c

SRC_CHECKER =	./src/checker/checker.c \
				./src/checker/main.c


OBJS_COMMON	= ${SRC_COMMON:.c=.o}
OBJS_SORTER		= ${SRC_SORTER:.c=.o}
OBJS_CHECKER	= ${SRC_CHECKER:.c=.o}

INCLUDE = ./src/include

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
NAME_CHECKER = checker

CC = gcc
RM = rm -f

all: ${NAME}

.c.o:
			${CC} ${CFLAGS} -I$(INCLUDE) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS_COMMON) $(OBJS_SORTER)
			${CC} $(CFLAGS) -I$(INCLUDE) -o $(NAME) $(OBJS_COMMON) $(OBJS_SORTER)

$(NAME_CHECKER): $(OBJS_COMMON) $(OBJS_CHECKER)
			${CC} $(CFLAGS) -I$(INCLUDE) -o $(NAME_CHECKER) $(OBJS_COMMON) $(OBJS_CHECKER)

clean:
			${RM} ${OBJS_COMMON} ${OBJS_SORTER} ${OBJS_CHECKER}

fclean: clean
			${RM} ${NAME} ${NAME_CHECKER}

re: fclean all

bonus: checker

.PHONY:		checker bonus all clean fclean re
