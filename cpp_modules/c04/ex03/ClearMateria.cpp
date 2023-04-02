# include "ClearMateria.hpp"

t_list  *_droppedMateria = nullptr;

void addDroppedMateria(AMateria *materia)
{
    t_list *newNode = new t_list;
    newNode->materia = materia;
    newNode->next = _droppedMateria;
    _droppedMateria = newNode;
}

void clearDroppedMateria()
{
    t_list *tmp = _droppedMateria;
    while (tmp)
    {
        _droppedMateria = _droppedMateria->next;
        delete tmp->materia;
        delete tmp;
        tmp = _droppedMateria;
    }
}
