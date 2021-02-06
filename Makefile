# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saugustu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 18:08:32 by saugustu          #+#    #+#              #
#    Updated: 2021/01/26 00:10:21 by saugustu         ###   ########.fr        #
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

all :
	$(MAKE) $(NAME) -j 4

$(NAME) : $(OBJ) $(LIB) 
	cp $(LIB) $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	gcc $(FLAGS) $(OPTFLAGS) -c $< -o $@ -MD

$(LIB) : NONE
	$(MAKE) -C $(LIB_PATH)

include $(wildcard $(D_FILES))

clean :
	rm -f $(OBJ) $(D_FILES)
	$(MAKE) clean -C $(LIB_PATH)

fclean : clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIB_PATH)

re : fclean all

.PHONY : NONE all clean fclean re
