#include "philo_one.h"

static void				ft_sleeping(int n)
{
	unsigned long start;
	unsigned long passed;

	start = get_time();
	while (1)
	{
		passed = get_time() - start;
		if (passed > (unsigned long)n)
			break ;
		usleep(1);
	}
}

int     try_fork(t_philo *philo)
{
	t_global *gl;

	gl = get_gl();
	pthread_mutex_lock(&gl->mut->forks[philo->index]);
	pthread_mutex_lock(&gl->mut->forks[(philo->index + 1) % gl->times->nb_ph]);
	print_state(philo, EATING);
	philo->last_eat = get_time();
	ft_sleeping(gl->times->t_to_eat);
	pthread_mutex_unlock(&gl->mut->forks[philo->index]);
	pthread_mutex_unlock(&gl->mut->forks[(philo->index + 1) % gl->times->nb_ph]);
	return (1);
}

void    live(t_philo *philo)
{
    t_global *gl;

    gl = get_gl();
    while (42)
    {
        print_state(philo, THINKING);
		try_fork(philo);
		if (gl->times->nb_eat && ++philo->nb_eat == gl->times->nb_eat)
			break ;
		print_state(philo, SLEEPING);
		ft_sleeping(gl->times->t_to_sleep);
    }
	return (NULL);
}