#include "crianca.h"
#include "usuario.h"
#include <iostream>
#include <string>

Crianca::Crianca(int id, string categoria, string nome, int idade, float saldo, int id_responsavel):Usuario(id, categoria, nome, idade, saldo){
    _id_responsavel = id_responsavel;
}
