#ifndef IDOSO_H
#define IDOSO_H

#include <iostream>
#include <string>
#include "adulto.h"

using namespace std;

class Idoso : protected Adulto{
    private:
        int _id_dependente;
    public:
        Idoso(int id, string categoria, string nome, int idade,float saldo);
};
    
#endif
