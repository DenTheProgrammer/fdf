NAME = a.out

SRCS = ft_brezen.c

OBJS = $(SRCS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) -I /Users/ashari/Desktop/FdF/minilibx	$(SRCS) -L /Users/ashari/Desktop/FdF/minilibx -lmlx -framework	OpenGL -framework AppKit

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
