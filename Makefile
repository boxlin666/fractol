# **************************************************************************** #
#                               Project Setup                                  #
# **************************************************************************** #

NAME        = fractol
SRC_DIR     = src
SRC         = $(addprefix $(SRC_DIR)/, main.c init_data.c mlx_window.c utils.c mandelbrot.c julia.c tricorn.c ft_lib.c)
OBJ         = $(SRC:.c=.o)
DEP         = $(OBJ:.o=.d)

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -Ilibft -Iminilibx-linux -Iinclude -MMD -MP

# **************************************************************************** #
#                               Library Setup                                  #
# **************************************************************************** #

# MinilibX
MLX_DIR     = minilibx-linux
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# libft
LIBFT_DIR   = libft
LIBFT_LIB   = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

# **************************************************************************** #
#                                    Rules                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ) $(MLX_LIB) $(LIBFT_LIB)
	$(CC) $(OBJ) $(CFLAGS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

-include $(DEP)

# **************************************************************************** #
#                                   Cleaning                                   #
# **************************************************************************** #

clean:
	rm -f $(OBJ) $(DEP)
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
