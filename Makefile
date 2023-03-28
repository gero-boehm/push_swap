CC=cc
CFLAGS=-I include -I lib/include
NAME=push_swap
SRC=main.c parser.c stack.c operations/operations.c sort.c
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

100: all
	./push_swap 83 -326 -160 5 151 -260 112 -410 87 -358 -235 224 -142 -282 -228 -87 118 383 23 -117 384 -171 96 308 93 123 373 -372 321 493 -49 -432 -447 -176 451 364 166 -115 -496 190 256 337 350 -380 483 424 132 307 219 -401 242 -159 -53 -211 114 -283 -59 288 200 14 346 27 31 -68 386 -268 -47 -126 469 29 -245 101 332 25 187 362 44 280 -395 -100 268 -458 -154 206 486 -423 419 32 -74 -137 273 318 403 -406 -232 433 -344 -164 -168 216

100r: all
	./push_swap $(shell ./rand.sh 100 1000)

10: all
	./push_swap 48 41 38 20 9 -41 -44 -14 2 -40

10r: all
	./push_swap $(shell ./rand.sh 10 100)

10s: all
	./push_swap -5 -4 -3 -2 -1 0 1 2 3 4

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

lclean: fclean
	rm -rf lib

re: fclean all

norm:
	norminette $(SRC) $(HEADERS)

.PHONY:
	all bonus clean fclean lclean re norm 100 100r