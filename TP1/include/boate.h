#ifndef BOATE_H
#define BOATE_H

#include <iostream>
#include "eventoadulto.h"

class Boate : public  EventoAdulto{
    protected:
    int _horaInicio;
    int _horaFim;

    public:
        Boate(int quota_idoso, int horaInicio, int horaFim, int id, string nome, int id_dono, int *capacidade, int *precos);
};

#endif