// Thread Barriers: Practical example.
// Problem: Every thread rolls a dice, and saves its value in an array.
//          The main thread calculates the winner and then each thread
//           prints a message with wether they won or lost.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define THREADS_NUM 8

pthread_barrier_t barrierDice;
pthread_barrier_t barrierCalculate;

int diceValues[8];
int status[8] = { 0 };

void *rollDice(void *args)
{
    int index = *(int*)args;
    while (1)
    {
        diceValues[index] = (rand() % 6) + 1;
        pthread_barrier_wait(&barrierDice);
        pthread_barrier_wait(&barrierCalculate);
        if (status[index] == 1)
            printf("(%d rolled %d) I won!\n", index, diceValues[index]);
        else 
            printf("(%d rolled %d) I lost.\n", index, diceValues[index]);
    }
    free(args);
}

int main(void)
{
    srand(time(NULL));
    pthread_t t[THREADS_NUM];
    pthread_barrier_init(&barrierDice, NULL, THREADS_NUM + 1); // Because main is also a thread 
    pthread_barrier_init(&barrierCalculate, NULL, THREADS_NUM + 1);
    int i = 0;
    while (i < THREADS_NUM)
    {
        int *a = malloc(sizeof(int));
        *a = i;
        if(pthread_create(&t[i], NULL, &rollDice, a) != 0)
            perror("Error creating thread");
        i++;
    }
    while (1)
    {
        pthread_barrier_wait(&barrierDice);
        int max = 0;
        for (int i = 0; i < THREADS_NUM; i++)
        {
            if (diceValues[i] > max)
                max = diceValues[i];
        }
        for(int i = 0; i < THREADS_NUM; i++)
        {
            if(diceValues[i] == max)
                status[i] = 1;
            else 
                status[i] = 0;
        }
        printf("--------------------------\n");
        sleep(1);
        pthread_barrier_wait(&barrierCalculate);
    }
    i = 0;
    while (i < THREADS_NUM)
    {
        if(pthread_join(t[i], NULL) != 0)
            perror("Error joining thread");
        i++;
    }
    pthread_barrier_destroy(&barrierDice);
    pthread_barrier_destroy(&barrierCalculate);
    return 0;
}