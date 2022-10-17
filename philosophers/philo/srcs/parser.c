#include "../header/philo.h"

// Init mutexes
void init_mutexes()
{
    int i;
    
    i = 0;
    while(i <= t()->rules.nr_philo)
    {
        pthread_mutex_init(&(t()->mutex.fork[i]), NULL);
        i++;
    }
    pthread_mutex_init(&(t()->mutex.write), NULL);
    pthread_mutex_init(&(t()->mutex.dead), NULL);
    pthread_mutex_init(&(t()->mutex.end), NULL);
}

// Init each philosopher's values
void init_philos(t_philo *p)
{
    int i;

    i = 1;
    while (i <= t()->rules.nr_philo)
    {
        memset(&p[i], 0, sizeof(t_philo));
        p[i].p_index = i;
        p[i].table = t();
        p[i].hand[LEFT] = i;
        p[i].hand[RIGHT] = i + 1;
        if(i == t()->rules.nr_philo)
            p[i].hand[RIGHT] = 1;
        i++;
    }
    p->x_eaten = 0;
    p->delta_death = t()->rules.time_to_die;
    t()->time_end = 0;
    t()->end = 0;
    t()->index_death = 0;
    t()->how_many_ate = 0;
}

// Check and load input function
int check_and_load(int argc, char **argv)
{
    if(argc < 5 || argc > 6)
    {
        err_msg("Wrong number of arguments");
        return (free_mem());
    }
    if(check_if_is_number(argv) != 0)
    {
        err_msg("Wrong input");
        return (free_mem());
    }
    if(load_args(argc, argv) != 0)
    {
        err_msg("Error in your numbers");
        return (free_mem());
    }
    return (0);
}

// Load input values
int load_args(int argc, char **argv)
{
    t()->rules.nr_philo = ft_atoi(argv[1]);
    t()->rules.time_to_die = ft_atoi(argv[2]);
    t()->rules.time_to_eat = ft_atoi(argv[3]);
    t()->rules.time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        t()->rules.x_eats = ft_atoi(argv[5]);
    if (t()->rules.nr_philo < 1 || t()->rules.nr_philo > 200 
            || t()->rules.time_to_die <= 0   || t()->rules.time_to_eat <= 0 
            || t()->rules.time_to_sleep <= 0 || t()->rules.x_eats < 0)
        return (1);
    if(argc == 5)
        t()->rules.x_eats = -1;
    return(0);
}

