# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 00:34:24 by rcosta-c          #+#    #+#              #
#    Updated: 2025/04/15 00:34:25 by rcosta-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zombie
SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

CC = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all