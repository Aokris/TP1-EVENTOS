/*
UNIVERSIDADE FEDERAL DE MINAS GERAIS - 2019/2
Programação e Desenvolvimento de Software II

Trabalho Prático - Parte 1
Sistema de gerenciamento de vendas de eventos e controle de usuários

Grupo:
- Bruno Flister Viana (2018048567)
- Ruhann Carlos Pereira de Almeida (2018105501)
- Vítor Gabriel Peixoto Pessoa (2018048451)

*/

#include <string>
#include <iostream>
#include <stdlib.h>
#include "funcoes.h"

using namespace std;

int main(){

/* ---------- Criação de Objetos - USUÁRIOS ---------- */
    vector<vector<string>> linha;    //iniciar o vetor da linha
    vector<string>::iterator lin; //iterator para linha

    vector<Crianca> crianca; //iniciar o vetor de crianças
    vector<Crianca>::iterator itc;
    vector<int> contCol;

    vector<Adulto> adulto; //iniciar o vetor de adultos
    vector<Adulto>::iterator ita;

    vector<Idoso> idoso; //iniciar o vetor de idosos
    vector<Idoso>::iterator itd;

/* ---------- Váriaveis Auxiliares - USUÁRIOS ---------- */
    int j = 0, k = 0, x = 0, n = 0, tam = 0; //variaveis auxiliares
    int sizeUsuarios = 0;
    unsigned int i = 0 ;

    int *depend = new int[1000];                //vetor de id dependentes
    depend[0] = -1;                       // usado para caso extremo de nenhum dependente
    int *idad = new int[1000];                  //vetor de idades
    int qcria = 0, qadult = 0, qidos = 0; //quantidade de usuarios
    int id = 0;
    float saldo = 0.0;
    string nome, categoria;

/* ---------- Tratando Entrada - USUÁRIOS ---------- */
    // FALTA IMPLEMENTAR A LEITURA CORRETAMENTE
    // OU SEJA, PEDIR PRA LER O NOME DO ARQUIVO QUE VAI SER ABERTO
    // IMPLEMENTAR DEPOIS QUE TIVERMOS TERMINADO, COISA SIMPLES E RAPIDA
    // USAR cin pra pedir o nome do arquivo pra ser aberto
    std::cout << "Para ler o arquivo, digite o nome de cada arquivo correspondente a seguir, no formato 'arquivo.csv'." << endl;
    std::cout << "O arquivo desejado preferencialmente deve se encontrar na mesma pasta do programa e *deve* usar ; como separador" << endl;
    string file_usuarios;
    std::cout << "Digite o nome do arquivo de USUARIOS que deseja abrir: ";
    std::cin >> file_usuarios;
    readCsv(linha, file_usuarios,','); // Inicializando entrada de usuários

    // Processando cada linha lida no arquivo
    for (i = 0; i < linha.size(); i++){
        j = 0;

        id = atoi (linha[i][j].c_str()); //armazena a id de cada usuario
        j++;
        
        categoria = linha[i][j]; //criança, adulto etc
        j++;

        nome = linha[i][j]; //nome do usuario
        j++;

        idad[i] = atoi (linha[i][j].c_str()); //idade do usuario
        j++;

        saldo = atof(linha[i][j].c_str());//saldo bancario
        j++;

        // Armazenando usuários no vector de sua categoria correspondente
        if(categoria == "crianca"){
            // Armazenando ID do responsável pela criança no vetor de dependentes
            depend[k] = atoi(linha[i][j].c_str());
            j++;

            qcria++;
            Crianca c(id, categoria, nome, idad[j], saldo, depend[k]);
            crianca.push_back(c);
            k++;
        } else if (categoria == "adulto"){
            qadult++;
            Adulto a(id, categoria, nome, idad[j], saldo);
            adulto.push_back(a);
        } else if (categoria == "idoso"){
            qidos++;
            Idoso ido(id, categoria, nome, idad[j], saldo);
            idoso.push_back(ido);
        }        
    }

    sizeUsuarios = linha.size();


/* ---------- Criação de Objetos - EVENTOS ---------- */
    vector<Cinema> cinema;
    vector<Cinema>::iterator itcine;

    vector<Show> show;
    vector<Show>::iterator itshow;

    vector<Boate> boate;
    vector<Boate>::iterator itboate;

    vector<TeatroFantoche> fantoche;
    vector<TeatroFantoche> itfan;

    vector<vector<string>> linha2; // Inicializando o vetor da linha de eventos
    map<double, int> precos;
    map<double, int>::iterator itprecos;
/* ---------- Váriaveis Auxiliares - EVENTOS ---------- */
    int IdEven = 0;
    int aux = 0;
    string categoriaEven;
    string subcategEven;
    string nomeEven;
    int *IdDono = new int[1000];
    int NumTipos = 0;
    int *ingEven = new int[1000];
    int *ValorEven = new int[1000];
    int *horarios = new int[1000];
    int quotaIdoso = 0;
    int duracao = 0;
    int horaIni = 0;
    int horaFim = 0;
    int abertura = 0;
    string *artistas = new string[1000];
    // Contadores
    int qBoate = 0, qShow = 0, qCine = 0, qFanto = 0;
    // Atalhos
    int maiorQuota = 0, idMaiorQuota = 0;
    int p = 0;
/* ---------- Tratando Entrada - EVENTOS ---------- */
    string file_eventos;
    std::cout << "Digite o nome do arquivo de EVENTOS que voce quer abrir: ";
    std::cin >> file_eventos;

    contCol = readCsv(linha2, file_eventos,','); // Inicializando entrada de eventos

    for (i = 0; i < linha2.size(); i++){
        j = 0;
        //Capturando os valores para passagem de parametros
        IdEven = atoi(linha2[i][j].c_str());
        j++;
        x++;
        categoriaEven = linha2[i][j];
        j++;
        x++;

        // Se o evento for do tipo cinema, ele não possui subcategoria
        if(categoriaEven != "cinema"){
            subcategEven = linha2[i][j];
            j++;
            x++;
        }

        nomeEven = linha2[i][j];
        j++;
        x++;
        IdDono[p] == atoi(linha2[i][j].c_str());
        j++;
        x++;
        p++;
        NumTipos = atoi(linha2[i][j].c_str());  // Nº de tipos de ingressos diferentes
        j++;
        x++;

        for (int k = 0; k < NumTipos; k++){
            ingEven[k] = atoi(linha2[i][j].c_str()); // Quantidade de ingressos do tipo k
            j++;
            x++;

            ValorEven[k] = atof(linha2[i][j].c_str()); // Valor do ingresso do tipo k
            j++;
            x++;

            //Contando ingressos por preço
            precos[ValorEven[k]] += ingEven[k];
        }
        
        // Se o evento não for do tipo Adulto, a leitura dos horários é realizada

        // Tratando os objetos
        if(categoriaEven == "infantil"){
            for (int k = 0; k < linha2[i].size() - (x+1); k++){
                horarios[k] = atoi(linha2[i][j].c_str());
                j++;
            }
            qFanto++;
            TeatroFantoche fan (horarios, IdEven, nomeEven, IdDono[p], ingEven, ValorEven);
            fantoche.push_back(fan);
        } else if(categoriaEven == "cinema"){
            for (int k = 0; k < linha2[i].size()-(x+1); k++){
                horarios[k] = stoi(linha2[i][j]);
                j++;
            }

            qCine++;

            duracao = atoi(linha2[i][j].c_str()); // Obtendo a duracao do cinema
            j++;

            Cinema cine(IdEven, nomeEven, IdDono[p], ingEven, ValorEven, horarios, duracao);
            cinema.push_back(cine);
        } else if(categoriaEven == "adulto"){
            quotaIdoso = atoi(linha2[i][j].c_str()); // Obtendo a quota para idosos do evento
            j++;

            if(quotaIdoso > maiorQuota){ // Atalho para obter o evento de maior quota
                maiorQuota = quotaIdoso;
                idMaiorQuota = IdEven;
            }

            if(subcategEven == "boate"){
                qBoate++;
                horaIni = atoi(linha2[i][j].c_str());// Obtendo horario de inicio da boate
                j++;
                horaFim = atoi(linha2[i][j].c_str());// Obtendo horario de fim da boate
                j++;
                Boate boa(quotaIdoso, horaIni, horaFim, IdEven, nomeEven, IdDono[p], ingEven, ValorEven);
                boate.push_back(boa);
            } else if(subcategEven == "show"){
                qShow++;
                abertura = atoi(linha2[i][j].c_str());// Obtendo horario de abertura do show 
                j++;
                int w = 0;
                for(; j <= linha2[i].size(); j++){
                    artistas[w] = linha2[i][j]; // Obtendo listagem dos artistas que apresentarão no show
                    w++;
                }
                Show sho(quotaIdoso, abertura, artistas, IdEven, nomeEven, IdDono[p], ingEven, ValorEven);
                show.push_back(sho);
            }
        }
        
        x = 0;
    }

/* ---------- Saída do Programa ---------- */

// 0 - USUÁRIOS
//   0.1 - Número de crianças, adultos e idosos
    std::cout << endl << "Número de usuários:" << endl;
    std::cout << "Crianças: " << qcria << endl;
    std::cout << "Adultos: " << qadult << endl;
    std::cout << "Idosos: " << qidos << endl << endl;

//   0.2 - Idade mínima, máxima e média para todos os usuários
    IdadeDosUsuarios(idad, j);

//   0.3 - Número mínimo, médio e máximo de dependentes por adulto
    if (depend[0] == -1){ // Atalho para o caso onde não há nenhum dependente na entrada
        std::cout << "Número de dependentes:" << endl;
        std::cout << "Minima: " << 0 << endl;
        std::cout << "Máxima: " << 0 << endl;
        std::cout << "Média: " << 0 << endl;
    } else {
        NumeroDependentes(depend, qcria, qadult + qidos);
    }

//   0.4 - Lista de dependentes por adulto
    std::cout << "Dependentes:" << endl;
    for(itc = crianca.begin(); itc != crianca.end();itc++){
        for(ita = adulto.begin(); ita != adulto.end(); ita++){
            if(itc->get_id_responsavel() == ita->get_id()){
                std::cout << ita->get_nome() << " (ID: " << ita->get_id() << "): " << itc->get_nome() << " (ID: " << itc->get_id_responsavel() << "): " << endl;
        }
    }}

    for(itc = crianca.begin(); itc != crianca.end();itc++){
        for(itd = idoso.begin(); itd != idoso.end(); itd++){
            if(itc->get_id_responsavel() == itd->get_id()){
                std::cout << itd->get_nome() << " (ID: " << itd->get_id() << "): " << itc->get_nome() << " (ID: " << itc->get_id_responsavel() << "): " << endl;
        }
    }}

// 1 - EVENTOS
//   1.1 - Número de eventos de cada tipo
    std::cout << endl << "Número de eventos:" << endl;
    std::cout << "Adultos:" << endl;
    std::cout << "\tBoate: " << qBoate << endl;
    std::cout << "\tShow: " << qShow << endl;
    std::cout << "Livres:" << endl;
    std::cout << "\tCinema: " << qCine << endl;
    std::cout << "Infantis:" << endl;
    std::cout << "\tTeatro de Fantoches: " << qFanto << endl << endl;

//   1.2 - Número de eventos vendidos por cada usuário
    std::cout << "Número de eventos que o usuário possui:" << endl;
    //Criação de map para armazenar numero eventos por dono
    map<int, int> dono;
    map<int, int>::iterator it;

    //Passagem para o Map
    for(int i = 0; i < p; i++){
        dono[IdDono[i]]++;
    }
     for(it = dono.begin(); it != dono.end(); it++){
        for(ita = adulto.begin(); ita != adulto.end(); ita++){
            if(it->first == ita->get_id()){
                std::cout<<ita->get_nome()<<" (ID: "<<ita->get_id()<<"): "<<it->second<<endl;
            }
        }
     }

//   1.3 - Nome e ID do evento com a maior cota para idosos
    std::cout << "Evento com maior cota para idoso:" << endl;
    for(itshow = show.begin(); itshow != show.end(); itshow++){
        if(itshow->get_id() == idMaiorQuota){
                std::cout << itshow->get_nome() << " (ID: " << itshow->get_id() << "): " << "maiorQuota" << endl;
        }
    }
    for(itboate = boate.begin(); itboate != boate.end(); itboate++){
        if(itboate->get_id() == idMaiorQuota){
                std::cout << itboate->get_nome() << " (ID: " << itboate->get_id() << "): " << "maiorQuota" << endl;
        }
    }


//   1.4 - Número total de bilhetes de cada valor
    std::cout << "Número de ingressos por preço:" << endl;
    for(itprecos = precos.begin(); itprecos != precos.end(); itprecos++){
        std::cout << "R$" << itprecos->first << ": " << itprecos->second << endl;
    }


    delete [] depend ;
    delete [] idad ;
    delete [] ingEven ;
    delete [] ValorEven ;
    delete [] horarios ;

    return 0;
}