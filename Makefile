NAME=libft.a
AR=ar
ARFLAGS=rcs
CC=gcc
CFLAGS=-Wall -Wextra -Werror
INCLUDES=-Iincludes/
LIBCDIR= libc/
FT_PRINTFDIR= ft_printf/

LIBCSRC= $(addprefix $(LIBCDIR), \
	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c	\
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c		\
	ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c	\
	ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c	\
	ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c	\
	ft_isprint.c ft_tolower.c ft_toupper.c ft_memalloc.c ft_memdel.c\
	ft_strclr.c ft_strdel.c ft_striter.c ft_striteri.c ft_strnew.c	\
	ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c	\
	ft_strjoin.c ft_strtrim.c ft_itoa.c ft_putchar.c ft_putstr.c	\
	ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c			\
	ft_putendl_fd.c ft_putnbr_fd.c ft_strsplit.c ft_lstnew.c		\
	ft_lstdelone.c ft_lstadd.c ft_lstiter.c ft_lstdel.c ft_lstmap.c	\
	ft_lstpop.c ft_strndup.c ft_isblank.c ft_isnumber.c ft_islower.c\
	ft_isupper.c ft_strtrimc.c ft_dlstnew.c ft_dlstappend.c			\
	ft_dlstprepend.c ft_dlstdel_back.c ft_dlstdel_front.c			\
	ft_dlstdel.c ft_dlstdelone.c ft_rbnodenew.c ft_lstreverse.c		\
	ft_lstfilter.c ft_dlstreverse.c ft_dlstfilter.c ft_iscntrl.c	\
	ft_isgraph.c ft_isspace.c ft_isxdigit.c ft_str_is_alpha.c		\
	ft_str_is_lowercase.c ft_str_is_numeric.c ft_str_is_printable.c	\
	ft_str_is_uppercase.c ft_strcasecmp.c ft_strncasecmp.c			\
	ft_strcapitalize.c ft_atoimax.c ft_utoa_base.c to_utf8.c		\
	ft_strnjoin.c ft_basename.c ft_utoa.c ft_strnlen.c ft_stpncpy.c	\
	ft_isatty.c)

FT_PRINTFSRC= $(addprefix $(FT_PRINTFDIR), \
	ft_printf.c ft_fprintf.c ft_vprintf.c ft_vfprintf.c ft_printpercent_fd.c\
	ft_printchar_fd.c ft_printstr_fd.c ft_printunistr_fd.c ft_printint_fd.c	\
	ft_printuint_fd.c ft_printoctal_fd.c ft_printhexa_fd.c ft_printbin_fd.c	\
	ft_printpointer_fd.c ft_printunichar_fd.c ft_printn_fd.c ft_printitoa.c	\
	print_token.c parse_token.c)

SRC= $(FT_PRINTFSRC) $(LIBCSRC) ft_getopt/ft_getopt.c
OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) $(NAME)

.PHONY: all clean fclean re
