# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 13:40:44 by yboudoui          #+#    #+#              #
#    Updated: 2023/07/28 09:07:24 by yboudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	Serializer

#-----------------------------------------------------------------------------#

SRCS				=	main.cpp\
						Serializer.cpp

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
