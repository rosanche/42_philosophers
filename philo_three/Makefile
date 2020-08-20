NAME=philo_three

CC=gcc -Wall -Wextra -Werror $(philo_three_H) -g3

philo_three_H = -I philo_three.h

RM=rm -f

SRC= ft_utils.c\
ft_utils2.c\
init.c\
main.c\
print_state.c\
threads.c \

OBJ=$(SRC:.c=.o)

%.o: %.c
	$(CC) -c $< -o $@ 

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
.PHONY: clean, fclean