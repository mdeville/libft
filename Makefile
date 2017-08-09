NAME=libft.a
AR=ar
ARFLAGS=rc
CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCDIR=srcs
SRC=ft_memset.c
OBJ=$(SRC:.c=.o)

all: $(NAME)

%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME)
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
