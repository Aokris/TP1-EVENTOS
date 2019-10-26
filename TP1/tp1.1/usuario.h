#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>

using namespace std;

class Usuario{
    private:
        int _id;
        string _categoria;
        string _nome;
        int _idade;
        float _saldo;
    
    protected:
        Usuario(int id, string categoria, string nome, int idade, float saldo);
};
    
#endif
