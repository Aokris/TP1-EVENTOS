#include "cinema.h"
#include <iostream>
#include <string>

Cinema::Cinema(int id, string nome, Usuario responsavel, int *capacidade, int *precos, int *horarios, int duracao): Evento(id, nome,  responsavel, capacidade, precos){
    _duracao = duracao;
}