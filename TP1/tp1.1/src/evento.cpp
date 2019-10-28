#include "evento.h"
#include <iostream>
#include <string>

Evento::Evento(int id, string nome, int id_responsavel, int &capacidade, int &precos){
    _id = id;
    _nome =  nome;
    _id_responsavel = id_responsavel;
    _capacidade = &capacidade;
    _precos = &precos;
}