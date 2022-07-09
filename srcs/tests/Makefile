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


LBFT_SRCS = ../mandatory/utils/libft.a
LBFT_INCS = ../mandatory/utils/libft.h


OBJS = $(SRCS:.c=.o)

%.o: %.c
	gcc -c catch.hh $< -o $@

$(NAME): $(OBJS) 
	gcc catch.hh $(LBFT_INCS) -o $@ $(OBJS) $(LBFT_SRCS)

clean : 
	rm -f $(OBJS)

fclean: clean
	rm -fr $(NAME)

re: fclean $(NAME)


.PHONY: $(NAME) clean fclean re 
