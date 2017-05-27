NAME		=	ft_retro
INC			=	-I include
CFLAGS		=	-Wall -Wextra -Werror -g3 -lpanel -lncurses $(INC)
CC			=	clang++
LD			=	clang++

INCLUDE		=	$(shell find include -name "*.hpp")
SRC			=	$(shell find src -name "*.cpp")
OBJ			=	$(SRC:src/%.c=build/%.o)

all: ft_retro

build/%.o: src/%.c $(INCLUDE)
	@echo "\033[92m    CC    $@\033[0m"
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

ft_retro: $(OBJ)
	@echo "\033[92m    LD    $(NAME)\033[0m"
	$(LD) $^ $(CFLAGS) -o $(NAME)


clean:
	@echo "\033[92m    RM    object files\033[0m"
	@rm -rf build

fclean: clean
	@echo "\033[92m    RM    $(NAME)\033[0m"
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM

re: fclean all