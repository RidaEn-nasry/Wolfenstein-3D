NAME = wolfenstein3d

SRCS = ./errors/validate_map.c\
		./errors/exit_free_if.c\
		./parser/parser_utils.c 

RM = rm -rf
CC = gcc 
CFLAGS = -Wall -Wextra -Werror -g
OBJS = $(SRCS:.c=.o)
INCS = -I./includes/ -I../utils/libft/
INCLDS = ./includes/parser.h ./includes/errors.h ./includes/renderer.h 
LIBFT_PATH = ../utils/libft/
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

