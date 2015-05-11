#ifndef NODOLIST_H
#define NODOLIST_H
#include "Nodo.h"
#include <QListWidget>
#include <iostream>
using namespace std;


class NodoList
{
public:
    NodoList();
    ~NodoList();
    int SIZE;
    Nodo espacios[];
    int inicios[];
    int listas;
    void agregar(int lista, QString c);
    void insertar(int lista, int pos, QString c);
    void eliminar(int lista, int pos);
    int getAnterior(int lista, int pos);
    int buscar(int lista, int pos);
    void inicializar();
    void crearLista(QString c);
    void addToList(QListWidget *list, int lista);
    int getNumberOfLists();
};

#endif // NODOLIST_H
