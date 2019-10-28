#ifndef EVENTO_INFANTIL_H
#define EVENTO_INFANTIL_H

#include <iostream>
#include "evento.h"

class EventoInfantil : public  Evento{
    protected:
        EventoInfantil(int id, string nome, int id_responsavel, int &capacidade, int &precos);
};

#endif