# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 00:32:50 by rcosta-c          #+#    #+#              #
#    Updated: 2025/06/02 22:49:20 by rcosta-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc
SRC = main.cpp BitcoinExchange.cpp

CC = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all