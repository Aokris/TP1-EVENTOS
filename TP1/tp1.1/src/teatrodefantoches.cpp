#include "teatrodefantoches.h"
#include <iostream>
#include <string>

TeatroFantoche::TeatroFantoche(int &horarios,int id, string nome, int id_responsavel, int &capacidade, int &precos):
    EventoInfantil(id, nome, id_responsavel, capacidade, precos){
    _horarios = &horarios;
}