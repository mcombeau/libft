# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcombeau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 13:48:30 by mcombeau          #+#    #+#              #
#    Updated: 2021/12/03 13:58:37 by mcombeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
LIBFT_PATH = "../"

$(NAME): make_libft
	$(CC) $(CFLAGS) -o $(NAME) $(LIBFT_PATH)*.o main.c

make_libft:
	make bonus -C $(LIBFT_PATH)

all: $(NAME)


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
