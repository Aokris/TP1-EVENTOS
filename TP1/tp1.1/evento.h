#ifndef EVENTO
#define EVENTO

#include <iostream>
#include <string>
#include "usuario.h"

class Evento{
    private:
        int _id;
        string _nome;
        Usuario responsavel;
        int *_capacidade;
        int *_precos;
    
    protected:
        Evento(int id, string nome, Usuario responsavel, int *capacidade, int *precos);

};
#endif