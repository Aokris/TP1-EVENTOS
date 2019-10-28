#include "funcoes.h"

//1 Função le arquivo q le os arquivos csv
void le_arquivo (fstream &file, vector<string> &linha, int *qlinhas){

    //Variaveis axuiliares
    string buffer;
    string aux;
    vector<string>::iterator ptr; 
    int k = 0, n = 0, j = 0;

    //Loop de leitura de arquivo
    while(!file.eof()){
        getline(file, buffer,'\n');  //le cada linha para evitar espaços vazios
        for(int i = 0; i < buffer.length(); i++){
            if(buffer[i] == ','){ //separa cada palavra de acordo com delimitador ,
                linha.push_back(aux);
                aux.clear();
                n++;
                
            } else {
                aux = aux + buffer[i];
            }           
        }
        //Armazena palavras no vector linha
        linha.push_back(aux);
        aux.clear();
    }
    qlinhas[j] = n;
    j++;
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
