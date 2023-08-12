# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 14:04:15 by yboudoui          #+#    #+#              #
#    Updated: 2023/08/12 09:24:36 by yboudoui         ###   ########.fr        #
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

.PHONY:		all clean fclean re
