NAME = minitalk.a

FUNC = \
		client.c \
		server.c

LIBFT = libfta/libft.a

INC = includes

OBJ = $(FUNC:.c=.o)

CC = gcc

SRVR_NAME = server

CLNT_NAME = client

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

$(LIBFT):
	cd libfta && $(MAKE) && $(MAKE) bonus

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $? -o $@

$(SRVR_NAME): $(LIBFT)
	$(CC) $(CFLAGS) -I $(INC) server.o $(LIBFT) -o $(SRVR_NAME)

$(CLNT_NAME): $(LIBFT)
	$(CC) $(CFLAGS) -I $(INC) client.o $(LIBFT) -o $(CLNT_NAME)

all: $(NAME) $(SRVR_NAME) $(CLNT_NAME)

clean:
	rm -f $(OBJ) $(SRVR_NAME) $(CLNT_NAME)
	cd libfta && $(MAKE) clean

fclean:	clean
	rm -f $(NAME) 
	cd libfta && $(MAKE) fclean

re:	fclean all

.PHONY: all clean fclean re