#include "philo_one.h"

static void				ft_sleeping(int n)
{
	unsigned long start;
	unsigned long passed;

	start = get_time();
	while (42)
	{
		passed = get_time() - start;
		if (passed >= (unsigned long)n)
			break ;
		usleep(200);
	}
}

int     try_fork(t_philo *philo)
{
	t_global *gl;

	gl = get_gl();
	if(sem_wait(gl->sem->forks) == -1)
		write(1, "Error sem_wait\n", 15);
	print_state(philo, TAKE_FORK);
	if(sem_wait(gl->sem->forks) == -1)
		write(1, "Error sem_wait\n", 15);	
	print_state(philo, TAKE_FORK);
	philo->last_eat = get_time();
	print_state(philo, EATING);
	ft_sleeping(gl->times->t_to_eat);
	if (sem_post(gl->sem->forks) == -1)
		write(1, "Error sem_post\n", 15);
	if (sem_post(gl->sem->forks) == -1)
		write(1, "Error sem_post\n", 15);
	return (1);
}

void    *live(void *args)
{
    t_global *gl;
	t_philo *philo;

    gl = get_gl();
	philo = (t_philo*)args;
    while (42)
    {
        print_state(philo, THINKING);
		try_fork(philo);
		if (gl->times->nb_eat && ++philo->nb_eat == gl->times->nb_eat)
			break ;
		print_state(philo, SLEEPING);
		ft_sleeping(gl->times->t_to_sleep);
    }
	gl->nb_philo--;
	return (NULL);
}

void	*check(void *args)
{
	t_global *gl;
	t_philo *philo;

	gl = get_gl();
	philo = (t_philo*)args;
	while (42)
	{
		if (get_time() - philo->last_eat > gl->times->t_to_die && gl->alive)
		{
			gl->alive= 0;
			print_state(philo, DIED);
			free_gl(gl);
			break ;
		}
		ft_sleeping(5);
	}
	return (NULL);
}