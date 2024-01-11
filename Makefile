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

libft:
	cd libfta && $(MAKE)

server: libft
	@echo "Compiling the server"
	$(CC) $(CFLAGS) -I $(INC) server.o $(LIBFT) -o server

client: libft
	@echo "Compiling the client"
	$(CC) $(CFLAGS) -I $(INC) client.o $(LIBFT) -o client

all: $(NAME) server client

clean:
	rm -f $(OBJ) server client
	cd libfta && $(MAKE) clean

fclean:	clean
	rm -f $(NAME) 
	cd libfta && $(MAKE) fclean

re:	fclean all

.PHONY: all clean fclean re server client