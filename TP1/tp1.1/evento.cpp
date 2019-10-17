#include "evento.h"
#include <iostream>
#include <string>

Evento::Evento(int id, string categoria, Usuario responsavel, int *capacidade, int *precos){
    _id = id;
    _categora = categoria;
    _responsável = responsável;
    _capacidade = capacidade;
    _precos = precos;
}