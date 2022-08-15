// Introduction to barriers
// barrier init takes the variable, (NULL attributes(for the sake of learning)), and the number of threads that it will have to wait for the barrier to let pass   

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

pthread_barrier_t barrier;

void *routine()
{
    while (1)
    {
        printf("Waiting at the barrier...\n");
        sleep(1);
        pthread_barrier_wait(&barrier);
        printf("We passed the barrier\n");
        sleep(1);
    }
}

int main(void)
{
    int nr_threads = 10;
    pthread_t t[nr_threads];
    int i = 0;
    pthread_barrier_init(&barrier, NULL, 7);
    while (i < nr_threads)
    {
        if(pthread_create(&t[i], NULL, routine, NULL) != 0)
            perror("Error creating thread");
        i++;
    }
    i = 0;
    while (i < nr_threads)
    {
        if(pthread_join(t[i], NULL) != 0)
            perror("Error joining thread");
        i++;
    }
    return 0;
}