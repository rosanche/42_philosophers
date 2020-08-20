#include "philo_three.h"

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
        if (!(gl->philos[i].living = fork()))
            live(&gl->philos[i]);
        i++;
    }
    return (1);
}

int watch()
{
    int i;
	int status;
    t_global *gl;

    gl = get_gl();
    launch();
	status = 0;
	i = 0;
    while (waitpid(-1, &status, 0) > 0)
	{
        printf("CACACA: %d\n", gl->alive);
		if (WIFEXITED(status) && (status == 512 || status == 768))
		{
            printf("CACACA: %d\n", gl->alive);
            gl->alive = 0;
            // if(sem_wait(gl->sem->die_eat) == -1)
			// 	write(1, "Error sem_wait\n", 15);
			while (i < gl->times->nb_ph)
            {
				kill(gl->philos[i].living, SIGINT);
                i++;
            }
            // if(sem_post(gl->sem->die_eat) == -1)
			//     write(1, "Error sem_post\n", 15);
			return (2);
		}
		else if (WIFEXITED(status) && status == 256)
		{
			gl->nb_philo--;
			if (gl->nb_philo == 0)
				return (1);
		}
	}
	return (0);
}

int print_error(char *str)
{
    write(1, str, ft_strlen(str));
    return (0);
}

int main(int ac, char **av)
{
    t_global *global;
    int ret;

    if (ac < 5 || ac > 6)
        return (print_error("Wrong number of arguments !"));
    if (!(global = init_global(av)))
        return (0);
    if (!(ret = watch()))
        return (0);
    printf("MERDEEE: %d\n", global->alive);
    free_gl(global);
    if (ret == 2)
        return (0);
    write(1, "They all have eaten enough\n", 27);
    return (1);
}