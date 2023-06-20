# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 13:40:44 by yboudoui          #+#    #+#              #
#    Updated: 2023/06/18 19:14:45 by yboudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	Bureaucrat

#-----------------------------------------------------------------------------#

SRCS				=	main.cpp\
						Bureaucrat.cpp

OBJS				=	$(SRCS:.cpp=.o)

#-----------------------------------------------------------------------------#

CXX					=	c++

CXXFLAGS			=	-Wall -Wextra -Werror -std=c++98

RM					=	rm -f

.cpp.o:
			$(CXX) $(CXXFLAGS)  -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
				$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean
			make all

.PHONY:		all clean fclean re
