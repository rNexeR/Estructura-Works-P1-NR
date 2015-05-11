#include "Tarea5/Nodolist.h"

NodoList::NodoList()
{
    SIZE = 10;
    Nodo espacios[10], inicios[10];
    //inicializar();
}

NodoList::~NodoList()
{

}

void NodoList::agregar(int lista, QString c){
    if (inicios[0] == -1)
        return;
    int pos = inicios[0];
    inicios[0] = espacios[pos].sig;

    int posLista = inicios[lista];
    while(espacios[posLista].sig != -1)
        posLista = espacios[posLista].sig;
    espacios[posLista].sig = pos;
    espacios[pos].sig = -1;
    espacios[pos].valor = c;
}

void NodoList::insertar(int lista, int pos, QString c){
    if (inicios[0] == -1)
        return;
    int posNueva = inicios[0];
    inicios[0] = espacios[posNueva].sig;
    if (pos == 0){
        espacios[posNueva].sig = inicios[lista];
        inicios[lista] = posNueva;
        espacios[posNueva].valor = c;
        return;
    }
    int posAnterior = getAnterior(lista, pos);
    espacios[posNueva].sig = espacios[posAnterior].sig;
    espacios[posAnterior].sig = posNueva;
    espacios[posNueva].valor = c;

}

void NodoList::eliminar(int lista, int pos){
    if (pos == 0){
        int posActual = inicios[lista];
        inicios[lista] = espacios[posActual].sig;
        //espacios[posActual].valor = NULL;
        espacios[posActual].sig = inicios[0];
        inicios[0] = posActual;
        return;
    }
    int posAnterior = getAnterior(lista, pos);
    int posNueva = inicios[0];
    inicios[0] = pos;
    espacios[posAnterior].sig = espacios[pos].sig;
    espacios[pos].sig = posNueva;
    //espacios[pos].valor = NULL;
}

int NodoList::getAnterior(int lista, int pos){
    int i = 1;
    int actual = inicios[lista];
    while(i<pos && espacios[actual].sig!=-1){
        actual = espacios[actual].sig;
        i++;
    }
    return actual;
}

int NodoList::buscar(int lista, int pos){
    int i = 0;
    int actual = inicios[lista];
    while(i<pos && espacios[actual].sig != -1){
        actual = espacios[actual].sig;
        i++;
    }
    return actual;
}

void NodoList::inicializar(){
    inicios[0] = 0;
    for(int i = 1; i<SIZE; i++)
        inicios[i] = -1;

    for (int i = 0; i<SIZE; i++){
        espacios[i].sig = i+1;
    }
    espacios[SIZE-1].sig = -1;
}

void NodoList::crearLista(QString c){
    for (int i = 0; i<SIZE; i++)
        cout<<espacios[i].sig<<endl;
    int x = 0;
    while(inicios[x] != -1 || x == SIZE)
        x++;
    if(x == SIZE)
        return;
    int y = inicios[0];
    inicios[x] = y;
    int sig = espacios[y].sig;
    inicios[0] = sig;
    espacios[y].valor = c;
    espacios[y].sig = -1;
    listas++;
}

void NodoList::addToList(QListWidget *list, int lista){
    int x = inicios[lista];
    while(espacios[x].sig != -1){
        list->addItem(espacios[x].valor);
        x = espacios[x].sig;
    }
}

int NodoList::getNumberOfLists(){

}
