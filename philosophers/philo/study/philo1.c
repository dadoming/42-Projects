// Beggining the study on the concept of threads

#include <pthread.h>
//gcc -g -pthread main.c -o philo
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int x = 0;

void *second()
{
    x += 1;
    printf("Process id of 2: %d\n", getpid());
    sleep(3);
    printf("2: %d\n", x);
    printf("Ending thread 2\n");
}

void *routine()
{
    printf("Process id of 1: %d\n", getpid());
    sleep(3);
    printf("1: %d\n", x);
    printf("Ending thread 1\n");

}

int main(void)
{
    pthread_t t1;
    pthread_t t2;

    if(pthread_create(&t1, NULL, &routine, NULL) != 0)
        return 1;
    if(pthread_create(&t2, NULL, &second, NULL) != 0)
        return 2;
    pthread_join(t1, NULL); // kinda wait()
    pthread_join(t2, NULL); 

    return 0;
}