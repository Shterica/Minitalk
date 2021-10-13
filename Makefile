SERVER		= server
SERV_SRCS	= server.c utils.c
SERV_OBJS	= $(SERV_SRCS:.c=.o)

CLIENT		= client
CLNT_SRCS	= client.c utils.c
CLNT_OBJS	= $(CLNT_SRCS:.c=.o)

H 			= minitalk.h

CFLAGS		= -Wall -Werror -Wextra
CC			= gcc

all: $(SERVER) $(CLIENT)

bonus: $(SERVER) $(CLIENT)

$(SERVER): $(SERV_OBJS)
	$(CC) $(SERV_OBJS) -o $(SERVER)

$(CLIENT): $(CLNT_OBJS)
	$(CC) $(CLNT_OBJS) -o $(CLIENT)

%.o: %.c $(H)
	$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

clean:
	rm -rf $(CLNT_OBJS)
	rm -rf $(SERV_OBJS)

fclean: clean
	rm -rf $(SERVER)
	rm -rf $(CLIENT)

re: fclean all

.PHONY: all clean fclean re