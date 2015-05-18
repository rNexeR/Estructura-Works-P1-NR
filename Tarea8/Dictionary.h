#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "Conjunto.h"
#include <stdio.h>
#include <ctype.h>

class Dictionary
{
public:
    Dictionary();
    ~Dictionary();
    int hash(string val);
    void agregar(string valor);
    Conjunto words[26];
};

#endif // DICTIONARY_H
