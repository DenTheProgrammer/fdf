NAME = fillit

SRCS = ft_arrncpy.c ft_backtr.c \
ft_error_msg.c ft_find_coordinate.c ft_is_map_valid.c \
ft_is_tetramino_valid.c ft_list_del.c ft_list_delone.c \
ft_list_new.c ft_list_pushback.c ft_list_size.c \
ft_map_create.c ft_map_reader.c \
ft_print_map.c ft_solver.c ft_usage_file.c main.c \
ft_sqrt.c ft_strdel.c ft_strndup.c ft_memset.c \
ft_strnew.c

OBJS = $(SRCS:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJS)
	@$(CC) -o $(NAME) $(OBJS)

%.o: srcs/%.c $(HEADER)
	@$(CC) $(FLAGS) -c $<

%.o: srcs/%.c
	@$(CC) $(FLAGS) -I header.h -o $@ -c $<

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
