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

int Usuario::get_id(){
    return _id;
}
string Usuario::get_categoria(){
    return _categoria;
}
string Usuario::get_nome(){
    return _nome;
}
int Usuario::get_idade(){
    return _idade;
}
float Usuario::get_saldo(){
    return _saldo;
}