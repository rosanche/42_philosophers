NAME=philo_two

CC=gcc -Wall -Wextra -Werror $(PHILO_TWO_H) -g3

PHILO_TWO_H = -I philo_two.h

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