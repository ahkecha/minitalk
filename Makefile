# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 13:07:22 by ahkecha           #+#    #+#              #
#    Updated: 2021/12/19 13:14:34 by ahkecha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = minitalk_server.c minitalk_utils.c

CLIENT = minitalk_client.c minitalk_utils.c

NAME_SERVER = server

NAME_CLIENT = client

all:
	gcc -Wall -Wextra -Werror $(SERVER) -o $(NAME_SERVER)
	gcc -Wall -Wextra -Werror $(CLIENT) -o $(NAME_CLIENT)

clean:
	rm -f client.o server.o

fclean:	clean
	rm -f server client


server:
	rm -f server
	gcc -Wall -Wextra -Werror $(SERVER) -o $(NAME_SERVER)

client:
	rm -f client
	gcc -Wall -Wextra -Werror $(CLIENT) -o $(NAME_CLIENT)

.PHONY: server client all re fclean clean
