#include "../header/philo.h"

int check_and_load(t_philo *philo, int argc, char **argv)
{
    if(check_args(argc, argv) != 0)
    {
        if(philo)
            free(philo);
        return (1);
    }
    if(load_args(philo, argc, argv) != 0)
    {
        if(philo)
            free(philo);
        err_msg("Error in your numbers");
        return (2);
    }
    return (0);
}

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

int load_args(t_philo *philo, int argc, char **argv)
{
    philo -> number_of_philosophers = ft_atoi(argv[1]);
    if (philo -> number_of_philosophers < 2) // Minimum 2 philosophers?
        return (1);
    philo->time_to_die = ft_atoi(argv[2]);
    if (philo -> time_to_die < 0)
        return (2);
    philo->time_to_eat = ft_atoi(argv[3]);
    if (philo -> time_to_eat < 0)
        return (3);
    philo->time_to_sleep = ft_atoi(argv[4]);
    if (philo -> time_to_sleep < 0)
        return (4);    
    if (argc == 6)
        philo -> number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
    else 
        philo -> number_of_times_each_philosopher_must_eat = 0;
    if (philo -> number_of_times_each_philosopher_must_eat < 0)
        return (5);
    return(0);
}

int check_if_is_number(char **str)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (str[i])
    {
        if(!((str[i][j] == '+' ) || (str[i][j] >= '0' && str[i][j] <= '9')))
            return (-1);
        j++;
        while (str[i][j] != '\0')
        {
            if (!(str[i][j] >= '0' && str[i][j] <= '9'))
                return (-1);
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}