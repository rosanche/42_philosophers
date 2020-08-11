#include "philo_one.h"



int main(int ac, char **av)
{
    t_global *global;

    // global = NULL;
    if (ac > 4 && ac < 7) 
    {;
        global = init_global(av);
        print_state(global->philos[0], THINKING);
    }
    printf("time: %ld", get_time());
}