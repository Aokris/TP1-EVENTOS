/*Sistema de gerenciamento de vendas de eventos e controle de usuarios

PDS2 

Trabalho Pratico-Parte 1
*/
#include "funcoes.h"

int main (){
    int j=0,aux=0,k=0,i=0,tam = 0;//variaveis auxiliares

    int *depend = new int;//vetor de id dependentes
    depend[0] = -1; // usado para caso extremo de nenhum dependente
    int *idad = new int;//vetor de idades
    int qcria = 0,qadult = 0,qidos = 0;//quantidade de usuarios

/*-------Dados para criação de objetos-----------*/
    int id;
    float saldo;
    string nome,categoria;

    vector<string> linha; //iniciar o vetor da linha
    vector<Crianca> crianca; //iniciar o vetor de crianças
    vector<Adulto> adulto; //iniciar o vetor de adultos 
    vector<Idoso> idoso; //iniciar o vetor de idosos
    vector<string>::iterator lin;//iterator para linha
    fstream file;//Cria a variavel arquivo
    
    file.open("Entrada.csv");//abre o arquivo

    if(!file.is_open())//verifica se o arquivo foi aberto
    {
        cout << "Erro! Não foi possível abrir esse arquvio"<<'\n';
    }else{
        le_arquivo(file, linha);//le o arquivo e coloca na variavel linha
    }

    for(lin = linha.begin(); lin < linha.end()-1; lin++){
        tam++;
    }//pega quantas palavras tem no arquivo
 
        while(i != tam){
         
        id = stoi(linha[i]);//armazena a id de cada usuario
        i++;
        

        categoria = linha[i];//criança, adulto etc
        i++;

        nome = linha[i];//nome do usuario
        i++;

        idad[j] = stoi(linha[i]);//idade do usuario
        j++;    
        i++;

        saldo = stod(linha[i]);//saldo bancario
        i++;

        if(categoria == "crianca"){//se criança pega o dependente
            depend[k] = stoi(linha[i]);//achar outra forma de somar o numero maximo de dependetes pois queremos imprimir o numero maximo por adulto
            i++;
        }

        if(categoria == "crianca"){
                qcria++;
                Crianca c (id,categoria,nome,idad[j],saldo,depend[k]);
                crianca.push_back(c);
                k++;

            }else if(categoria == "adulto"){
                qadult++;
                Adulto a (id,categoria,nome,idad[j],saldo);
                adulto.push_back(a);

            }else if(categoria == "idoso"){
                qidos++;
                Idoso ido (id,categoria,nome,idad[j],saldo);
                idoso.push_back(ido);

            }        
   }

//---------Saida do Programa----------//
    cout << "\nNúmero de usuários:" << endl;
    cout << "Crianças: " << qcria << endl;
    cout << "Adultos: " << qadult << endl;
    cout << "Idosos: " << qidos << endl;

    IdadeDosUsuarios(idad,j);
    if (depend[0] == -1){
        cout << "\nNúmero de dependentes:" << endl;
        cout << "Minima: "<< 0 << endl;
        cout << "Máxima: "<< 0 << endl;
        cout << "Média: "<< 0 << endl;
    }else{
        NumeroDependentes(depend,k);
    }

    file.close();

    return 0;
}