#include "../header/philo.h"

// Check and load input function
int check_and_load(t_philo *p, int argc, char **argv)
{
    if(check_args(argc, argv) != 0)
    {
        if(p)
            free(p);
        return (1);
    }
    if(load_args(p, argc, argv) != 0)
    {
        if(p)
            free(p);
        err_msg("Error in your numbers");
        return (2);
    }
    return (0);
}

// Checks input
int check_args(int argc, char **argv)
{
    if(argc < 5 || argc > 6)
    {
        err_msg("Wrong number of arguments");
        return (1);
    }
    if(check_if_is_number(argv) != 0)
    {
        err_msg("Wrong input");
        return (2);
    }
    return (0);
}

// Load input values
int load_args(t_philo *p, int argc, char **argv)
{
    p->condition = malloc(sizeof(t_cond));
    p->condition->nr_philo = ft_atoi(argv[1]);
    p->condition->time_to_die = ft_atoi(argv[2]);
    p->condition->time_to_eat = ft_atoi(argv[3]);
    p->condition->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        p->condition->x_eats = ft_atoi(argv[5]);
    else 
        p->condition->x_eats = 0;
    if (p->condition->nr_philo < 2 || p->condition->time_to_die < 0 
            || p->condition->time_to_eat < 0 || p->condition->time_to_sleep < 0 
            || p->condition->x_eats < 0)
        return (1);
    return(0);
}

