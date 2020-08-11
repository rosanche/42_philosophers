#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum {
	THINKING, EATING, HUNGRY, SLEEPING, DIED, TAKE_FORK
}	t_state;

typedef struct s_to {
    unsigned long t_to_eat;
    unsigned long t_to_die;
    unsigned long t_to_sleep;
    int nb_ph;
    unsigned long nb_eat;
}               t_to;

typedef struct s_mut {
    pthread_mutex_t *forks;
}               t_mut;

typedef struct s_philo {
    int index;
    unsigned long start;
    int nb_eat;
    unsigned long last_eat;
    pthread_t *live;
    pthread_t *check
}               t_philo;

typedef struct s_global {
    t_to *times;
    t_philo *philos;
    t_mut   *mut;
}               t_global;


void       print_state(t_philo philo, t_state etat);

// Libft
unsigned long		get_time(void);
char				*ft_itoa(unsigned long n);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);
int			ft_atoi(const char *str);
char		*ft_strdup(const char *s1);
int			ft_len(unsigned long nb);

#endif