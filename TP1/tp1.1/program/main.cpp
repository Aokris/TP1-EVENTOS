/*
UNIVERSIDADE FEDERAL DE MINAS GERAIS - 2019/2
Programação e Desenvolvimento de Software II

Trabalho Prático - Parte 1
Sistema de gerenciamento de vendas de eventos e controle de usuários

Grupo:
- Bruno Flister Viana (2018048567)
- Ruhann Carlos Pereira de Almeida (coloca a matrícula aqui)
- Vítor Gabriel Peixoto Pessoa (2018048451)

*/

#include <string>
#include <iostream>
#include <stdlib.h>
#include "funcoes.h"

using namespace std;

int main(){

    int j = 0, k = 0, i = 0, x = 0, n = 0, tam = 0; //variaveis auxiliares
    int *qlinhas = new int[100];

    int *depend = new int;                //vetor de id dependentes
    depend[0] = -1;                       // usado para caso extremo de nenhum dependente
    int *idad = new int;                  //vetor de idades
    int qcria = 0, qadult = 0, qidos = 0; //quantidade de usuarios
    int id = 0;
    float saldo = 0.0;
    string nome, categoria;

    //-------Dados para criação de objetos(Usuários)-----------//
    vector<string> linha;    //iniciar o vetor da linha
    vector<Crianca> crianca; //iniciar o vetor de crianças
    vector<Crianca>::iterator itc;
    vector<Adulto> adulto; //iniciar o vetor de adultos
    vector<Adulto>::iterator ita;
    vector<Idoso> idoso; //iniciar o vetor de idosos
    vector<Idoso>::iterator itd;
    vector<string>::iterator lin; //iterator para linha
    fstream file, file1;          //Cria a variavel arquivo

    //------------Variaveis Eventos ---------------//
    int IdEven = 0;
    int aux = 0;
    string categoriaEven;
    string tipoEven;
    string nomeEven;
    int IdDono = 0;
    int qtipoEven = 0;
    int *ingEven = new int;
    double *ValorEven = new double;
    int *horarios = new int;

    //------Dados para criação de objetos(Eventos)-----------//

    vector<Cinema> cinema;
    vector<Show> show;
    vector<Boate> boate;
    vector<TeatroFantoche> fantoche;

    file.open("Usuarios.csv"); //abre o arquivo

    if (!file.is_open()){ // Verificando se o arquivo foi aberto corretamente
        cout << "Erro! Não foi possível abrir esse arquivo" << endl;
        cout << "Finalizando programa..." << endl;
        return EXIT_FAILURE;
    }else{
        le_arquivo(file, linha, qlinhas); //le o arquivo e coloca na variavel linha
    }

    for (lin = linha.begin(); lin < linha.end(); lin++)
        tam++;

    while (i != tam){
        id = atoi (linha[i].c_str()); //armazena a id de cada usuario
        i++;

        categoria = linha[i]; //criança, adulto etc
        i++;

        nome = linha[i]; //nome do usuario
        i++;

        idad[j] = atoi (linha[i].c_str()); //idade do usuario
        j++;
        i++;

        saldo = strtod(linha[i].c_str(), NULL); //saldo bancario
        i++;

        if (categoria == "crianca"){//se criança pega o dependente
            depend[k] = atoi (linha[i].c_str()); //achar outra forma de somar o numero maximo de dependetes pois queremos imprimir o numero maximo por adulto
            i++;
        }if (categoria == "crianca"){
            qcria++;
            Crianca c(id, categoria, nome, idad[j], saldo, depend[k]);
            crianca.push_back(c);
            k++;
        }else if (categoria == "adulto"){
            qadult++;
            Adulto a(id, categoria, nome, idad[j], saldo);
            adulto.push_back(a);
        }else if (categoria == "idoso"){
            qidos++;
            Idoso ido(id, categoria, nome, idad[j], saldo);
            idoso.push_back(ido);
        }
    }

    file1.open("Entrada_eventos.csv"); //abre o arquivo

    if (!file1.is_open()){ // Verificando se o arquivo foi aberto corretamente
        cout << "Erro! Não foi possível abrir esse arquivo" << endl;
        cout << "Finalizando programa..." << endl;
        return EXIT_FAILURE;
    }else{
        le_arquivo(file, linha, qlinhas); //le o arquivo e coloca na variavel linha
    }

    tam = 0;
    i = 0;

    for (lin = linha.begin(); lin < linha.end() - 1; lin++){
        tam++;
    } //pega quantas palavras tem no arquivo

    while (i != tam){

        //Capturação dos valores para passagem de parametros

        IdEven = atoi (linha[i].c_str());
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
        qtipoEven = atoi (linha[i].c_str());
        i++;
        x++;

        for (int k = 0; k < qtipoEven; k++){
            ingEven[k] = atoi (linha[i].c_str());
            i++;
            x++;
            ValorEven[k] = strtod(linha[i].c_str(), NULL);
            i++;
            x++;
        }
        
        for (int k = 0; k < qlinhas[n] - x; k++){
            horarios[k] = atoi (linha[i].c_str());
            i++;
            n++;
        }
        x = 0;
        // Area para cria os objetos de acordo com o tipo ou categoria
    }

    //---------Saida do Programa----------//
    cout << "\nNúmero de usuários:" << endl;
    cout << "Crianças: " << qcria << endl;
    cout << "Adultos: " << qadult << endl;
    cout << "Idosos: " << qidos << endl
         << endl;

    //   0.2 - Idade mínima, máxima e média para todos os usuários
    IdadeDosUsuarios(idad, j);
    cout << endl;

    //   0.3 - Número mínimo, médio e máximo de dependentes por adulto
    IdadeDosUsuarios(idad, j);
    if (depend[0] == -1){
        cout << "\nNúmero de dependentes:" << endl;
        cout << "Minima: " << 0 << endl;
        cout << "Máxima: " << 0 << endl;
        cout << "Média: " << 0 << endl;
    }else{
        if (qcria == (qcria + qadult + qidos)){
            NumeroDependentes(depend, qcria, qadult + qidos);
        }else{
            NumeroDependentes(depend, 0, qidos + qadult);
        }
    }
    
    //   0.4 - Lista de dependentes por adulto
    cout << "Dependentes:" << endl;
    for(itc = crianca.begin(); itc<crianca.end();itc++){
        for(ita = adulto.begin(); ita!=adulto.end();ita++){
            if(itc->get_id_responsavel() == ita->get_id()){
                cout<<ita->get_nome()<<" (ID: "<<ita->get_id()<<"): "<<itc->get_nome()<<" (ID: "<<itc->get_id_responsavel()<<"): "<<endl;
            }
        }
    }

    for(itc = crianca.begin(); itc<crianca.end();itc++){
        for(itd = idoso.begin(); itd!=idoso.end();itd++){
            if(itc->get_id_responsavel() == itd->get_id()){
                cout<<itd->get_nome()<<" (ID: "<<itd->get_id()<<"): "<<itc->get_nome()<<" (ID: "<<itc->get_id_responsavel()<<"): "<<endl;
            }
        }
    }
    
    // 1 - EVENTOS
    //   1.1 - Número de eventos de cada tipo
    cout << "Número de eventos:" << endl;
    cout << "Adultos:" << endl;
    cout << "Livres:" << endl;
    cout << "Infantis:" << endl << endl;

    //   1.2 - Número de eventos vendidos por cada usuário
    cout << "Número de eventos que o usuário possui:" << endl;

    //   1.3 - Nome e ID do evento com a maior cota para idosos
    cout << "Evento com maior cota para idoso:" << endl;

    //   1.4 - Número total de bilhetes de cada valor
    cout << "Número de ingressos por preço:" << endl;
    delete(qlinhas);
    delete(depend);
    delete(idad);
    delete(ingEven);
    delete(ValorEven);
    delete(horarios);

    return 0;
}