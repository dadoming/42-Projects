#include "pipex.h"

void msgError(char *where)
{
    perror(where);
    exit(1);
}