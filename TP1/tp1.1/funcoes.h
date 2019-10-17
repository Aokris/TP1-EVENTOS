#include "adulto.h"
#include "crianca.h"
#include "idoso.h"
#include "evento.h"
#include "eventoadulto.h"
#include "eventoinfantil.h"
#include "teatrodefantoches.h"
#include "cinema.h"
#include "boate.h"
#include "show.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include<iterator>

void le_arquivo (fstream &file,vector<string> &linha);

void IdadeDosUsuarios(int *idad, int max);

void NumeroDependentes (int *depend, int max);

using namespace std;