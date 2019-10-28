#include "cinema.h"
#include <iostream>
#include <string>

Cinema::Cinema(int id, string nome, int id_responsavel, int &capacidade, int &precos, int &horario, int duracao):
    Evento(id, nome, id_responsavel, capacidade, precos){
    _duracao = duracao;
    _horarios = &horario;
}