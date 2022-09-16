#include "../includes/philo_bonus.h"

void action(int time)
{
    usleep(time * 1000);
}

void print_status(philo_t *p, char *status, char *color)
{
    long long int current_time;

    current_time = get_delta_t(table()->time_start);
    sem_wait(table()->semaphore.print);
    printf("%s%lld", color, current_time);
    printf("  %d  %s%s\n", p->index, status, RESET);
    if(strcmp(status, DIED) != 0)
        sem_post(table()->semaphore.print);
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

int	ft_atoi(const char *str)
{
	int			i;
	int			neg;
	long int	res;

	res = 0;
	neg = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i++] - '0');
		if ((res * neg) < -2147483648)
			return (-2);
		if ((res * neg) > 2147483647)
			return (-1);
	}
	return ((int)res * neg);
}