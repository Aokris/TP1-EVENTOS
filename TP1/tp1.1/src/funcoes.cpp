#include "funcoes.h"

std::vector<std::string> splitLine(std::string line, char sep){

    // Convert string in stream string
    std::istringstream split(line);

    // Create vector for line 
    std::vector<std::string> lineVector;

    // Split line for character separator
    for (std::string each; std::getline(split, each,sep); lineVector.push_back(each));

    return lineVector;
}


// Function for read file csv
void readCsv( std::vector<std::vector<std::string>> &resutlCsv, std::string nameFile, char sep){

    std::string lineString;
    std::ifstream myfile(nameFile);

    // Read file if correct name
    if (myfile.is_open()){

        // Process file line by line
        while (getline(myfile, lineString))
  
            resutlCsv.push_back(splitLine(lineString,sep));

        myfile.close();

    }else
        std::cout << "Unable to open file";
}

void IdadeDosUsuarios(int *idad, int max){
    int aux=0,soma=0;
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

   cout << "\nIdade dos usuários:" << endl;
   cout << "Minima: "<< idad[0] << endl;
   cout << "Máxima: "<< idad[max-1] << endl;
   cout << "Média: "<< resul << endl << endl;
}

void NumeroDependentes (int *depend, int qp, int np){
    map<int, int> numdep;
    map<int, int>::iterator it;
    int maior, menor, soma=0;
    float resul;
    int max = sizeof(depend);

    for(int i = 0; i<max;i++){
        numdep[depend[i]]++;
    }
    
    it = numdep.begin();
    maior = it->second;
    menor = it->second;

    for(it = numdep.begin(); it!=numdep.end();it++){
        if(maior < it->second){
            maior = it->second;
        }

        if(menor > it->second){
            menor = it->second;
        }
    }

    if(qp == 0){
        menor = 0;
    }

    for(it = numdep.begin(); it!=numdep.end();it++){
        soma = soma + it->second;
    }

    if(qp == 0){
        resul = (float)soma/np;
    }else{
        resul = (float)soma/np;
    }

    cout << "\nNúmero de dependentes:" << endl;
    cout << "Minima: "<< menor << endl;
    cout << "Máxima: "<< maior << endl;//numero de dependetes deve ser por adulto (ver exemplo da professora)
    cout << "Média: "<< resul << endl;
}
