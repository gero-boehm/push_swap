CC=cc
CFLAGS=-I include -I lib/include
NAME=push_swap
SRC=parser.c
OBJ=$(SRC:.c=.o)
HEADERS=include/push_swap.h

ifndef LENIENT
	CFLAGS += -Wall -Wextra -Werror
endif

ifdef DEBUG
	CFLAGS += -g
endif

all: $(NAME)

%.o: %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

lib/lib.a:
	if [ ! -d "./lib" ]; then git clone https://github.com/gero-boehm/lib.git; fi
	(cd lib && make DEBUG=$(DEBUG) && make clean)

$(NAME): lib/lib.a $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

lclean: fclean
	rm -rf lib

re: fclean all

norm:
	norminette $(addprefix src/, $(SRC)) $(HEADERS)

.PHONY:
	all bonus clean fclean lclean re norm