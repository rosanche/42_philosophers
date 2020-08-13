NAME=philo_one

CC=gcc -Wall -Wextra -Werror $(PHILO_ONE_H) -g3

PHILO_ONE_H = -I philo_one.h

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