#ifndef EVENTO_H
#define EVENTO_H

#include <iostream>
#include <string>
#include "usuario.h"

class Evento: public Usuario{
    private:
        int _id;
        string _nome;
        Usuario *_responsavel;
        int *_capacidade;
        int *_precos;
    
    protected:
        Evento(int id, string nome, Usuario *responsavel, int *capacidade, int *precos);

};
#endif