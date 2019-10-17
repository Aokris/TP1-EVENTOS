#ifndef ADULTO_H
#define ADULTO_H

#include <iostream>
#include <string>
#include "usuario.h"

using namespace std;

class Adulto : protected Usuario{
    private:
        int _id_dependente;
    public:
        Adulto (int id, string categoria, string nome, int idade,float saldo);
};
    
#endif
