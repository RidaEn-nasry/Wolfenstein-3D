NAME = cub3d

BONUS_PATH = ./srcs/
SRCS = $(BONUS_PATH)/errors/validate_map.c\
		$(BONUS_PATH)/errors/exit_free_if.c\
		$(BONUS_PATH)/parser/parser_utils.c\
		$(BONUS_PATH)/parser/parser.c\
		$(BONUS_PATH)/renderer/renderer.c\
		$(BONUS_PATH)/renderer/render_map.c\
		$(BONUS_PATH)/renderer/math_utils.c\
		$(BONUS_PATH)/renderer/init.c\
		$(BONUS_PATH)/renderer/mlx_utils.c\
		$(BONUS_PATH)/renderer/shape_drawers.c\
		$(BONUS_PATH)/renderer/game_drawers.c\
		$(BONUS_PATH)/renderer/moves.c\
		$(BONUS_PATH)/renderer/moves1.c\
		$(BONUS_PATH)/renderer/casting.c\
		$(BONUS_PATH)/renderer/cast_calculate.c\
		$(BONUS_PATH)/renderer/cast_utils.c\
		$(BONUS_PATH)/renderer/cast_utils2.c\
		$(BONUS_PATH)/renderer/intersection.c\
		$(BONUS_PATH)/renderer/prj_calculate.c\
		$(BONUS_PATH)/renderer/project_3d.c\
		$(BONUS_PATH)/renderer/utils.c\
		$(BONUS_PATH)/renderer/animate.c\
		$(BONUS_PATH)/renderer/animate_utils.c\
		$(BONUS_PATH)/renderer/sounds.c\
		$(BONUS_PATH)/errors/validate_map1.c\
		$(BONUS_PATH)/errors/validate_map2.c


RM = rm -rf
CC = gcc
#CFLAGS = -Wall -Wextra -Werror -g  -mmacosx-version-min=10.15 -arch arm64
CFLAGS = -Wall -Wextra -Werror -g 
OBJS = $(SRCS:.c=.o)
INCS = -I$(BONUS_PATH)/includes/ -I./srcs/utils/libft/
INCLDS = $(BONUS_PATH)/includes/parser.h $(BONUS_PATH)/includes/errors.h $(BONUS_PATH)/includes/renderer.h 
LIBFT_PATH = ./srcs/utils/libft/
MINLBX_PATH = ./srcs/utils/minilibx/


MLX = -L$(MINLBX_PATH) -lmlx -framework OpenGL -framework AppKit
#MLX = $(wildcard $(MINLBX_PATH)*)
MLX_INC = -I$(MINLBX_PATH)/
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

