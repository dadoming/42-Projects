// Summing values using multithreads
// This program sums both halfs of the array into a total sum

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void* print_prime(void* arg)
{
    int index = *(int*)arg;
    int j = 0;
    int sum = 0;
    while (j < 5)
    {
        sum += primes[index + j];
        j++;
    }
    printf("Local sum: %d\n", sum);
    *(int*)arg = sum;
    return (arg);
}

int main(void)
{
    pthread_t t[2];
    int i = 0;
    while (i < 2)
    {
        int *a = malloc(sizeof(int));
        *a = 5 * i;
        if(pthread_create(&t[i], NULL, print_prime, a) != 0)
            return 1;
        i++;
    }
    i = 0;
    int globalSum = 0;
    while (i < 2)
    {
        int *res;
        if(pthread_join(t[i], (void **)&res) != 0)
            return 2;
        globalSum += *res;
        free(res);
        i++;
    }
    printf("Global Sum: %d\n", globalSum);
    return 0;
}