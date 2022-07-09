

NAME = example
MINILIBX = ./srcs/utils/minilibx/ 
SRCS = example.c
OBJS = $(SRCS:.cpp=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I$(MINILIBX) -c $< -o $@

$(NAME):
	$(CC) $(OBJ) -L$(MINILIBX)  -l$(MINILIBX) -framework OpenGL -framework AppKit -o $(NAME)

	



