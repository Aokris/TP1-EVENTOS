#ifndef EVENTO_ADULTO_H
#define EVENTO_ADULTO_H

#include <iostream>
#include "evento.h"

class EventoAdulto : public  Evento{
    protected:
    int _quota_idoso;
    public:
        EventoAdulto(int id, string nome, int id_dono, int *capacidade, int *precos, int quota_idoso);
};

#endif