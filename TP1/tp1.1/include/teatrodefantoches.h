#ifndef TEATRO_FANTOCHE_H
#define TEATRO_FANTOCHE_H

#include <iostream>
#include "eventoinfantil.h"

class TeatroFantoche : public  EventoInfantil{
    protected:
        int *_horarios;
    public:
        TeatroFantoche(int *horarios, int id, string nome, int id_dono, int *capacidade, int *precos);
};

#endif