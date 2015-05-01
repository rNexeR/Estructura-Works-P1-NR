#ifndef LISTCARTAS_H
#define LISTCARTAS_H
#include "Tarea4/Carta.h"
#include <iostream>
using namespace std;


class ListCartas
{
public:
    Carta *inicio, *final;
    int size;
    ListCartas();
    ~ListCartas();
    void agregar(int num);
    bool insertar(int num, int pos);
    void eliminar(int pos);
    Carta* buscar(int num);
    Carta* getPos(int pos);
};

#endif // LISTCARTAS_H
