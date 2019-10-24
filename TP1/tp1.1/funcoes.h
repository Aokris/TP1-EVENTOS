#include "adulto.h"
#include "crianca.h"
#include "idoso.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include<iterator>
#include <set>

void le_arquivo (fstream &file,vector<string> &linha);

void IdadeDosUsuarios(int *idad, int max);

void NumeroDependentes (int *depend, int max);

using namespace std;