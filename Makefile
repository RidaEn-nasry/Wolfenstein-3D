NAME = wolf3d

MNDTR_PATH = ./srcs/mandatory
SRCS = $(MNDTR_PATH)/errors/validate_map.c\
		$(MNDTR_PATH)/errors/exit_free_if.c\
		$(MNDTR_PATH)/parser/parser_utils.c\
		$(MNDTR_PATH)/parser/parser.c\
		$(MNDTR_PATH)/renderer/renderer.c\
		$(MNDTR_PATH)/renderer/render_map.c\
		$(MNDTR_PATH)/renderer/math_utils.c\
		$(MNDTR_PATH)/renderer/init.c\
		$(MNDTR_PATH)/renderer/mlx_utils.c\
		$(MNDTR_PATH)/renderer/shape_drawers.c\
		$(MNDTR_PATH)/renderer/game_drawers.c\
		$(MNDTR_PATH)/renderer/moves.c\
		$(MNDTR_PATH)/renderer/casting.c\
		$(MNDTR_PATH)/renderer/utils.c	

RM = rm -rf
CC = gcc
#CFLAGS = -Wall -Wextra -Werror -g  -mmacosx-version-min=10.15 -arch arm64
CFLAGS = -Wall -Wextra -Werror -g 
OBJS = $(SRCS:.c=.o)
INCS = -I$(MNDTR_PATH)/includes/ -I./srcs/utils/libft/
INCLDS = $(MNDTR_PATH)/includes/parser.h $(MNDTR_PATH)/includes/errors.h $(MNDTR_PATH)/includes/renderer.h 
LIBFT_PATH = ./srcs/utils/libft/
MINLBX_PATH = ./srcs/utils/minilibx/


MLX = -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
#MLX = $(wildcard $(MINLBX_PATH)*)
MLX_INC = -I/usr/local/include/
%.o: %.c $(INCLDS)
	$(CC) $(CFLAGS) $(INCS) $(MLX_INC) -c $< -o $@


$(NAME): $(OBJS) $(INCLDS)
	$(MAKE) -C $(LIBFT_PATH)
	$(MAKE) -C $(MINLBX_PATH)
	$(CC) $(OBJS) $(LIBFT_PATH)/libft.a $(MLX) -o  $@

run: $(NAME)
	./$(NAME) ./resources/maps/map.cub

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MINLBX_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT_PATH)/libft.a
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re 

