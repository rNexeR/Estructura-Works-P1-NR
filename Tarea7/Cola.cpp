#include "Tarea7/Cola.h"
Cola::Cola()
{
    frente = NULL;
    ultimo = NULL;
}

Cola::~Cola()
{

}

void Cola::agregar(NodoC* n){
    if(!frente){
        cout<<"Nuevo"<<endl;
        frente = n;
        ultimo = n;
        return;
    }
    ultimo->sig = n;
    ultimo = n;
}

bool Cola::vacia(){
    if(frente)
        return false;
    return true;
}

bool Cola::liberarFrente(){
    if(frente){
        NodoC* temp = frente;
        frente = frente->sig;
        delete temp;
        return true;
    }
    ultimo = NULL;
    return false;
}

void Cola::limpiar(){
    while(liberarFrente());
}

NodoC* Cola::getFrente(){
    return frente;
}

