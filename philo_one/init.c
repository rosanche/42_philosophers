#include "philo_one.h"

t_philo *init_philos(int nb_philos)
{
    t_philo *philos;
    int i;

    i = 0;
    if (!(philos = (t_philo*)malloc(sizeof(t_philo) * nb_philos)))
        return (NULL);
    while (i < nb_philos)
    {
        philos[i].index = i;
        philos[i].nb_eat = 0;
        philos[i].start = get_time();
        philos[i].last_eat = get_time();
        i++;
    }
    return (philos);
}

t_to    *init_times(char **av)
{
    t_to *times;

    if (!(times = (t_to *)malloc(sizeof(t_to))))
        return (NULL);
    times->nb_ph = ft_atoi(av[1]);
    times->t_to_die = ft_atoi(av[2]);
    times->t_to_eat = ft_atoi(av[3]);
    times->t_to_sleep = ft_atoi(av[4]);
    return (times);
}

t_mut       *init_mut(int nb_philos)
{
    t_mut   *mut;
    int i;

    i = -1;
    if (!(mut = (t_mut *)malloc(sizeof(t_mut))))
        return (NULL);
    if (!(mut->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nb_philos)))
        return (NULL);
    while (++i < nb_philos)
        if (pthread_mutex_init(&mut->forks[i], NULL))
            return (NULL);
    return (mut);
}

t_global		*get_gl(void)
{
	static t_global gl;

	return (&gl);
}

t_global    *init_global(char **av)
{
    t_global *global;

    // if (!(global = (t_global *)malloc(sizeof(t_global))))
    //     return (NULL);
    global = get_gl();
    global->times = init_times(av);
    global->philos = init_philos(global->times->nb_ph);
    global->mut = init_mut(global->times->nb_ph);
    return (global);
}