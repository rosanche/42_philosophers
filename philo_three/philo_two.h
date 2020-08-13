#ifndef PHILO_TWO_H
# define PHILO_TWO_H

#include <pthread.h>
#include <fcntl.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

typedef enum {
	THINKING, EATING, HUNGRY, SLEEPING, DIED, TAKE_FORK
}	t_state;

typedef struct s_to {
    unsigned long t_to_eat;
    unsigned long t_to_die;
    unsigned long t_to_sleep;
    int nb_ph;
    int nb_eat;
}               t_to;

typedef struct s_sem {
    sem_t *forks;
    sem_t *die_eat;
}               t_sem;

typedef struct s_philo {
    int index;
    unsigned long start;
    int nb_eat;
    unsigned long last_eat;
    pthread_t   check;
    int         living;
}               t_philo;

typedef struct s_global {
    t_to *times;
    t_philo *philos;
    t_sem   *sem;
    int     nb_philo;
    int     alive;
}               t_global;


void       print_state(t_philo *philo, t_state etat);
void	*check(void *philo);
void    *live(void *philo);
int     try_fork(t_philo *philo);
t_global		*get_gl(void);
t_global    *init_global(char **av);
void    free_gl(t_global *gl);


// Libft
unsigned long		get_time(void);
char				*ft_itoa(unsigned long n);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);
int			ft_atoi(const char *str);
char		*ft_strdup(const char *s1);
int			ft_len(unsigned long nb);

#endif