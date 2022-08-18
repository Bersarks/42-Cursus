NAME = libft.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
SRC =	ft_strjoin.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_split.c \
		ft_substr.c \
		ft_strlcpy.c \
		ft_memcpy.c \
		get_next_line.c \

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	ar -rcs $(NAME) $(OBJECTS)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJECTS): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	$(RM) $(OBJECTS)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
