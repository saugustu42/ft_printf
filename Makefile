# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saugustu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 18:08:32 by saugustu          #+#    #+#              #
#    Updated: 2021/01/25 17:55:30 by saugustu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIST = ft_printf.c

OBJ = $(patsubst %.c,%.o,$(LIST))

D_FILES = $(patsubst %.c,%.d,$(LIST))

OPTFLAGS = -O2
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

%.o : %.c
	gcc $(FLAGS) $(OPTFLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean :
	rm -f $(OBJ) $(D_FILES)

fclean : clean
	rm -f $(NAME)

re : fclean all
