NAME = minirt

SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), main.c render.c)

MLX42 = MLX42/build/libmlx42.a

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

CFLAGS = -I includes/ -I MLX42/include -I libft/includes

MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
MLXFLAGS_LINUX = -Iinclude -ldl -lglfw -pthread -lm


all: $(NAME)

$(NAME): $(OBJ_DIR) $(MLX42) $(OBJ)
	cc $(OBJ) MLX42/build/libmlx42.a $(CFLAGS) $(MLXFLAGS_LINUX) -o $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(MLX42):
	cmake MLX42/ -B MLX42/build && make -C MLX42/build -j4

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf MLX42/build

re: fclean all