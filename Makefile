NAME=minishell

<<<<<<< HEAD
SRCS= minishell.c parser.c dollar_parse.c arg_parse.c
CFLAGS=-Wall -Wextra -Werror
=======
SRCS= minishell.c parser.c dollar_parse.c arg_parse.c arg_parse2.c execute.c
CFLAGS=-g
>>>>>>> main
LIBFT=libft/libft.a

all: $(NAME)

$(NAME): $(SRCS) 
	make -C ./libft -s
	gcc -g   -o  $(NAME)  $(CFLAGS) $(SRCS) -lreadline -lncurses $(LIBFT)

clean:
	make clean -C ./libft -s

fclean: clean
	make fclean -C ./libft -s
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re