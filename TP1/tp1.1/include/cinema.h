#ifndef CINEMA_H
#define CINEMA_H

#include "evento.h"
#include <iostream>

class Cinema : public  Evento{
    private:
        int *_horarios;
        int _duracao;
    protected:
    Cinema(int id, string nome, int id_responsavel, int &capacidade, int &precos, int &horario, int duracao);
};
#endif