#include "../header/philo.h"

// What each philosopher will do

// Alterar a forma como o ponteiro para a mesa funciona,
//  principalmente as rules. E necessario cada philosopher
//  ter um ponteiro para a sua struct de rules.
// Nao pode simplesmente tar a olhar para a mesa e alterar os valores
//  por ai. Dai existir data race.
// Verificar melhor a questao de ter a lock order inversion.
void *routine(void* philosopher)
{
    t_philo *p; 
    pthread_t check_death;

    p = (t_philo*) philosopher;
    if(p->p_index % 2 == 0)
        usleep(60000);
    pthread_create(&check_death, NULL, check_, p);
    while (eat(p) && _sleep(p) && think(p))
    {
        continue;
    }
    pthread_detach(check_death);
    return (0);
}

int start(t_philo *p)
{
    pthread_t   ph_th[202];

    if(t()->rules.nr_philo == 1)
    {
        printf("%s0   %d   %s%s\n", WHITE, 1, FORK, RESET);
        t()->time_end = t()->rules.time_to_die + 1;
        t()->index_death = 1;
        t()->end = 1;
        usleep(1000 * t()->rules.time_to_die);
        return (0);
    }
    if(create_threads(ph_th, p) != 0)
        return (2);
    if(join_threads(ph_th) != 0)
        return (3);
    return (0);
}

int create_threads(pthread_t *th, t_philo *p)
{
    int i = 0;
    while (++i <= t()->rules.nr_philo)
    {
        if(pthread_create(&th[i - 1], NULL, routine, &p[i]) != 0)
        {
            printf("Error creating thread: %d\n", i);
            return (free_mem());
        }
    }
    return (0);
}

int join_threads(pthread_t *th)
{
    int i = 0;
    while (++i <= t()->rules.nr_philo)
    {
        if(pthread_join(th[i - 1], NULL) != 0)
        {
            printf("Error joining thread: %d\n", i);
            return (free_mem());
        }
    }
    return (0);
}