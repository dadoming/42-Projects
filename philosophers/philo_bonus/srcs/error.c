#include "../includes/philo_bonus.h"

void err_msg(char *err_str)
{
	int i;

	i = 0;
	while (err_str[i] != '\0')
	{
		write(STDERR_FILENO, &err_str[i], 1);
		i++;
	}
	write(STDERR_FILENO, "\n", 1);
}
