NAME = fillit

$(NAME):
		make -C libft/
		gcc -Wall -Wextra -Werror -I fillit/ -c fillit/validation.c fillit/tetriminos.c fillit/coordination.c fillit/map.c fillit/main.c
		gcc validation.o tetriminos.o coordination.o map.o main.o -L libft/ -lft -o $(NAME)

clean:
		make -C libft/ clean
		rm -f validation.o tetriminos.o coordination.o map.o main.o

fclean:
		clean
		make -C libft/ fclean
		rm -f $(NAME)
