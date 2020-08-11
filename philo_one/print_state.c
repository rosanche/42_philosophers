#include "philo_one.h"

char       *get_status(t_state etat)
{
    if (etat == TAKE_FORK)
        return (" has taken a fork\n");
    else if (etat == THINKING)
        return (" is thinking\n");
    else if (etat == EATING)
        return (" is eating\n");
    // else if (etat === HUNGRY)
    //     return (" is thinking");
    else if (etat == SLEEPING)
        return (" is sleeping\n");
    else if (etat == DIED)
        return (" died\n");
    return (NULL);
}

void       print_state(t_philo *philo, t_state etat)
{
    char *str;
    char *tmp;
    char *time;
    char *phi;

    time = ft_itoa(get_time() - philo->start);
    phi = " philo ";
    tmp = ft_strjoin(time, phi);
    str = ft_strjoin(tmp, get_status(etat));
    free(tmp);
    write(1, str, ft_strlen(str));
}