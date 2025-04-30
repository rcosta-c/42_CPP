# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcosta-c <rcosta-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 00:32:50 by rcosta-c          #+#    #+#              #
#    Updated: 2025/04/30 10:56:53 by rcosta-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Form
SRC = main.cpp Bureaucrat.cpp AForm.cpp

CC = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all