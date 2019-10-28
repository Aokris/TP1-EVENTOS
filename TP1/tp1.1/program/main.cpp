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

#include "funcoes.h"

int main(){

/* ---------- Criação de Objetos - USUÁRIOS ---------- */
    vector<string> linha; //iniciar o vetor da linha
    vector<string>::iterator lin;//iterator para linha

    vector<Crianca> crianca; //iniciar o vetor de crianças
    vector<Crianca>::iterator itc;

    vector<Adulto> adulto; //iniciar o vetor de adultos
    vector<Adulto>::iterator ita; 

    vector<Idoso> idoso; //iniciar o vetor de idosos
    vector<Idoso>::iterator itd;

/* ---------- Váriaveis Auxiliares - USUÁRIOS ---------- */
    int j = 0 , aux = 0, k = 0, i = 0, x = 0, n = 0, tam = 0; //variaveis auxiliares
    int *qlinhas = new int[100]; // Quantidade de linhas na entrada

    int *depend = new int;//vetor de id dependentes
    depend[0] = -1; // usado para caso extremo de nenhum dependente
    int *idad = new int;//vetor de idades
    int qcria = 0, qadult = 0, qidos = 0;//quantidade de usuarios
    int id;
    float saldo;
    string nome, categoria;

/* ---------- Tratando Entrada - USUÁRIOS ---------- */
    fstream f_users; // Criando a variável do arquivo de usuários
    f_users.open("Entrada.csv"); // Inicializando entrada de usuários
    
    if(!f_users.is_open()){ // Verificando se o arquivo foi aberto corretamente
        std::cout << "Erro! Não foi possível abrir esse arquivo" << endl;
        std::cout << "Finalizando programa..." << endl;
        return EXIT_FAILURE;
    } else {
        le_arquivo(f_users, linha, qlinhas);//le o arquivo e coloca na variavel linha
    }

    for(lin = linha.begin(); lin < linha.end(); lin++){
        tam++;
    }

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

        // Armazenando usuários no vector de sua categoria correspondente
        if(categoria == "crianca"){
            // Armazenando ID do responsável pela criança no vetor de dependentes
            depend[k] = stoi(linha[i]);
            i++;

            qcria++;
            Crianca c(id, categoria, nome, idad[j], saldo, depend[k]);
            crianca.push_back(c);
            k++;
        } else if(categoria == "adulto"){
            qadult++;
            Adulto a(id, categoria, nome, idad[j], saldo);
            adulto.push_back(a);
        } else if(categoria == "idoso"){
            qidos++;
            Idoso ido(id, categoria, nome, idad[j], saldo);
            idoso.push_back(ido);
        }        
   }
   f_users.close(); // Fechando o arquivo de usuários

/* ---------- Criação de Objetos - EVENTOS ---------- */
    vector<Cinema> cinema;
    vector<Show> show;
    vector<Boate> boate;
    vector<TeatroFantoche> fantoche;
    linha.clear();

/* ---------- Váriaveis Auxiliares - EVENTOS ---------- */
    int IdEven;
    string categoriaEven;
    string tipoEven;
    string nomeEven;
    int IdDono;
    int qtipoEven;
    int *ingEven = new int;
    double *ValorEven = new double;
    int *horarios = new int;

/* ---------- Tratando Entrada - EVENTOS ---------- */
    fstream f_events; // Criando variável do arquivo de eventos
    f_events.open("Entrada_eventos.csv"); // Inicializando entrada de eventos
    
    if(!f_events.is_open()){ // Verificando se o arquivo foi aberto corretamente
        std::cout << "Erro! Não foi possível abrir esse arquivo" << endl;
        std::cout << "Finalizando programa..." << endl;
        return EXIT_FAILURE;
    } else {
        le_arquivo(f_events, linha, qlinhas);//le o arquivo e coloca na variavel linha
    }

    tam = 0;
    i = 0;

    for(lin = linha.begin(); lin < linha.end()-1; lin++){
        tam++;
    }//pega quantas palavras tem no arquivo
 
    while(i != tam){ //Capturando os valores para passagem de parametros
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

        for(int k = 0; k < qtipoEven; k++){
            ingEven[k] = stoi(linha[i]);
            i++;
            x++;
            ValorEven[k] = stod (linha[i]);
            i++;
            x++;
        }
        for (int k = 0; k < qlinhas[n]-x; k++){
            horarios[k] = stoi(linha[i]);
            i++;
            n++;
        }
        x = 0;
        /*Area para cria os objetos de acordo com o tipo ou categoria*/
       
    }
    f_events.close(); // Fechando o arquivo de eventos

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
    for(itc = crianca.begin(); itc < crianca.end();itc++){
        for(ita = adulto.begin(); ita != adulto.end(); ita++){
            if(itc->get_id_responsavel() == ita->get_id()){
                std::cout << ita->get_nome() << " (ID: " << ita->get_id() << "): " << itc->get_nome() << " (ID: " << itc->get_id_responsavel() << "): " << endl;
        }
    }}

    for(itc = crianca.begin(); itc < crianca.end();itc++){
        for(itd = idoso.begin(); itd != idoso.end(); itd++){
            if(itc->get_id_responsavel() == itd->get_id()){
                std::cout << itd->get_nome() << " (ID: " << itd->get_id() << "): " << itc->get_nome() << " (ID: " << itc->get_id_responsavel() << "): " << endl;
        }
    }}

// 1 - EVENTOS
//   1.1 - Número de eventos de cada tipo
    std::cout << endl << "Número de eventos:" << endl;
    std::cout << "Adultos:" << endl;
    std::cout << "Livres:" << endl;
    std::cout << "Infantis:" << endl << endl;

//   1.2 - Número de eventos vendidos por cada usuário
    std::cout << "Número de eventos que o usuário possui:" << endl;

//   1.3 - Nome e ID do evento com a maior cota para idosos
    std::cout << "Evento com maior cota para idoso:" << endl;

//   1.4 - Número total de bilhetes de cada valor
    std::cout << "Número de ingressos por preço:" << endl;

    return 0;
}