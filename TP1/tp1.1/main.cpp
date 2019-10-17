/*Sistema de gerenciamento de vendas de eventos e controle de usuarios

PDS2 

Trabalho Pratico-Parte 1
*/
#include "funcoes.h"

int main (){

    /*------USUARIOS-------*/
    int j=0,aux=0,k=0,i=0;//variaveis auxiliares

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

    for(lin = linha.begin(); lin < linha.end()+1; lin++){

//Coleta de dados para criação de objetos
        if (aux == 0 && linha[i] != "\0"){
            id = stoi(linha[i]);
            aux ++;

        }else if (aux == 1){
            categoria = linha[i];
            aux++;

        }else if (aux == 2){
            nome = linha[i];
            aux++;

        }else if(aux == 3){
            idad[j] = stoi(linha[i]);
            j++;
            aux++;

        }else if(aux == 4){
            saldo = stod(linha[i]);
            if(categoria == "criança"){
                aux++;
            }else{
                aux = -1;
            }

        }else if (aux == 5){
            depend[k] = stoi(linha[i]);
            aux = -1;
            k++;

        }else{//Criando objetos...

            if(categoria == "criança"){
                qcria++;
                Crianca c (id,categoria,nome,idad[j],saldo,depend[k]);
                crianca.push_back(c);

            }else if(categoria == "adulto"){
                qadult++;
                Adulto a (id,categoria,nome,idad[j],saldo);
                adulto.push_back(a);

            }else if(categoria == "idoso"){
                qidos++;
                Idoso i (id,categoria,nome,idad[j],saldo);
                idoso.push_back(i);

            }
            aux = 0;
            i--;
        }
        i++;
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




/*-------EVENTOS-----*/
/*------Dados para Criação de objetos*/
    j=0,aux=0,k=0,i=0;//variaveis auxiliares

    /*int *depend = new int;//vetor de id dependentes
    depend[0] = -1; // usado para caso extremo de nenhum dependente
    int *idad = new int;//vetor de idades*/
    int qboate = 0,qshow = 0,qcinema = 0, qteatro = 0;//quantidade de eventos

    int id2, dono, numtipo, quota_idoso = 0; //id do evento, id do dono, numero de tipos de ingressos, quota idoso; 
    int *valor_i = new int;//valor dos ingressos,
    int *capacidade = new int; //quantidade de ingresso
    string subcategoria,categoriaevent,nomeevent;//subcategoria, categoria:adulto,infantil, nome do evento

    vector<string> linha2; //iniciar o vetor da linha
    vector<TeatroFantoche> teatro; //iniciar o vetor de teatrofantoche
    vector<Cinema> cinema; //iniciar o vetor de cinema 
    vector<Boate> boate; //iniciar o vetor de boate
    vector<Show> show; //iniciar vetor de show
    vector<string>::iterator lin2;//iterator para linha
    fstream file2;//Cria a variavel arquivo
    
    file2.open("Entrada2.csv");//abre o arquivo

    if(!file2.is_open())//verifica se o arquivo foi aberto
    {
        cout << "Erro! Não foi possível abrir esse arquvio"<<'\n';
    }else{
        le_arquivo(file2, linha2);//le o arquivo e coloca na variavel linha
    }

    for(lin2 = linha.begin(); lin2 < linha.end()+1; lin2++){

//Coleta de dados para criação de objetos
        if (aux == 0 && linha2[i] != "\0"){
            id2 = stoi(linha2[i]);
            aux ++;

        }else if (aux == 1){
            if(linha2[i] == "cinema"){
                subcategoria = linha2[i];
                aux = 3;
                k = 0;

            }else{
            categoriaevent = linha2[i];
            if(categoriaevent == "adulto"){
                k = 1;                
            }else k = 2;

            aux++;}

        }else if (aux == 2){
            subcategoria = linha2[i];
            aux++;

        }else if(aux == 3){
            nomeevent = linha2[i];
            aux++;

        }else if(aux == 4){
            dono = stoi(linha2[i]);
            aux++;            
            }

        }else if (aux == 5){
            numtipo = stoi(linha2[i]);
            for(int h = 0; h < numtipo; h++){
                capacidade[h] = stoi(linha2[i]);
                valor_i[h] = stoi(linha2[i]);
            }

        }
        
        switch (k)
        {
        case 0:
            int *horario = new int;
            break;
        
        default:
            break;
        }

        else{//Criando objetos...

            if(subcategoria == "cinema"){
                qcinema++;
                Cinema cine (id2,nome,dono,capacidade,precos,depend[k]);
                crianca.push_back(c);

            }else if(categoria == "adulto"){
                qadult++;
                Adulto a (id,categoria,nome,idad[j],saldo);
                adulto.push_back(a);

            }else if(categoria == "idoso"){
                qidos++;
                Idoso i (id,categoria,nome,idad[j],saldo);
                idoso.push_back(i);

            }
            aux = 0;
            i--;
        }
        i++;
    }

    
    
    file.close();
    file2.close();
    return 0;
}