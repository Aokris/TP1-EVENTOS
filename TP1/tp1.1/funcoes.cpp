#include "funcoes.h"

void le_arquivo (fstream &file,vector<string> &linha){

    string buffer;
    vector<string>::iterator ptr; 

    while(!file.eof())
    {
        getline(file, buffer,';'); //ler cada coluna
        if(buffer.length() == 0){
            cout<<"bruno";
			continue;
		}else
        linha.push_back(buffer); //adicionar ao vetor da linha    
    }
}

void IdadeDosUsuarios(int *idad, int max){
    int aux=0,soma=0;
    float resul;

    for (int i = 0; i < max; i++) { 
        cout<<idad[i]<<endl;
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
   cout << "Média: "<< resul << endl;
}

void NumeroDependentes (int *depend, int max){
    int aux=0,soma=0;
    float resul;

    for (int i = 0; i < max; i++){ 
        soma += depend[i];

        for (int j = 0; j < i; j++){ 
            
            if (depend[i] < depend[j]){ 

                aux = depend[i];
                depend[i] = depend[j];
                depend[j] = aux;
            } 
        } 
    }
    resul = (float)soma/max;

    cout << "\nNúmero de dependentes:" << endl;
    cout << "Minima: "<< depend[0] << endl;
    cout << "Máxima: "<< depend[max-1] + 1 << endl;//numero de dependetes deve ser por adulto (ver exemplo da professora)
    cout << "Média: "<< resul << endl;
}