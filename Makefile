# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zphakath <zphakath@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/18 05:07:34 by zphakath          #+#    #+#              #
#    Updated: 2018/08/22 17:24:28 by zphakath         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AbstractVM

SRC = Factory.cpp Int8.cpp int16.cpp int32.cpp float.cpp parse.cpp\
		Exception.cpp double.cpp readfast.cpp

all: $(NAME)

$(NAME):
		clang++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all
