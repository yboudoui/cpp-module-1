# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 14:53:22 by yboudoui          #+#    #+#              #
#    Updated: 2023/08/08 11:25:11 by yboudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	Span

#-----------------------------------------------------------------------------#

SRCS				=	main.cpp\
						Span.cpp

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
