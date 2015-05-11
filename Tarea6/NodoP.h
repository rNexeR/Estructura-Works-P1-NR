#ifndef NODO_H
#define NODO_H

#include <QString>

class NodoP
{
public:
    NodoP();
    ~NodoP();
    NodoP* ant;
    QString valor;
};

#endif // NODO_H
