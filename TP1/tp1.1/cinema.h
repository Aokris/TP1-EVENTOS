#ifndef CINEMA
#define CINEMA

#include "evento.h"
#include <iostream>

class Cinema : protected Evento{
    private:
        int *_horario;
        int _duracao;
    protected:
    Cinema(int id, string nome, Usuario responsavel, int *capacidade, int *precos, int *horario, int duracao);
};
#endif