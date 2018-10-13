#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 13:04:14 by tmaslyan          #+#    #+#              #
#    Updated: 2018/10/11 14:35:42 by tmaslyan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = mindopen

FLAGS = -Wall -Wextra -Werror

SRC = main.cpp AsciiDown.cpp PointerToLeft.cpp Symbol.cpp GetChar.cpp PutChar.cpp AsciiUp.cpp Cycle.cpp  PointerToRight.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(OBJ) -o $(NAME) 

%.o: %.cpp
	clang++ $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all