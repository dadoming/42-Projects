#include "../includes/philo_bonus.h"

void init_shared()
{
    table()->time_start = get_timestamp();
    table()->died = 0;
    table()->ate_all = 0;
}

philo_t *init_philos(philo_t *p)
{
    int i;

    p = malloc(sizeof(philo_t) * table()->rules.nr_philo);
    if(!p)
        return (NULL);
    i = 0;
    while (i < table()->rules.nr_philo)
    {
        memset(&p[i], 0, sizeof(philo_t));
        p[i].index = i;
        p[i].table = table();
        i++;
    }
    return (p);
}

int load_args(int argc, char **argv)
{
    table()->rules.nr_philo = ft_atoi(argv[1]);
    table()->rules.time_to_die = ft_atoi(argv[2]);
    table()->rules.time_to_eat = ft_atoi(argv[3]);
    table()->rules.time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        table()->rules.x_eats = ft_atoi(argv[5]);
    if (table()->rules.nr_philo < 1 || table()->rules.nr_philo > 200 
            || table()->rules.time_to_die <= 0   || table()->rules.time_to_eat <= 0 
            || table()->rules.time_to_sleep <= 0 || table()->rules.x_eats < 0)
        return (1);
    if(argc == 5)
        table()->rules.x_eats = -1;
    return 0;
}

int parse_and_init(int argc, char** argv)
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
    if(load_args(argc, argv) != 0)
    {
        err_msg("Error in your numbers");
        return (3);
    }
    return (0);
}