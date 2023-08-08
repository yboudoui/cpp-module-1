# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 14:53:22 by yboudoui          #+#    #+#              #
#    Updated: 2023/07/31 14:53:26 by yboudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = g++
CFLAGS = -std=c++98 -Wall -Wextra

all: main

main: main.cpp Span.cpp
	$(CC) $(CFLAGS) main.cpp Span.cpp -o main

clean:
	rm -f main

