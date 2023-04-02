# ifndef CLEARMATERIA_HPP
# define CLEARMATERIA_HPP

# include "AMateria.hpp"

class AMateria;

typedef struct s_list
{
    AMateria *materia;
    struct s_list *next;
} t_list;

void clearDroppedMateria();
void addDroppedMateria( AMateria *materia );

# endif