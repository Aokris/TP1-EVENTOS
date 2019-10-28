#include "teatrodefantoches.h"
#include <iostream>
#include <string>

TeatroFantoche::TeatroFantoche(int *horarios,int id, string nome, Usuario *responsavel, int *capacidade, int *precos):EventoInfantil(id, nome, responsavel, capacidade, precos){
    _horarios = horarios;
}