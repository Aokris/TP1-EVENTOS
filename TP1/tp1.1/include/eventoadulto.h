#ifndef EVENTO_ADULTO_H
#define EVENTO_ADULTO_H

#include <iostream>
#include "evento.h"

class EventoAdulto : public  Evento{
    private:
    int _quota_idoso;
    protected:
        EventoAdulto(int id, string nome, int id_responsavel, int &capacidade, int &precos, int quota_idoso);
};

#endif