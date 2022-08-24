#include "../header/philo.h"

// Check and load input function
int check_and_load(t_philo *p, int argc, char **argv)
{
    if(argc < 5 || argc > 6)
    {
        err_msg("Wrong number of arguments");
        return (free_mem(p));
    }
    if(check_if_is_number(argv) != 0)
    {
        err_msg("Wrong input");
        return (free_mem(p));
    }
    if(load_args(p, argc, argv) != 0)
    {
        err_msg("Error in your numbers");
        return (free_mem(p));
    }
    return (0);
}

// Load input values
int load_args(t_philo *p, int argc, char **argv)
{
    p->rules = malloc(sizeof(t_rules));
    p->rules->nr_philo = ft_atoi(argv[1]);
    p->rules->time_to_die = ft_atoi(argv[2]);
    p->rules->time_to_eat = ft_atoi(argv[3]);
    p->rules->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        p->rules->x_eats = ft_atoi(argv[5]);
    else 
        p->rules->x_eats = 0;
    if (p->rules->nr_philo < 2 || p->rules->time_to_die < 0 
            || p->rules->time_to_eat < 0 || p->rules->time_to_sleep < 0 
            || p->rules->x_eats < 0)
        return (1);
    return(0);
}

