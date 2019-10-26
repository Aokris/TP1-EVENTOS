#include "evento.h"
#include <iostream>
#include <string>

Evento::Evento(int id, string nome, Usuario *responsavel, int *capacidade, int *precos):Usuario(responsavel->get_id, responsavel->get_categoria, responsavel->get_nome, responsavel->get_idade, responsavel->get_saldo){
    _id = id;
    _nome =  nome;
    _responsavel = responsavel;
    _capacidade = capacidade;
    _precos = precos;
}