#ifndef TEATRO_FANTOCHE_H
#define TEATRO_FANTOCHE_H

#include <iostream>
#include "eventoinfantil.h"

class TeatroFantoche : public  EventoInfantil{
    private:
    int *_horarios;
    protected:
        TeatroFantoche(int &horarios,int id, string nome, int id_responsavel, int &capacidade, int &precos);
};

#endif