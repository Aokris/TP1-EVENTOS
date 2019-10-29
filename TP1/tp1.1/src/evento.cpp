#include "evento.h"
#include <iostream>
#include <string>

Evento::Evento(int id, string nome, int id_dono, int &capacidade, int &precos){
    _id = id;
    _nome =  nome;
    _id_dono = id_dono;
    _capacidade = &capacidade;
    _precos = &precos;
}