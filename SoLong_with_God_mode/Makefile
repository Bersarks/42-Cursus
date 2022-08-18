# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otokluog <otokluog@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 11:00:57 by otokluog          #+#    #+#              #
#    Updated: 2022/06/09 17:37:19 by otokluog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = map_check.c mapread.c so_long.c init.c draw.c so_play.c game_update.c exit_game.c

FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a
FT_PRINTF_PATH = ./src/libraries/ft_printf
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_PATH = ./src/libraries/libft

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror
LINKS = -lmlx -framework OpenGL -framework AppKit -L./src/libraries/mlx -L./src/libraries/libft

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)
$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_PATH)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) $(LINKS) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@rm $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     Deleted object files" $(NONE)

$(OBJ): $(SRC) $(LIBFT) $(FT_PRINTF)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) -c $(SRC)

exe: all
	@echo "     - Executing $(NAME)... \n"
	@./$(NAME)
	@echo "\n     - Done -"
clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(FT_PRINTF_PATH) fclean

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(FT_PRINTF_PATH) fclean

re: fclean all
