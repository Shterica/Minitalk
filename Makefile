SERVER		= server
SERV_SRCS	= server.c utils.c
SERV_OBJS	= $(SERV_SRCS:.c=.o)

CLIENT		= client
CLNT_SRCS	= client.c utils.C
CLNT_OBJS	= $(CLNT_SRCS:.c=.o)

HEADER		= -I ./

CFLAGS		= -Wall -Werror -Wextra
CC			= gcc
