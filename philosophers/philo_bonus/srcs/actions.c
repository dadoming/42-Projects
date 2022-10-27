#include "../header/philo_bonus.h"

void pick_forks(t_philo *p)
{
    sem_wait(table()->sem.forks);
    print_status(p, FORK, WHITE);
    sem_wait(table()->sem.forks);
    print_status(p, FORK, WHITE);
}

// Criar uma thread q checke se o philosopher do processo
//  dela está vivo. Se morrer, então matar o processo atual
//  e assim que matar o processo atual, matar todos os processos
//  fazer também um sem_post de forma a mais nenhum philosopher
//  printar depois da morte. A thread printa a morte.

static void drop_forks()
{
    sem_post(table()->sem.forks);
    sem_post(table()->sem.forks);
}

int eat(t_philo *p)
{
    if(p->is_dead == 1)
        return (TRUE);
    pick_forks(p);
    print_status(p, EAT, GREEN);
    action(table()->rules.time_eat);
    if(p->is_dead == 1)
        return (TRUE);
    p->delta_death = get_delta_t();
    if (table()->rules.max_eat > 0)
        p->times_eaten++;
    drop_forks(p);
    if((table()->rules.max_eat > 0 && \
        p->times_eaten >= table()->rules.max_eat) || \
        p->is_dead == 1)
        return (TRUE);
    return (FALSE);
}
