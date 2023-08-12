# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 14:04:15 by yboudoui          #+#    #+#              #
#    Updated: 2023/08/12 18:58:28 by yboudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	PmergeMe

#-----------------------------------------------------------------------------#

SRCS				=	main.cpp\

OBJS				=	$(SRCS:.cpp=.o)

#-----------------------------------------------------------------------------#

CXX					=	c++

CXXFLAGS			=	-Wall -Wextra -Werror -std=c++98 -g3

RM					=	rm -f

.cpp.o:
			$(CXX) $(CXXFLAGS) -I. -c $< -o $(<:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) -I. $(OBJS) -o $(NAME)


clean:
			$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean
			make all

val:
	valgrind -q ./$(NAME) 6 5 9 8 7 10 15 11 12 19 21 2 3 1 13 32 42 56 34 89 74 75 79

val2:
	valgrind -q ./$(NAME) $(shuf -i 0-100000 -n 5000 | tr '\n' ' ')
.PHONY:		all clean fclean re
