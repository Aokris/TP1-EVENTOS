#ifndef EVENTO_H
#define EVENTO_H

#include <iostream>
#include <string>
#include "usuario.h"

class Evento{
    private:
        int _id;
        string _nome;
        int _id_responsavel;
        int *_capacidade;
        int *_precos;
    
    protected:
        Evento(int id, string nome, int id_responsavel, int &capacidade, int &precos);

};
#endif