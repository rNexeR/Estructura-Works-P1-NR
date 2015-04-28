#include "Calle.h"

Calle::Calle(string n, vector<Calle*> c, Color cl)
{
    nombre = n;
    adyecentes = c;
    color = cl;
}

Calle::Calle(){
    nombre = "empty";
    color = BLANCO;
}

Calle::Calle(string n){
    nombre = n;
    color = BLANCO;
}

Calle::Calle(string n, Color cl){
    nombre = n;
    color = cl;
}

Calle::~Calle()
{

}

void Calle::setNombre(string n){
    nombre = n;
}

void Calle::setColor(Color c){
    color = c;
}

void Calle::setAdyecentes(vector<Calle*> c){
    adyecentes = c;
}

string Calle::getNombre(){
    return nombre;
}

Color Calle::getColor(){
    return color;
}

vector<Calle*> Calle::getAdyecentes(){
    return adyecentes;
}

void Calle::addAdyecente(Calle* c){
    adyecentes.push_back(c);
}

Calle* Calle::searchAdyecente(string n){
    for(int x = 0; x < adyecentes.size(); x++){
        if (adyecentes[x]->getNombre() == n)
            return adyecentes[x];
    }
    return NULL;
}

