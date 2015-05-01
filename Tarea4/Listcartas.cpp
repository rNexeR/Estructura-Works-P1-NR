#include "Tarea4/Listcartas.h"

ListCartas::ListCartas()
{
    inicio = NULL;
    final = NULL;
    size = 0;
}

ListCartas::~ListCartas()
{

}

void ListCartas::agregar(int num){
    size++;
    if(!inicio){
        inicio = new Carta(num);
        final = inicio;
        return;
    }
    final->sig = new Carta(num);
    final = final->sig;
}

bool ListCartas::insertar(int num, int pos){
    if (pos>=0 && pos<size){
        if (!inicio){
            inicio = new Carta(num);
            final = inicio;
            size++;
        }else if(pos == size-1){
            agregar(num);
        }else{
            Carta* temp = getPos(pos-1);
            Carta* t = new Carta(num);
            t->sig = temp->sig;
            temp->sig = t;
            size++;
        }
    }
}

void ListCartas::eliminar(int pos){
    Carta* t = getPos(pos);
    Carta* temp = t->sig;
    size--;
    if(t != final)
        t->sig = t->sig->sig;
    else
        final = t;
    delete temp;
}

Carta* ListCartas::buscar(int num){
    Carta* t = inicio;
    if(num == 0)
        return inicio;
    for(int i = 0; i<num; i++){
        t = t->sig;
        if(t->num == num)
            return t;
    }
    return NULL;
}

Carta* ListCartas::getPos(int pos){
    Carta* t = inicio;
    for(int i = 0; i<pos; i++){
        t = t->sig;
    }
    return t;
}

