#ifndef SHOW
#define SHOW

#include <iostream>
#include "eventoadulto.h"

class Show : protected EventoAdulto{
    private:
    int _aberturaPortoes;
    string *_artistas;
    protected:
        Show(int quota_idoso, int aberturaPortoes, string *artistas);
};

#endif