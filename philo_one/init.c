#include "philo_one.h"

t_philo *init_philos(int nb_philos)
{
    t_philo *philos;
    t_global *gl;
    int i;

    i = 0;
    gl = get_gl();
    gl->nb_philo = gl->times->nb_ph;
    gl->alive = 1;
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
    if (av[5])
        times->nb_eat = ft_atoi(av[5]);
    return (times);
}

t_mut       *init_mut(int nb_philos)
{
    t_mut   *mut;
    int i;

    i = 0;
    if (!(mut = (t_mut *)malloc(sizeof(t_mut))))
        return (NULL);
    if (!(mut->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (nb_philos + 1))))
        return (NULL);
    if (!(mut->die_eat = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nb_philos)))
        return (NULL);
    while (++i < nb_philos)
        if (pthread_mutex_init(&mut->forks[i], NULL) || pthread_mutex_init(&mut->die_eat[i], NULL))
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

    global = get_gl();
    global->times = init_times(av);
    global->philos = init_philos(global->times->nb_ph);
    global->mut = init_mut(global->times->nb_ph);
    return (global);
}
