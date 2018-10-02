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

NAME = zombie_farm

FLAGS = -Wall -Wextra -Werror

SRC = Zombie.cpp ZombieEvent.cpp main.cpp

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