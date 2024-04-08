SRCS = client.c server.c

OBJS = $(SRCS:%.c=%.o)

NAME = minitalk

CC = cc 

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all:		$(NAME)

%.o:	%.c 
			$(CC) $(CFLAGS) -Iprintf -c $? -o $@

$(NAME):	server client


server:		server.o 
			make -C printf
			$(CC) $(CFLAGS) $^ -Lprintf -lftprintf -o server

client:		client.o 
			make -C printf
			$(CC) $(CFLAGS) $^ -Lprintf -lftprintf -o client

printf:
			make -C printf

clean:
			make clean -C printf
			$(RM) $(OBJS)

fclean: clean
						$(RM) server client

re:						fclean all