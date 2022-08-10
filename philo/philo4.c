// Getting return values from threads

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void *roll_dice()
{
    int *dice_value = malloc(sizeof(int));
    *dice_value = (rand() % 6) + 1;
    return ((void*)dice_value);
}

int main(void)
{
    int dice_rolls = 6;
    int i = 0;
    int *dice_value;
    pthread_t th[dice_rolls];
    
    srand(time(NULL));
    while (i < dice_rolls)
    {
        if(pthread_create(&th[i], NULL, &roll_dice, NULL) != 0)
            return 1;
        i++;
    }
    i = 0;
    while (i < dice_rolls)
    {
        if(pthread_join(th[i], (void **) &dice_value) != 0)
            return 2;
        printf("You got: %d!\n", *dice_value);
        free(dice_value);
        i++;
    }
    return 0;
}