#ifndef FUNCOES_H
#define FUNCOES_H

#include "adulto.h"
#include "crianca.h"
#include "idoso.h"
#include "cinema.h"
#include "teatrodefantoches.h"
#include "show.h"
#include "boate.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iterator>
#include <set>
#include <map>

using namespace std;

std::vector<std::string> splitLine(std::string line, char sep, int &cont);
std::vector<int> readCsv( std::vector<std::vector<std::string>> &resutlCsv, std::string nameFile, char sep);

void IdadeDosUsuarios(int *idad, int max);

void NumeroDependentes(int *depend, int qp, int np);


#endif