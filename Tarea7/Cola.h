#ifndef COLA_H
#define COLA_H

#include "Tarea7/Nodoc.h"
#include <iostream>
using namespace std;

class Cola
{
public:
    Cola();
    ~Cola();
    void agregar(NodoC* n);
    bool vacia();
    bool liberarFrente();
    void limpiar();
    NodoC* getFrente();

private:
    NodoC* frente, *ultimo;
};

#endif // COLA_H
