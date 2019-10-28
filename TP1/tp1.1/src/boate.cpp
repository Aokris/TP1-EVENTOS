#include "boate.h"
#include <iostream>
#include <string>

Boate::Boate(int quota_idoso, int horaInicio, int horaFim, int id, string nome, Usuario *responsavel, int *capacidade, int *precos):EventoAdulto(id, nome, responsavel, capacidade, precos, quota_idoso){
    _horaInicio = horaInicio;
    _horaFim = horaFim;
}