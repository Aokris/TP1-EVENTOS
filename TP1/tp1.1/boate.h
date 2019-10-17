#ifndef BOATE
#define BOATE

#include <iostream>
#include "eventoadulto.h"

class Boate : protected EventoAdulto{
    private:
    int _horaInicio;
    int _horaFim;

    protected:
        Boate(int quota_idoso, int horaInicio, int horaFim);
};

#endif