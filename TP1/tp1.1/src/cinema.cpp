#include "cinema.h"
#include <iostream>
#include <string>

Cinema::Cinema(int id, string nome, int id_dono, int &capacidade, int &precos, int &horario, int duracao):
    Evento(id, nome, id_dono, capacidade, precos){
    _duracao = duracao;
    _horarios = &horario;
}