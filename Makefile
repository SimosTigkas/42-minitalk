NAME = minitalk.a

FUNC = \
		client.c \
		server.c

LIBFT = libfta/libft.a

INC = includes

OBJ = $(FUNC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

all: $(NAME) server client

server:
	cd libfta && $(MAKE)
	$(CC) $(CFLAGS) -I $(INC) server.c $(LIBFT) -o server

client: 
	$(CC) $(CFLAGS) -I $(INC) client.c $(LIBFT) -o client

clean:
	rm -f $(OBJ) server client
	cd libfta && $(MAKE) clean

fclean:	clean
	rm -f $(NAME) 
	cd libfta && $(MAKE) fclean

re:	fclean all
	cd libfta && $(MAKE) fclean
	cd libfta && $(MAKE) all

.PHONY: all clean fclean server client