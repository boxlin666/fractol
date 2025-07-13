# **************************************************************************** #
#                               MAKEFILE CONFIG                                #
# **************************************************************************** #

NAME        = fractol
SRC_DIR    := src
SRC         = $(addprefix $(SRC_DIR)/, main.c init_data.c mlx_window.c utils.c mandelbrot.c julia.c tricorn.c ft_lib.c)
OBJ         = $(SRC:.c=.o)
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -Ilibft -Imlx -Iinclude

# MinilibX config
MLX_DIR     = mlx
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_INC     = -I $(MLX_DIR)
MLX_FLAGS   = -L $(MLX_DIR) -lmlx -lXext -lX11 -lm

# libft config
LIBFT_DIR     = libft
LIBFT_LIB     = $(LIBFT_DIR)/libft.a
LIBFT_INC     = -I $(LIBFT_DIR)
LIBFT_FLAGS   = -L $(LIBFT_DIR) -lft

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ) $(MLX_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_INC) $(LIBFT_INC) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean


re: fclean all

.PHONY: all clean fclean re $(NAME)
