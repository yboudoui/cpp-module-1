# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 13:40:44 by yboudoui          #+#    #+#              #
#    Updated: 2023/07/05 09:54:51 by yboudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	AForm

#-----------------------------------------------------------------------------#

SRCS				=	main.cpp\
						Bureaucrat.cpp\
						AForm.cpp\
						ShrubberyCreationForm.cpp\
						RobotomyRequestForm.cpp\
						PresidentialPardonForm.cpp\

OBJS				=	$(SRCS:.cpp=.o)

#-----------------------------------------------------------------------------#

CXX					=	c++

CXXFLAGS			=	-Wall -Wextra -Werror -std=c++98

RM					=	rm -f

.cpp.o:
			$(CXX) $(CXXFLAGS) -I . -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
				$(CXX) $(CXXFLAGS) -I . $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean
			make all

.PHONY:		all clean fclean re
