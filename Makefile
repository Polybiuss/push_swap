NAME = push_swap
BONUS_NAME = checker
SOURCES = push_swap.c \
	create_list.c \
	checker_swap.c \
	parsing.c \
	utils.c \
	swap.c \
	push.c \
	rotate.c \
	reverse_rotate.c \
	testing.c \
	sorting.c \
	chunk.c \
	chunk_2.c \
	chunk_3.c \
	push_chunk.c \
	push_sorted_chunk.c \
	push_to_queue.c \
	create_struct.c \
	sort_low_num.c \
	cmd_low_num.c \

SOURCES_BONUS = checker.c \
	parsing.c \
	checker_swap.c \
	create_list.c \
	utils.c \
	checker_swap1.c \
	checker_push.c \
	checker_rotate.c \
	checker_reverse_rotate.c \
	testing.c \
	checker_read.c \
	get_next_line.c \

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft.a

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(NAME)

bonus : $(OBJECTS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(BONUS_NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re : fclean all

.PHONY : all clean fclean re