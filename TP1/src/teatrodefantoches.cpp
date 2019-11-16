#include "teatrodefantoches.h"
#include <iostream>
#include <string>

TeatroFantoche::TeatroFantoche(int *horarios, int id, string nome, int id_dono, int *capacidade, int *precos):
    EventoInfantil(id, nome, id_dono, capacidade, precos){
    _horarios = horarios;
}

