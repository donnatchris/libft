#############################################################
## ARGUMENTS

NAME			= libft.a
CFLAGS			= -Wall -Wextra -Werror
CC				= gcc
INCLUDES		= -I includes/

#############################################################
## SOURCES

SRC_FILES		= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OBJ_FILES		= $(SRC_FILES:.c=.o)

#############################################################
## RULES

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
