NAME = wolfenstein3d

MNDTR_PATH = ./srcs/mandatory
SRCS = $(MNDTR_PATH)/errors/validate_map.c\
		$(MNDTR_PATH)/errors/exit_free_if.c\
		$(MNDTR_PATH)/parser/parser_utils.c 

RM = rm -rf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
OBJS = $(SRCS:.c=.o)
INCS = -I$(MNDTR_PATH)/includes/ -I./srcs/utils/libft/
INCLDS = $(MNDTR_PATH)/includes/parser.h $(MNDTR_PATH)/includes/errors.h $(MNDTR_PATH)/includes/renderer.h 
LIBFT_PATH = ./srcs/utils/libft/

%.o: %.c 
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@


$(NAME): $(OBJS) $(INCLDS)
	$(MAKE) -C $(LIBFT_PATH)  
	$(CC) $(OBJS) $(LIBFT_PATH)/libft.a -o  $@



clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT_PATH)/libft.a
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re 

