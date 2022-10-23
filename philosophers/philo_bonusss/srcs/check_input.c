#include "../header/philo_bonus.h"

static int check_if_number(char **str);

int check_input(int argc, char **argv)
{
    if (argc < 5 || argc > 6)
    {
        err_msg("Wrong number of arguments.");
        return (TRUE);
    }
    if (check_if_number(argv) == TRUE)
    {
        err_msg("Wrong input.");
        return (TRUE);
    }
    return (FALSE);
}

static int check_if_number(char **str)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (str[i])
    {
        if(!((str[i][j] == '+' ) || (str[i][j] >= '0' \
            && str[i][j] <= '9')))
            return (TRUE);
        j++;
        while (str[i][j] != '\0')
        {
            if (!(str[i][j] >= '0' && str[i][j] <= '9'))
                return (TRUE);
            j++;
        }
        j = 0;
        i++;
    }
    return (FALSE);
}
