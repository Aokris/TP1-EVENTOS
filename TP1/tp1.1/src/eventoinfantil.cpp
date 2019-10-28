#include "eventoinfantil.h"
#include <iostream>
#include <string>

EventoInfantil::EventoInfantil(int id, string nome, int id_responsavel, int &capacidade, int &precos):
    Evento(id, nome, id_responsavel, capacidade, precos){
}