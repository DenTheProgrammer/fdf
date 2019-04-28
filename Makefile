NAME = fdf.out

SRCS = srcs/ft_brezen.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	cd srcs &&  cc $(FLAGS) ../srcs/*.c -I ../minilibx -L ../minilibx -lmlx -framework OpenGL -framework AppKit ../libft/libft.a -g -o $(NAME) && cd ..

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
