# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saugustu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 18:08:32 by saugustu          #+#    #+#              #
#    Updated: 2021/01/25 23:11:09 by saugustu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB_PATH = ./libft
LIB = $(LIB_PATH)/libft.a

LIST = ft_printf.c print_chars.c print_hex.c\
	   print_sig.c put_count.c parser.c

OBJ = $(patsubst %.c,%.o,$(LIST))

D_FILES = $(patsubst %.c,%.d,$(LIST))

OPTFLAGS = -O2
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(LIB) $(OBJ)
	ar rcs $(NAME) $?

%.o : %.c
	gcc $(FLAGS) $(OPTFLAGS) -c $< -o $@ -MD

$(LIB) : NONE
	$(MAKE) -C $(LIB_PATH)
	cp $(LIB) $(NAME)

include $(wildcard $(D_FILES))

clean :
	rm -f $(OBJ) $(D_FILES)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : NONE all clean fclean re
