NAME	= minishell
SRCS	= src/main.c src/ft_scanf.c src/print_message.c \
			src/ft_run_command.c src/split.c src/setenv_func.c \
			src/echo_func.c src/error_message.c src/cat_func.c \
			src/unsetenv_func.c src/get_next_line.c src/getenv_func.c \
			src/expand_str.c src/cd_func.c src/run_man.c src/man_file1.c \
			src/run_info.c src/exec_cmd.c src/src1.c src/echo_src.c
OBJS	= $(SRCS:.c=.o)
FLAGS	= -Wall -Wextra -Werror -g -O0
HEADER	= includes/minishell.h

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@gcc $(OBJS) -o $(NAME) -L libft/ -lft

%.o: %.c $(HEADER)
	@cc -c $< -o $@ $(FLAGS)
	@echo  "█\c)"

clean:
	@make -C libft/ clean
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME) $(OBJS)

re: fclean $(NAME)
