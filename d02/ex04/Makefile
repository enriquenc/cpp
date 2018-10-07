#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 13:04:14 by tmaslyan          #+#    #+#              #
#    Updated: 2018/10/01 13:04:16 by tmaslyan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = eval_expr

FLAGS = -Wall -Wextra -Werror

SRC = main.cpp Fixed.cpp EvalExpr.cpp

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