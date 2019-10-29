#ifndef EVENTO_H
#define EVENTO_H

#include <iostream>
#include <string>
#include "usuario.h"

class Evento{
    protected:
        int _id;
        string _nome;
        int _id_dono;
        int *_capacidade;
        int *_precos;
    
    public:
        Evento(int id, string nome, int id_dono, int *capacidade, int *precos);
        int get_id();
        string get_nome();
};
#endif