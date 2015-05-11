#ifndef PILA_H
#define PILA_H
#include <QString>
#include <iostream>
//#include "Tarea6/NodoP.h"
using namespace std;

class NodoP
{
public:
    NodoP(){
        valor = "";
        ant = NULL;
    }

    ~NodoP(){

    }

    NodoP* ant;
    QString valor;
};

class Pila
{
public:
    Pila();
    ~Pila();
    void agregar(NodoP* n);
    bool vacia();
    bool liberarTope();
    void limpiar();
    NodoP* getTope();

private:
    NodoP* tope;
};

#endif // PILA_H
