/*Sistema de gerenciamento de vendas de eventos e controle de usuarios

PDS2 

Trabalho Pratico-Parte 1
*/
#include "funcoes.h"

int main (){
    int j=0,aux=0,k=0,i=0,tam = 0, n = 0, x;//variaveis auxiliares
    int *qlinhas = new int;

/*-------------Variaveis Usuários---------------*/

    int *depend = new int;//vetor de id dependentes
    depend[0] = -1; // usado para caso extremo de nenhum dependente
    int *idad = new int;//vetor de idades
    int qcria = 0,qadult = 0,qidos = 0;//quantidade de usuarios
    int id;
    float saldo;
    string nome,categoria;

/*-------Dados para criação de objetos(Usuários)-----------*/

    vector<string> linha; //iniciar o vetor da linha
    vector<Crianca> crianca; //iniciar o vetor de crianças
    vector<Adulto> adulto; //iniciar o vetor de adultos 
    vector<Idoso> idoso; //iniciar o vetor de idosos
    vector<string>::iterator lin;//iterator para linha
    fstream file,file1;//Cria a variavel arquivo

/*------------Variaveis Eventos ---------------*/
    int IdEven;
    string categoriaEven;
    string tipoEven;
    string nomeEven;
    int IdDono;
    int qtipoEven;
    int *ingEven = new int;
    double *ValorEven = new double;
    int *horarios = new int;

/*-------Dados para criação de objetos(Eventos)-----------*/




    
    file.open("Usuarios.csv");//abre o arquivo

    if(!file.is_open())//verifica se o arquivo foi aberto
    {
        cout << "Erro! Não foi possível abrir esse arquvio"<<'\n';
    }else{
        le_arquivo(file, linha, qlinhas);//le o arquivo e coloca na variavel linha
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

   file1.open("Eventos.csv");//abre o arquivo dos eventos 

    if(!file1.is_open())//verifica se o arquivo foi aberto
    {
        cout << "Erro! Não foi possível abrir esse arquvio"<<'\n';
    }else{
        le_arquivo(file1, linha, qlinhas);//le o arquivo e coloca na variavel linha
    }

    tam = 0;
    i = 0;

    for(lin = linha.begin(); lin < linha.end()-1; lin++){
        tam++;
    }//pega quantas palavras tem no arquivo
 
    while(i != tam){

//Capturação dos valores para passagem de parametros

        IdEven = stoi(linha[i]);
        i++;
        x++;
        categoriaEven = linha[i];
        i++;
        x++;
        tipoEven = linha[i];
        i++;
        x++;
        nomeEven = linha[i];
        i++;
        x++;
        qtipoEven = stoi(linha[i]);
        i++;
        x++;

        for(int k=0;k<qtipoEven;k++){
            ingEven[k] = stoi(linha[i]);
            i++;
            x++;
            ValorEven[k] = stod (linha[i]);
            i++;
            x++;
        }
        for (int k = 0; k < qlinhas[n]-x;k++){
            horarios[k] = stoi(linha[i]);
            i++;
            n++;
        }
        x = 0;
        /* Area para cria os objetos de acordo com o tipo ou categoria 
        
        
        */
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
    file1.close();

    return 0;
}