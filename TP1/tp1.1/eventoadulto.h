#ifndef EVENTOADULTO
#define EVENTOADULTO

#include <iostream>
#include "evento.h"

class EventoAdulto : protected Evento{
    private:
    int _quota_idoso;
    protected:
        EventoAdulto(int id, string nome, Usuario *responsavel, int *capacidade, int *precos, int quota_idoso);
};

#endif