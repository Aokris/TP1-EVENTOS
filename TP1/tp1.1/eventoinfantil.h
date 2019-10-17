#ifndef EVENTOINFANTIL
#define EVENTOINFANTIL

#include <iostream>
#include "evento.h"

class EventoInfantil : protected Evento{
    protected:
        EventoInfantil(int id, string nome, Usuario responsavel, int *capacidade, int *precos);
};

#endif