#ifndef SHOW_H
#define SHOW_H

#include <iostream>
#include "eventoadulto.h"

class Show : protected EventoAdulto{
    private:
    int _aberturaPortoes;
    string *_artistas;
    protected:
        Show(int quota_idoso, int aberturaPortoes, string *artistas,int id, string nome, Usuario *responsavel, int *capacidade, int *precos);
};

#endif