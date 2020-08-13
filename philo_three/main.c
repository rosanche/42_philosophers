#include "philo_two.h"

void    free_gl(t_global *gl)
{
    sem_close(gl->sem->forks);
    sem_close(gl->sem->die_eat);
    free(gl->philos);
    free(gl->times);
    free(gl->sem);
}

int    launch()
{
    t_global *gl;

    gl = get_gl();
    int i = 0;
    while (i < gl->times->nb_ph)
    {
        if (!(gl->philos[i].living == fork()))
            live(&gl->philos[i]);
        i++;
    }
    return (1);
}

int print_error(char *str)
{
    write(1, str, ft_strlen(str));
    return (0);
}

int main(int ac, char **av)
{
    t_global *global;

    if (ac < 5 || ac > 6)
        return (print_error("Wrong number of arguments !"));
    if (!(global = init_global(av)))
        return (0);
    if (!launch())
        return (0);
    while (42)
    {
        if (!global->alive)
            return (0);
        if (!global->nb_philo)
            break ;
        usleep(200);
    }
    free_gl(global);
    write(1, "They all have eaten enough\n", 27);
    return (1);
}

// cntinue with waitpid
// !!!do the check of the arguments so there are no letters in it!!!