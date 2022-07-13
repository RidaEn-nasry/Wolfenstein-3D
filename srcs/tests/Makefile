# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ren-nasr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 20:26:20 by ren-nasr          #+#    #+#              #
#    Updated: 2022/07/09 20:35:39 by ren-nasr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = check
SRCS = ./parser_tests/valid_map_tests.c\
       	main.c

LBFT_ARCH = ../utils/libft/libft.a
CHECK_ARCH = /goinfre/ren-nasr/homebrew/Cellar/check/0.15.2/lib/libcheck.a
TESTS_OBJS = $(wildcard ../mandatory/errors/*.o) $(wildcard ../mandatory/parser/*.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCS = -I/goinfre/ren-nasr/homebrew/Cellar/check/0.15.2/include/ -I../utils/libft/ -I. -I../mandatory/includes/
OBJS = $(SRCS:.c=.o)

%.o: %.c 
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME): $(OBJS) 
	$(CC) -o $@ $(OBJS) $(CHECK_ARCH) $(LBFT_ARCH) $(TESTS_OBJS)

clean : 
	rm -f $(OBJS)

fclean: clean
	rm -fr $(NAME)

re: fclean $(NAME)

.PHONY: $(NAME) clean fclean re 
