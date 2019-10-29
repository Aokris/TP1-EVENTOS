#ifndef BOATE_H
#define BOATE_H

#include <iostream>
#include "eventoadulto.h"

class Boate : public  EventoAdulto{
    private:
    int _horaInicio;
    int _horaFim;

    protected:
        Boate(int quota_idoso, int horaInicio, int horaFim, int id, string nome, int id_dono, int &capacidade, int &precos);
};

#endif