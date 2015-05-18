#include "Tarea8/Conjunto.h"

Conjunto::Conjunto()
{
    inicio = NULL;
}

double entero(string val){
    double valor = 0.0;
    for(int x = 0; x < val.size(); x++){
        char c = toupper(val[x]) - 'A';
        valor+=c;
    }
    return (valor/val.size());
}

bool Conjunto::agregar(string valor){
    if (!inicio){
            cout<<"agregando inicio"<<endl;
            inicio = new Word(valor);
            return true;
        }
        Word* actual = inicio;
        if (entero(valor) < entero(inicio->valor)){
            cout<<"agregando antes de inicio"<<endl;
            inicio = new Word(valor);
            inicio->sig = actual;
            return true;
        }
        while(true){
            if(entero(valor) == entero(inicio->valor))
                return false;
            if (actual->sig && entero(valor) > entero(actual->sig->valor))
                actual = actual->sig;
            if(!actual->sig)
                break;
            if (entero(valor) < entero(actual->sig->valor))
                break;
        }
        if (actual){
            Word* temp = actual->sig;
            actual->sig = new Word(valor);
            actual->sig->sig = temp;
            cout<<"Agregado despues de: "<<actual->valor<<endl;
        }
        return true;
}

Conjunto Conjunto::unionc(Conjunto* c){
    Word* actual = inicio;
    Word* actualc = c->inicio;

    if(!actual)
        return *c;
    if(!actualc)
        return *this;
    Conjunto unir;
    while(actual || actualc){
        if(actual && (!actualc || entero(actual->valor) < entero(actualc->valor))){
            unir.agregar(actual->valor);
            actual = actual->sig;
            continue;
        }
        if(actualc && (!actual || entero(actual->valor) > entero(actualc->valor))){
            unir.agregar(actualc->valor);
            actualc = actualc->sig;
            continue;
        }
        if(entero(actual->valor) == entero(actualc->valor)){
            unir.agregar(actual->valor);
            actual = actual->sig;
            actualc = actualc->sig;
            continue;
        }
    }
    return unir;
}

Conjunto Conjunto::interseccion(Conjunto* c){
    Word* actual = inicio;
    Word* actualc = c->inicio;

    Conjunto inter;
    while(actual && actualc){
        if(entero(actual->valor) < entero(actualc->valor)){
            actual = actual->sig;
            continue;
        }
        if(entero(actual->valor) > entero(actualc->valor)){
            actualc = actualc->sig;
            continue;
        }
        if(entero(actual->valor) == entero(actualc->valor)){
            inter.agregar(actual->valor);
            actual = actual->sig;
            actualc = actualc->sig;
            continue;
        }
    }
    return inter;
}

Conjunto Conjunto::diferencia(Conjunto* c){
    Word* actual = inicio;
    Word* actualc = c->inicio;

    Conjunto dif;
    while(actual || actualc){
        if(actual && (!actualc || entero(actual->valor) < entero(actualc->valor))){
            dif.agregar(actual->valor);
            actual = actual->sig;
            continue;
        }
        if(actualc && (!actual || entero(actual->valor) > entero(actualc->valor))){
            dif.agregar(actualc->valor);
            actualc = actualc->sig;
            continue;
        }
        if(entero(actual->valor) == entero(actualc->valor)){
            actual = actual->sig;
            actualc = actualc->sig;
            continue;
        }
    }
    return dif;
}

Conjunto::~Conjunto()
{

}

