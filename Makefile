NAME = push_swap
BONUS_NAME = checker
LIB = libft.a
LIBFT_DIR = libft
OBJ_DIR = obj
SRC_CHECK = checker_bonus
SRC_CHUNK = chunk
SRC_CMD = cmd
SRC_CMD_CHECKER = cmd_checker
SRC_PARS = parsing
SRC_SORT = sort
SRC = push_swap.c \
	$(SRC_PARS)/parsing.c \
	$(SRC_PARS)/testing.c \
	$(SRC_PARS)/utils.c \
	$(SRC_PARS)/create_list.c \
	$(SRC_CMD)/push.c \
	$(SRC_CMD)/rotate.c \
	$(SRC_CMD)/swap.c \
	$(SRC_CMD)/reverse_rotate.c \
	$(SRC_SORT)/cmd_low_num.c \
	$(SRC_SORT)/sorting.c \
	$(SRC_SORT)/push_to_queue.c \
	$(SRC_SORT)/create_struct.c \
	$(SRC_SORT)/sort_low_num.c \
	$(SRC_CHUNK)/chunk.c \
	$(SRC_CHUNK)/chunk_2.c \
	$(SRC_CHUNK)/chunk_3.c \
	$(SRC_CHUNK)/push_chunk.c \
	$(SRC_CHUNK)/push_sorted_chunk.c \
	$(SRC_CHECK)/checker_swap.c \

SRC_BONUS = $(SRC_CHECK)/checker.c \
	$(SRC_PARS)/parsing.c \
	$(SRC_PARS)/testing.c \
	$(SRC_PARS)/utils.c \
	$(SRC_PARS)/create_list.c \
	$(SRC_CHECK)/checker_swap.c \
	$(SRC_CHECK)/checker_read.c \
	$(SRC_CMD_CHECKER)/checker_push.c \
	$(SRC_CMD_CHECKER)/checker_swap1.c \
	$(SRC_CMD_CHECKER)/checker_rotate.c \
	$(SRC_CMD_CHECKER)/checker_reverse_rotate.c \

OBJECTS = $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJECTS_BONUS = $(SRC_BONUS:%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
GREEN = \033[0;32m
CYAN = \033[0;36m
RESET = \033[0m
GRAY = \033[90m

SUCCESS = $(GREEN)[SUCCESS]$(RESET)
INFO = $(CYAN)[INFO]$(RESET)


all : $(NAME)

$(OBJ_DIR):
	@if [ ! -d ./$(OBJ_DIR) ]; then \
		echo "$(INFO) Creating $(OBJ_DIR) directory..."; \
		echo "$(GRAY) mkdir -p $(OBJ_DIR)"; \
		mkdir -p $(OBJ_DIR); \
	fi

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR) $(LIB)
	@echo "$(INFO) Compiling $<...$(GRAY)"
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(SUCCESS) Compilation $< done!"

$(LIB):
	@if [ -d ./$(LIBFT_DIR) ]; then \
		echo "$(INFO) $(LIBFT_DIR) && git pull"; \
		cd $(LIBFT_DIR) && git pull && cd ..; \
	else \
		echo "$(INFO) git clone Polybft in directory libft"; \
		git clone https://github.com/Polybiuss/libft.git $(LIBFT_DIR); \
	fi
	echo "$(INFO) Make $(LIB)..$(GRAY)"
	make -C $(LIBFT_DIR)
	echo "$(SUCCESS) Make done!"

$(NAME): $(OBJECTS)
	@echo "$(INFO) Compiling to make $(NAME)...$(GRAY)"
	$(CC) $(CFLAGS) $^ $(LIBFT_DIR)/$(LIB) -o $(NAME)
	@echo "$(SUCCESS) $(NAME) created!"

bonus : $(OBJECTS_BONUS)
	@echo "$(INFO) Compiling to make $(BONUS_NAME)...$(GRAY)"
	$(CC) $(CFLAGS) $^ $(LIBFT_DIR)/$(LIB) -o $(BONUS_NAME)
	@echo "$(SUCCESS) $(BONUS_NAME) created!"

clean :
	@echo "$(INFO) Remove all files.o...$(GRAY)"
	rm -rf $(OBJ_DIR)
	rm -rf $(OBJ_BONUS_DIR)
	cd $(LIBFT_DIR) && make clean && cd ..
	@echo "$(SUCCESS) Remove done!"
	
fclean : clean
	@echo "$(INFO) Deleting $(NAME), $(BONUS_NAME) and $(LIB)..$(GRAY)"
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)/$(LIB)
	rm -f $(BONUS_NAME)
	@echo "$(SUCCESS) Delete done!"

re : fclean all

.PHONY: all clean fclean re