#include "funcoes.h"

// 1. Função que divide as linhas
std::vector<std::string> splitLine(std::string line, char sep, int &cont){

    // Convertendo a string para stream string
    std::istringstream split(line);

    // Criando um vetor para a linha
    std::vector<std::string> lineVector;

    // Divide a linha para o separador de caracteres
    for (std::string each; std::getline(split, each,sep); lineVector.push_back(each));

    // Conta o número de colunas
    cont = lineVector.size();

    return lineVector;
}


// 2. Função que abre arquivo csv e realiza sua leitura
std::vector<int> readCsv( std::vector<std::vector<std::string>> &resutlCsv, std::string nameFile, char sep){

    std::string lineString;
    std::ifstream myfile(nameFile);
    std::vector<int> contCol;
    int cont;

    // Verificando se o arquivo foi aberto corretamente
    if(myfile.is_open()){

        // Processo de leitura linha por linha
        while(getline(myfile, lineString)){
            cont = 0;
            resutlCsv.push_back(splitLine(lineString,sep,cont));
            contCol.push_back(cont);
        }
        myfile.close();

    } else {
        std::cout << "Erro! Não foi possível abrir esse arquivo" << endl;
        std::cout << "Finalizando programa..." << endl;
    }

    return contCol;
}

// 3. Função que imprime a idade dos usuarios segundo o especificado
void IdadeDosUsuarios(int *idad, int max){
    int aux = 0, soma = 0;
    float resul = 0.0;

    for (int i = 0; i < max; i++) { 
        soma += idad[i];
    }

    for (int i = 0; i < max; i++) { 
        for (int j = i; j < max; j++){ 
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

// 4. Numero de dependentes por adulto
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
