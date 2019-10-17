#ifndef TEATROFANTOCHE
#define TEATROFANTOCHE

#include <iostream>
#include "eventoinfantil.h"

class TeatroFantoche : protected EventoInfantil{
    private:
    int *_horarios;
    protected:
        TeatroFantoche(int *horarios);
};

#endif