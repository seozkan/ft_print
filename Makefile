# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 10:17:13 by seozkan           #+#    #+#              #
#    Updated: 2023/02/25 14:15:39 by seozkan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = @gcc
RM = @rm -f
AR = ar rcs
FLAGS = -Wall -Wextra -Werror

YELLOW = \033[33;49;1m
END = \033[0;0m

SRC = ft_printf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	$(AR) $(NAME) *.o
	@echo "$(YELLOW)${NAME} ✔️$(END)"

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus