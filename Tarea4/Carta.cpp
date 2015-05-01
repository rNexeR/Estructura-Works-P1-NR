#include "Tarea4/Carta.h"

Carta::Carta(int num)
{
    this->num = num;
    sig = NULL;
}

Carta::~Carta()
{

}

Carta::Carta(){
    this->num = 0;
    sig = NULL;
}
