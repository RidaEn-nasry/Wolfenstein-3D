# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 15:56:34 by ren-nasr          #+#    #+#              #
#    Updated: 2022/07/26 22:39:02 by mkarim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

BONUS_PATH = ./bonus/
MNDTR_PATH = ./mandatory/

all: $(MNDTR_PATH)
	$(MAKE) -C $(MNDTR_PATH)

bonus:
	$(MAKE) -C $(BONUS_PATH)

clean:
	$(MAKE) -C $(MNDTR_PATH) clean
	$(MAKE) -C $(BONUS_PATH) clean
	
fclean: clean
	$(MAKE) -C $(MNDTR_PATH) fclean
	$(MAKE) -C $(BONUS_PATH) fclean

re: fclean all 

.PHONY: clean fclean re bonus