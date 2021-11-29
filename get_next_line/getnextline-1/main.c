#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int     fd;
    char    *line;
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
            printf("ERRO");
            exit(0);
        }
        line = get_next_line(fd);
        while (line != NULL)
        {
            printf("%s", line);
            printf("\n");
            line = get_next_line(fd);
        }
    }
    else
    {
        printf("error, argc != 2");
        exit(0);
    }
}