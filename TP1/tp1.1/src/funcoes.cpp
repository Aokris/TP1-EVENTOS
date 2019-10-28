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

//2 . Função que imprime a idade dos usuarios segundo o especificado
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

//Impressao das idades minima, maxima e media
   std::cout << "Idade dos usuários:" << endl;
   std::cout << "Minima: "<< idad[0] << endl;
   std::cout << "Máxima: "<< idad[max-1] << endl;
   std::cout << "Média: "<< resul << endl << endl;
}

//Numero de dependentes por adulto
void NumeroDependentes (int *depend, int qp, int np){
    //Criação de map para armazenar numero de dependentes por adulto
    map<int, int> numdep;
    map<int, int>::iterator it;

    //Variaveis axuiliares
    int maior, menor, soma = 0;
    float resul;
    int max = sizeof(depend);

    //Passagem para o Map
    for(int i = 0; i < max; i++){
        numdep[depend[i]]++;
    }
    
    //Definindo o minimo e o maximo
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

    //Tirando a media
    resul = (float)soma/np;

    //Impressao
    std::cout << "Número de dependentes:" << endl;
    std::cout << "Minima: "<< menor << endl;
    std::cout << "Máxima: "<< maior << endl;
    std::cout << "Média: "<< resul << endl << endl;
}
