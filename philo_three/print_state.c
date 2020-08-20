#include "philo_three.h"

char       *get_status(t_state etat)
{
    if (etat == TAKE_FORK)
        return (" has taken a fork\n");
    else if (etat == THINKING)
        return (" is thinking\n");
    else if (etat == EATING)
        return (" is eating\n");
    else if (etat == TAKE_FORK)
        return (" has taken a fork");
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
    char *index;

    time = ft_itoa(get_time() - philo->start);
    phi = " philo ";
    tmp = ft_strjoin(time, phi);
    index = ft_itoa(philo->index + 1);
    str = ft_strjoin(tmp, index);
    free(time);
    free(index);
    free(tmp);
    tmp = ft_strjoin(str, get_status(etat));
    free(str);
    write(1, tmp, ft_strlen(tmp));
    free(tmp);
}