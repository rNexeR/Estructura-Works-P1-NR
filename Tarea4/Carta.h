#ifndef CARTA_H
#define CARTA_H
#include <iostream>
using namespace std;


class Carta
{
public:
    int num;
    Carta *sig;
    Carta(int num);
    Carta();
    ~Carta();
};

#endif // CARTA_H
