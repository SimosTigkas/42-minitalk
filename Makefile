NAME=minitalk.a

FUNC = \
		client.c \
		server.c

LIBFTA = libft.a

INC = includes

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	gcc $(CFLAGS) -I$(INC) -c $< -o $@ 

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)