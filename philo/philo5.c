// Passing arguments to threads
// PROBLEM: Create 10 threads, each taking a unique prime from the primes array and print it on the screen.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void* print_prime(void* arg)
{
    sleep(1);
    int i = *(int*)arg;
    printf("Prime: %d\n", primes[i]);
    free(arg);
}

int main(void)
{
    pthread_t t[10];
    int i = 0;
    while (i < 10)
    {
        int *a = malloc(sizeof(int));
        *a = i;
        if(pthread_create(&t[i], NULL, print_prime, a) != 0) // Or more easily by substituting the a for &primes[i] and thus no need for more memory allocation
            return 1;
        i++;
    }
    i = 0;
    while (i < 10)
    {
        if(pthread_join(t[i], NULL) != 0)
            return 2;
        i++;
    }
    return 0;
}