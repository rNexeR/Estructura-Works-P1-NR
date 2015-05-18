#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <iostream>
using namespace std;

class Word{
public:
    Word(){
        valor = "";
        sig = NULL;
    }

    Word(string val){
        valor = val;
        sig = NULL;
    }

    ~Word(){

    }

    Word* sig;
    string valor;
};

class Conjunto
{
public:
    Conjunto();
    Word* inicio;

    bool agregar(string valor);
    Conjunto unionc(Conjunto* c);
    Conjunto interseccion(Conjunto* c);
    Conjunto diferencia(Conjunto* c);

    ~Conjunto();
};

#endif // CONJUNTO_H
