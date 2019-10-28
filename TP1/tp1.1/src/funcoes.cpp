#include "funcoes.h"

void le_arquivo (fstream &file, vector<string> &linha, int *qlinhas){

    string buffer;
    string aux;
    vector<string>::iterator ptr; 
    int k = 0, n = 0, j = 0;
    while(!file.eof()){
        getline(file, buffer,'\n'); //ler cada coluna
        for(int i = 0; i < buffer.length(); i++){
            if(buffer[i] == ','){
                linha.push_back(aux);
                aux.clear();
                n++;
                
            } else {
                aux = aux + buffer[i];
            }           
        }
        linha.push_back(aux);
        aux.clear();
    }
    qlinhas[j] = n;
    j++;
}

void IdadeDosUsuarios(int *idad, int max){
    int aux = 0, soma = 0;
    float resul;

    for (int i = 0; i < max; i++) { 
        soma += idad[i];
    }

    for (int i = 0; i < max; i++) { 
        for (int j = 0; j < max; j++){ 
            if (idad[i] < idad[j]){ 
                aux = idad[i];
                idad[i] = idad[j];
                idad[j] = aux;
            } 
        } 
   }
   
   resul = (float)soma/max;

   std::cout << "Idade dos usuários:" << endl;
   std::cout << "Minima: "<< idad[0] << endl;
   std::cout << "Máxima: "<< idad[max-1] << endl;
   std::cout << "Média: "<< resul << endl << endl;
}

void NumeroDependentes (int *depend, int qp, int np){ // (vetor dependentes, quantidade de crianças, quantidade de adultos)
    map<int, int> numdep;
    map<int, int>::iterator it;
    int maior, menor, soma = 0;
    float resul;
    int max = sizeof(depend);

    for(int i = 0; i < max; i++){
        numdep[depend[i]]++;
    }
    
    it = numdep.begin();
    maior = it->second;
    menor = it->second;

    for(it = numdep.begin(); it != numdep.end(); it++){
        if(maior < it->second){
            maior = it->second;
        }
        if(menor > it->second){
            menor = it->second;
        }
    }

    if(np > numdep.size()){ // Se quantidade de adultos total != quantidade de adultos com crianças
        menor = 0;
    }

    for(it = numdep.begin(); it != numdep.end(); it++){
        soma = soma + it->second;
    }

    resul = (float)soma/np;

    std::cout << "Número de dependentes:" << endl;
    std::cout << "Minima: "<< menor << endl;
    std::cout << "Máxima: "<< maior << endl;
    std::cout << "Média: "<< resul << endl << endl;
}
