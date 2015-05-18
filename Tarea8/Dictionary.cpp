#include "Tarea8/Dictionary.h"

Dictionary::Dictionary()
{

}

int Dictionary::hash(string val){
    char v = val[0];
    int c = toupper(v) - 'A';
    return c%26;
}

void Dictionary::agregar(string valor){
    int pos = hash(valor);
    words[pos].agregar(valor);
}

Dictionary::~Dictionary()
{

}

