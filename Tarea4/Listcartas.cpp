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
    cout<<"Posicion: "<<pos<<"\t | Numero:"<<num<<endl;
    if (pos>=0 && pos<size){
        if (pos == 0){
            Carta* temp = inicio;
            inicio = new Carta(num);
            inicio->sig = temp;
        }else{
            Carta* temp = getPos(pos-1);
            Carta* t = new Carta(num);
            t->sig = temp->sig;
            temp->sig = t;
        }
        size++;
    }
}

void ListCartas::eliminar(int pos){
    if(pos>=0 && pos<size){
        if(pos == 0){
            Carta* temp = inicio;
            inicio = inicio->sig;
            delete temp;
        }else if(pos == size-1){
            Carta* temp = final;
            final = buscar(size-2);
            delete temp;
        }else{
            Carta* t = getPos(pos-1);
            Carta* temp = t->sig;
            t->sig = temp->sig;
            delete temp;
        }
        size--;
    }
}

Carta* ListCartas::buscar(int num){
    Carta* t = inicio;
    if(num == inicio->num)
        return inicio;
    for(int i = 1; i<size; i++){
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

