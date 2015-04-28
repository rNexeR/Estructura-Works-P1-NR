#ifndef CALLE_H
#define CALLE_H

#include <iostream>
#include <vector>
#include "color.h"
using namespace std;


class Calle
{
private:
    string nombre;
    Color color;
    vector<Calle*> adyecentes;
public:
    Calle(string n, vector<Calle*> c, Color cl);
    Calle(string n, Color cl);
    Calle(string n);
    Calle();
    ~Calle();
    void setNombre(string n);
    void setColor(Color c);
    void setAdyecentes(vector<Calle*> c);

    string getNombre();
    Color getColor();
    vector<Calle*> getAdyecentes();

    void addAdyecente(Calle* c);
    Calle* searchAdyecente(string c);

};

#endif // CALLE_H
