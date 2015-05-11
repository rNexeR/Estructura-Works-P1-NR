#include "Tarea6/Pila.h"

Pila::Pila()
{

}

Pila::~Pila()
{

}

void Pila::agregar(NodoP* n){
    if (!tope){
        tope = n;
        return;
    }
    NodoP* temp = tope;
    tope = n;
    tope->ant = temp;
}

bool Pila::vacia(){
    if(tope)
        return false;
    return true;
}

bool Pila::liberarTope(){
    if(tope){
        NodoP* temp = tope;
        tope = tope->ant;
        delete temp;
        return true;
    }
    return false;
}

void Pila::limpiar(){
    while(liberarTope());
}

NodoP* Pila::getTope(){
    return tope;
}

