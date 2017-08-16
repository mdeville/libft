NAME=libft.a
AR=ar
ARFLAGS=rc
CC=gcc
CFLAGS=-Wall -Wextra -Werror
LDLIB=-lcheck -lft
LDFLAGS=-L./
SRCDIR=srcs
BIN=checklib
CHECKSRC=libft.c
INCLUDES=-I./
SRC=ft_memset.c ft_bzero.c
OBJ=$(SRC:.c=.o)

all: $(NAME)

%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $<

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@ranlib $(NAME)

%.c: %.check
	@checkmk $^ > $@

$(BIN): $(CHECKSRC) $(NAME)
	@$(CC) $(CFLAGS) -o $@ $< $(INCLUDES) $(LDFLAGS) $(LDLIB)
	@rm $(CHECKSRC)

check: $(BIN)
	@./$(BIN)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
