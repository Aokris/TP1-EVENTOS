#ifndef CINEMA_H
#define CINEMA_H

#include "evento.h"
#include <iostream>

class Cinema : public  Evento{
    protected:
        int *_horarios;
        int _duracao;
    public:
        Cinema(int id, string nome, int id_dono, int *capacidade, int *precos, int *horario, int duracao);
};

#endif