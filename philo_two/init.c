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

t_sem       *init_sem(int nb_philos)
{
    t_sem   *sem;
    int i;
    t_global *global;

    global = get_gl();
    i = -1;
    if (!(sem = (t_sem *)malloc(sizeof(t_sem))))
        return (NULL);
    if (!(sem->forks = (sem_t *)malloc(sizeof(sem_t))))
        return (NULL);
    if (!(sem->forks = sem_open("sema", O_CREAT, 0666, global->nb_philo)))
        return (NULL);
    return (sem);
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
    global->sem = init_sem(global->times->nb_ph);
    return (global);
}

//proteger stdout avec semex 