#ifndef CRIANCA_H
#define CRIANCA_H

#include <iostream>
#include <string>
#include "usuario.h"

using namespace std;

class Crianca : protected Usuario{
    private:
        int _id_responsavel;
    public:
        Crianca(int id, string categoria, string nome, int idade, float saldo, int id_responsavel);
        int get_id_responsavel();
        string get_nome();
};
    
#endif
