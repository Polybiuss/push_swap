NAME = push_swap
SOURCES = push_swap.c \
	create_list.c \
	checker.c \
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

OBJECTS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft.a

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re