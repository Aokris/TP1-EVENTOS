#include "usuario.h"
#include <iostream>
#include <string>

Usuario::Usuario(int id, string categoria, string nome, int idade, float saldo){
    _id = id;
    _categoria = categoria;
    _nome = nome;
    _idade = idade;
    _saldo = saldo;
}
