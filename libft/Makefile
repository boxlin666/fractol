# **************************************************************************** #
#                                Configuration                                 #
# **************************************************************************** #

NAME        := libft.a

CC          := gcc
CFLAGS      := -Wall -Wextra -Werror -MMD -MP -fPIC
AR          := ar rcs
RM          := rm -f

SRCS        := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			   ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
			   ft_memset.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
			   ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
			   ft_substr.c ft_tolower.c ft_toupper.c ft_putchar_fd.c ft_putendl_fd.c \
			   ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_itoa.c ft_striteri.c

OBJS        := $(SRCS:.c=.o)
DEPS        := $(OBJS:.o=.d)

BONUS_SRCS  := ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
			   ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
			   ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_OBJS  := $(BONUS_SRCS:.c=.o)
BONUS_DEPS  := $(BONUS_OBJS:.o=.d)

# **************************************************************************** #
#                                     Rules                                    #
# **************************************************************************** #

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

# 编译规则 + 自动依赖生成
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)
-include $(BONUS_DEPS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(DEPS) $(BONUS_DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
