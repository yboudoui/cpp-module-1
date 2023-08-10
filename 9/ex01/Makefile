# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 14:04:15 by yboudoui          #+#    #+#              #
#    Updated: 2023/08/10 18:25:26 by yboudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	RPN

#-----------------------------------------------------------------------------#

SRCS				=	main.cpp\

OBJS				=	$(SRCS:.cpp=.o)

#-----------------------------------------------------------------------------#

CXX					=	c++

CXXFLAGS			=	-Wall -Wextra -Werror -std=c++98

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
