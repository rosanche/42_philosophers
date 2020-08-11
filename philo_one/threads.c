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

int     try_fork()
{
    
}

void    live(t_philo philo)
{
    t_global *gl;

    gl = get_gl();
    while (42)
    {
        print_state(philo, THINKING);

    }
}