NAME = minitalk.a

FUNC = \
		client.c \
		server.c

LIBFT = libfta/libft.a

INC = includes

OBJ = $(FUNC:.c=.o)

CC = gcc

SERVER_NAME = server

CLIENT_NAME = client

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

$(LIBFT):
	cd libfta && $(MAKE) && $(MAKE) bonus

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $? -o $@

$(SERVER_NAME): $(LIBFT)
	$(CC) $(CFLAGS) -I $(INC) server.o $(LIBFT) -o $(SERVER_NAME)

$(CLIENT_NAME): $(LIBFT)
	$(CC) $(CFLAGS) -I $(INC) client.o $(LIBFT) -o $(CLIENT_NAME)

all: $(NAME) $(SERVER_NAME) $(CLIENT_NAME)

clean:
	rm -f $(OBJ) $(SERVER_NAME) $(CLIENT_NAME)
	cd libfta && $(MAKE) clean

fclean:	clean
	rm -f $(NAME) 
	cd libfta && $(MAKE) fclean

re:	fclean all


.PHONY: all clean fclean re
