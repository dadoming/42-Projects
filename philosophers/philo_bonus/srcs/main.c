#include "../header/philo_bonus.h"

t_table *table(void)
{
    static t_table table;

    return (&table);
}

int main(int argc, char **argv)
{
    t_philo philo[200];

    if (check_input(argc, argv) == TRUE)
        return (1);
    if (init_program(argc, argv, philo) == TRUE)
        return (2);
    start_program(philo);
    destroy(philo);
    return (0);
}   