CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = RPN
OBJ_DIR = .obj

SRC_FILES = main.cpp RPN.cpp
OBJECTS = $(SRC_FILES:%.cpp=$(OBJ_DIR)/%.o)

NO_COLOR = \033[0m
RED = \033[31m
GREEN = \033[32;5m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36;5m

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CPPFLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)Object files created!$(NO_COLOR)"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning...$(NO_COLOR)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Full Cleaning...$(NO_COLOR)"
	@	rm -rf $(OBJ_DIR) $(NAME)

re: fclean all

.PHONY: all clean fclean re