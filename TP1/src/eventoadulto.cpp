#include "eventoadulto.h"
#include <iostream>
#include <string>

EventoAdulto::EventoAdulto(int id, string nome, int id_dono, int *capacidade, int *precos, int quota_idoso):
    Evento(id, nome, id_dono, capacidade, precos){
    _quota_idoso = quota_idoso;
}