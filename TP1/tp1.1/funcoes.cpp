#include "funcoes.h"

void le_arquivo (fstream &file,vector<string> &linha){

    string buffer;
    vector<string>::iterator ptr; 

    while(!file.eof())
    {
        getline(file, buffer,';'); //ler cada coluna
        if(buffer == ""){
			continue;
		}else
        linha.push_back(buffer); //adicionar ao vetor da linha    
    }
}

void IdadeDosUsuarios(int *idad, int max){
    int aux=0,soma=0;
    float resul;
    for (int i = 0; i < max-1; i++) { 
        soma += idad[i];

        for (int j = 0; j < i-1; j++){ 

            if (idad[j] > idad[j+1]){ 

                aux = idad[j];
                idad[j] = idad[j+1];
                idad[j+1] = aux;
            } 
        } 
   }
   resul = soma/max-1;

   cout << "\nIdade dos usuários:" << endl;
   cout << "Minima: "<< idad[0] << endl;
   cout << "Máxima: "<< idad[max-1] << endl;
   cout << "Média: "<< resul << endl;
}

void NumeroDependentes (int *depend, int max){
    int aux=0,soma=0;
    float resul;
    for (int i = 0; i < max-1; i++) { 
        soma += i;
        cout << endl << "valor da soma dos numeros de dependentes :" << soma <<endl;

        for (int j = 0; j < i-1; j++){ 
            
            if (depend[j] > depend[j+1]){ 

                aux = depend[j];
                depend[j] = depend[j+1];
                depend[j+1] = aux;
            } 
        } 
    }
    resul = soma/max-1;
    cout << "\nNúmero de dependentes:" << endl;
    cout << "Minima: "<< 1 << endl;
    cout << "Máxima: "<< depend[max-1] << endl;
    cout << "Média: "<< resul << endl;
}