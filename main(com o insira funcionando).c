/*Trabalho sobre Árvore B, apresentado á disciplina de Organização e Recuperação de Informação, ministrada pelo docente Jander Moreira na Universidade Fedeal de São Carlos - UFSCar
Data: 01 de Fevereiro de 2017
Autores, Registro Acadêmico (RA):
    Bruna Zamith, 628093
    Leonardo Utida, 628182
    Marcos Faglioni, 628301
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Define a estrutura do Nó da Arvore B*/
    typedef struct noArvore No;
    struct noArvore{
    int nElementos;
    float* elementos;
    No* filhos;
    int tipo; //0-> raiz // 1->folha // 2-> meio
    int ehRaiz;
    int ehFolha;
    int ordem;
    };
///*****************************************************************///
///PROTÓTIPO DAS FUNÇÕES///
/*Função "entradaComandoInicial"
Recebe os primeiros comandos do usuário;
Retorna 0 se for a tela help, ou comando 1 se for a inicialização da arvore
Por referência, o inteiro referente à ordem da árvore é retornado*/
int entradaComandoInicial(int*);

/*Função "entradaComandoSecundario"
Recebe o segundo comando do usuário;
Retorna 1 se for a tela insercao, ou comando 2 se for busca na arvore, ou 3 se o comando for encerrar programa*/
int entradaComandoSecundario();

/*Função "criaArvoreB" e "criaNo"
Cria a ArvoreB*/
void criaArvoreB(int, No*);
void criaNoFolha(int, No*);
void criaNo(int ordem, No* no);

/*Função "insere"
Chamada dentro da função insereRecursivo*/
int insere(No *atual, float chave);

int insereComNo(No *atual, float chave, No* novo);

void divida(No* atual, float novaChave,No* dir, No* novo, float* promovida);

int BusqueEInsira(No* atual, float chave, int* promocao, float* promovida, No* novo);

/*Função "insereRecursivo"
Recebe o No atual e faz a inserção*/
int insereFinal(No *raiz, float chave);

/*Função "buscaBin"
Chamada dentro da função buscaRecursiva*/
int BuscaBin(No atual, float chave);

/*Função "buscaRecursiva"
Recebe a Arvore e faz a busca*/
int BuscaRecursiva(No atual, float chave);

///*****************************************************************///
///FUNÇÃO PRINCIPAL///
int main(){


    //TESTE DO BUSCA RECURSIVA
    /*No teste1, testeCria1;
    criaArvoreB(4, &teste1);
    teste1.ehFolha = 0;
    criaNoFolha(4, &teste1.filhos[0]);
    criaNoFolha(4, &teste1.filhos[1]);
    criaNoFolha(4, &teste1.filhos[2]);
    criaNoFolha(4, &testeCria1);
    insere(&testeCria1, 21);
    insere(&testeCria1, 22);


    insere(&teste1, 10);
    insere(&teste1, 30);

    insere(&teste1.filhos[0], 2.1);
    insere(&teste1.filhos[0], 1.1);
    insere(&teste1.filhos[1], 12.1);
    insere(&teste1.filhos[1], 11.1);
    insere(&teste1.filhos[2], 31);
    insere(&teste1.filhos[2], 32);

    insereComNo(&teste1, 20, &testeCria1);
    int i;
    for(i = 0; i<teste1.filhos[3].nElementos; i++){
        printf("Elemento de testeS: %f\n", teste1.filhos[3].elementos[i]);
    }


    if(BuscaRecursiva(teste1, 31)){
        printf("ACHOU\n");
    }else{
        printf("NAO ACHOU T.T\n");
    }*/



    //TESTE DO DIVIDA
    /*No testeS, novo;
    criaNoFolha(7, &testeS);
    insere(&testeS, 2);
    insere(&testeS, 3);
    insere(&testeS, 4);
    insere(&testeS, 5);
    insere(&testeS, 6);
    insere(&testeS, 7);
    int i;
    float promovida = 1;

    divida(&testeS, promovida, &novo, &promovida);
    printf("promovida: %f\n", promovida);
    for(i = 0; i<testeS.nElementos; i++){
        printf("Elemento de testeS: %f\n", testeS.elementos[i]);
    }
    for(i = 0; i<novo.nElementos; i++){
        printf("Elemento de novo: %f\n", novo.elementos[i]);
    }*/

    //TESTE DO BUSQUEeINSIRA
    /*No Teste;
    criaNoFolha(5, &Teste);
    Teste.ehRaiz=1;
    int promocao, promovida;
    No novo;
    No aux;
    BusqueEInsira(&Teste, 1, &promocao, &promovida, &novo);
    BusqueEInsira(&Teste, 2, &promocao, &promovida, &novo);
    BusqueEInsira(&Teste, 3, &promocao, &promovida, &novo);
    BusqueEInsira(&Teste, 4, &promocao, &promovida, &novo);
    BusqueEInsira(&Teste, 5, &promocao, &promovida, &novo);
    int i;
    for(i = 0; i<Teste.nElementos; i++){
        printf("Elemento de teste: %f\n", Teste.elementos[i]);
    }
    for(i = 0; i<Teste.filhos[0].nElementos; i++){
        printf("Elemento de filho 1: %f\n", Teste.filhos[0].elementos[i]);
    }
    for(i = 0; i<Teste.filhos[1].nElementos; i++){
        printf("Elemento de filho 2: %f\n", Teste.filhos[1].elementos[i]);
    }*/

    //TESTE DO NOVO DIVIDA

    /*No divTeste, dir, novo;
    criaNo(5, &divTeste);
    criaNo(5, &dir);
    float promovida;
    insere(&divTeste, 1);
    insere(&divTeste, 2);
    insere(&divTeste, 3);
    insere(&divTeste, 4);
    insere(&dir, 17);
    printf("N elementos: %d\n", dir.nElementos);



    divida(&divTeste, 5, &dir, &novo, &promovida);
    int i;
    for(i = 0; i<divTeste.nElementos; i++){
        printf("Elemento de divTeste: %f\n", divTeste.elementos[i]);
    }
    for(i = 0; i<novo.nElementos; i++){
        printf("Elemento de novo: %f\n", novo.elementos[i]);
    }
    printf("valor: %f\n",novo.filhos[2].elementos[2]);
    printf("VALOR DA PROMOVIDA: %f\n", promovida);*/

    //TESTE GERAL:

    No raizz;
    criaArvoreB(5, &raizz);
    insereFinal(&raizz, 10);
    insereFinal(&raizz, 20);
    insereFinal(&raizz, 30);
    insereFinal(&raizz, 40);
    insereFinal(&raizz, 50);
    insereFinal(&raizz, 60);
    insereFinal(&raizz, 70);
    insereFinal(&raizz, 80);
    insereFinal(&raizz, 90);
    insereFinal(&raizz, 100);
    insereFinal(&raizz, 110);
    insereFinal(&raizz, 120);
    insereFinal(&raizz, 130);
    insereFinal(&raizz, 140);
    insereFinal(&raizz, 150);
    insereFinal(&raizz, 160);
    insereFinal(&raizz, 170);

    int i;
    for(i = 0; i < raizz.nElementos; i++){
        printf("Elementos da raiz: %f\n", raizz.elementos[i]);
    }
    printf("SEPARA\n");
    for(i = 0; i < raizz.filhos[0].nElementos; i++){
        printf("Elementos do filho 1: %f\n", raizz.filhos[0].elementos[i]);
    }
    for(i = 0; i < raizz.filhos[1].nElementos; i++){
        printf("Elementos do filho 2: %f\n", raizz.filhos[1].elementos[i]);
    }/*
    for(i = 0; i < raizz.filhos[2].nElementos; i++){
        printf("Elementos do filho 3: %f\n", raizz.filhos[2].elementos[i]);
    }
    for(i = 0; i < raizz.filhos[3].nElementos; i++){
        printf("Elementos do filho 4: %f\n", raizz.filhos[3].elementos[i]);
    }
    for(i = 0; i < raizz.filhos[4].nElementos; i++){
        printf("Elementos do filho 5: %f\n", raizz.filhos[4].elementos[i]);
    }*/
    for(i = 0; i < raizz.filhos[1].filhos[0].nElementos; i++){
        printf("Elementos do filho do FIM: %f\n", raizz.filhos[1].filhos[0].elementos[i]);
    }


    if(BuscaRecursiva(raizz, 10)){
        printf("ACHOU\n");
    }else{
        printf("NAO ACHOU T.T\n");
    }







    /*Chama o menu inicial (recebe o comando do usuário)*/
    printf("****Programa ArvoreB****\nComandos:\narvoreB -t [int] >> Inicializa a arvore definindo o grau minimo [int]\narvoreB -h [] >> Abre o menu de instrucoes\nDigite o Comando:\n");
    int comando,ordem; //cria os inteiros que receberão o comando e a ordem minima da arvore
    comando=entradaComandoInicial(&ordem); //recebe comando do usuario

    while(comando==0){//se o comando for a tela help
        printf("\n\nO programa arvoreB cria uma arvore B.\nPara inicializar, digite arvoreB -t [int], definindo o grau minimo [int]\nDigite o Comando:\n");
        comando=entradaComandoInicial(&ordem); //recebe novamenete o comando do usuario
    }

    /*Cria a ArvoreB*/
    No raiz;
    criaArvoreB(ordem, &raiz); //cria a Arvore B

    /*Chama o menu secundário (recebe o comando do usuario)*/
    comando = entradaComandoSecundario(); //chama o comando secundario do usuario (insercao, busca ou sair)

    No teste;

    while(comando!=3){
        if(comando==1){ //se o comando for 1 (insere)
            float chave;
            insereFinal(&teste, chave); //insere na arvore
        }
        if(comando==2){ //se o comando for 2 (busca)
            float chave;
            printf("Digite o valor que deseja buscar: ");
            scanf("%d", &chave);
            //BuscaRecursiva(&teste, chave); //busca na arvore
        }
        if(comando==3){ //encerra o programa
            return 0;
        }
        comando = entradaComandoSecundario(); //chama o comando secundario do usuario (insercao, busca ou sair)
    }

    return 0;
}

///*****************************************************************///
///FUNÇÕES///
/*Função verifica entrada do comando inicial*/
int entradaComandoInicial(int *ordem){
    char entrada[20];
    char text[10];
    gets(entrada); //recebe a string entrada do usuario
    strncpy(text,entrada,9);
    text[9]='\0';
    while(strcmp(text,"arvoreB -")){ //se os primeiros 9 caracteres forem "arvoreB -"
        while(entrada[9]!='t' && entrada[9]!='h'){ //se o 10o caracter for t ou h
            printf("\nComando invalido, tente novamente\n"); //senão
            gets(entrada);
            strncpy(text,entrada,9);
            text[9]='\0';
        }
    }
    if(entrada[9]=='t'){ //se o comando for t
        *ordem=((int)entrada[11])-((int)'0'); //recebe a ordem
        return 1;
    }
    if(entrada[9]=='h'){ //se o comando for h
        return 0;
    }
}

/*Função verifica entrada do comando inicial*/
int entradaComandoSecundario(){
    int opcao;
    while(opcao !=3){
            printf("\nFavor escolher: ");
            printf("1-Insercao, 2-Busca, 3-Sair\n");
            printf("O que deseja fazer: ");
            scanf("%d", &opcao);

            switch(opcao){
            case 1:
                printf("Opcao 1 (Insercao) escolhida\n");
                return 1;

            case 2:
                printf("Opcao 2 (Busca) escolhida\n");
                return 2;

            case 3:
                printf("Programa encerrado\n");
                opcao=3;
                return 3;

            default:
                printf("ERRO: Opcao invalida! Tente Novamente!\n");
                return entradaComandoSecundario();
            }
        }
}

/*Função cria a ArvoreB*/
void criaArvoreB(int ordem, No* raiz){
    raiz->ordem = ordem;
    raiz->elementos = (float*)malloc((ordem -1) * sizeof(float));
    raiz->filhos = (No*)malloc((ordem) * sizeof(No));
    raiz->tipo = 0; //raiz
    raiz->nElementos = 0;
    raiz->ehRaiz = 1;
    raiz->ehFolha = 1;
}

/*Função cria Nó*/
void criaNoFolha(int ordem, No* no){
    no->ordem = ordem;
    no->elementos = (float*)malloc((ordem -1) * sizeof(float));
    no->filhos = (No*)malloc((ordem) * sizeof(No));
    no->nElementos = 0;
    no->tipo = 1; //folha
    no->ehRaiz = 0;
    no->ehFolha = 1;
}

void criaNo(int ordem, No* no){
    no->ordem = ordem;
    no->elementos = (float*)malloc((ordem -1) * sizeof(float));
    no->filhos = (No*)malloc((ordem) * sizeof(No));
    no->nElementos = 0;
}

/*Função BuscaBin*/
int BuscaBin(No atual, float chave){
    if(atual.nElementos == 0){
        printf("O vetor buscado esta vazio\n");
        return 0;
    }else{
        int p, u, m;
        p=0;
        u = atual.nElementos -1;
        while(1){
            m = floor((p+u)/2);
            if(atual.elementos[m] == chave){
                printf("CHAVE ENCONTRADA\n");
                return 1;
            }
            else{
                if(atual.elementos[m] < chave){
                    p = m;
                }else{
                    u = m;
                }
                if(p+1 == u){
                    if(atual.elementos[p] == chave){
                        printf("CHAVE ENCONTRADA\n");
                        return 1;
                    }
                    else if(atual.elementos[u] == chave){
                        printf("CHAVE ENCONTRADA\n");
                        return 1;
                    }else{
                        printf("CHAVE NAO ENCONTRADA\n");
                        return 0;
                    }
                }
                if(p == u){
                    if(atual.elementos[p] == chave){
                        printf("CHAVE ENCONTRADA\n");
                        return 1;
                    }else{
                        printf("CHAVE NAO ENCONTRADA\n");
                        return 0;
                    }
                }
            }
        }
    }
}

/*Função BuscaRecursiva*/
int BuscaRecursiva(No atual, float chave){
    if(atual.nElementos == 0){
        return 0;
    }else{
        if(BuscaBin(atual, chave)){
            return 1;
        }else{
            if(atual.ehFolha == 1){
                return 0;
            }else{
                int i;
                for(i = 0; i < atual.nElementos;i++){
                    if(chave < atual.elementos[i]){
                        break;
                    }
                }
                BuscaRecursiva(atual.filhos[i], chave);
            }
        }
    }

}


void divida(No* atual, float novaChave, No* dir, No* novo, float* promovida){
    criaNo(atual->ordem, novo);
    novo->tipo = atual->tipo;
    novo->ehFolha = atual->ehFolha;
    int m;
    m = floor((atual->ordem)/2);
    if(novaChave < atual->elementos[m]){
        int i;
        int pos = 0;
        int fim = atual->nElementos;
        for(i = m; i<fim; i++){
            novo->elementos[pos] = atual->elementos[i];
            novo->filhos[pos+1] = atual->filhos[i+1];
            novo->nElementos++;
            atual->nElementos--;
            pos++;
        }
        insereComNo(atual, novaChave, dir);
    }else{
        int i;
        int pos = 0;
        int fim = atual->nElementos;
        for(i = m+1; i<fim; i++){
            novo->elementos[pos] = atual->elementos[i];
            novo->filhos[pos+1] = atual->filhos[i+1];
            novo->nElementos++;
            atual->nElementos--;
            pos++;
        }
        insereComNo(novo, novaChave, dir);
    }
    novo->filhos[0] = atual->filhos[atual->nElementos];
    *promovida = atual->elementos[atual->nElementos-1];
    atual->nElementos--;
}

/*Função insere*/
int insere(No *atual, float chave){
    if(atual->nElementos == atual->ordem -1){
        printf("ERRO:O vetor esta cheio\n");
        return 0;
    }
    else {
        if(atual->nElementos == 0){
        atual->elementos[0] = chave;
        atual->nElementos = 1;
        }
        else{
            int i = 0;
            while(atual->elementos[i] < chave && i < atual->nElementos){ //inserir na pos i+1
                i++;
            }
            int c;
            for(c = atual->nElementos; c > i; c--){
                atual->elementos[c] = atual->elementos[c-1];
                atual->filhos[c+1] = atual->filhos[c];
            }
            atual->elementos[i] = chave;
            atual->nElementos++;
        }
        return 1;
    }
}

int insereComNo(No *atual, float chave, No* novo){
    if(atual->nElementos == atual->ordem -1){
        printf("ERRO:O vetor esta cheio\n");
        return 0;
    }
    else {
        if(atual->nElementos == 0){
        atual->elementos[0] = chave;
        atual->nElementos = 1;
        }
        else{
            int i = 0;
            while(atual->elementos[i] < chave && i < atual->nElementos){ //inserir na pos i+1
                i++;
            }
            int c;
            for(c = atual->nElementos; c > i; c--){
                atual->elementos[c] = atual->elementos[c-1];
                atual->filhos[c+1] = atual->filhos[c];
                /*No novo;
                criaNoFolha(atual->ordem, &novo);
                atual->filhos[c] = novo;*/
            }
            atual->elementos[i] = chave;
            atual->filhos[i+1] = *novo;
            atual->nElementos++;
        }
        return 1;
    }
}

int BusqueEInsira(No* atual, float chave, int* promocao, float* promovida, No* novo){

    if(atual->ehFolha == 1){
        if(atual->nElementos < atual->ordem -1){
            insere(atual, chave);
            *promocao = 0;
        }else{
            No dir;
            criaNo(atual->ordem, &dir);
            divida(atual, chave,&dir, novo, promovida);
            *promocao = 1;
        }
        return 1;
    }else{
        //printf("ENTROU NO NAO FOLHA\n");
        int i; //acha o filho de descida -> desce no filho i
        for(i = 0; i < atual->nElementos;i++){
            if(chave < atual->elementos[i]){
                break;
            }
        }
        //printf("VALOR DE I: %d\n", i );
        //printf("VALOR: %d\n", atual->filhos[1].nElementos);
        //for(i = 0; i < atual->filhos[1].nElementos; i++){
        //printf("Elementos do filho: %f\n", atual->filhos[1].elementos[i]);
        //}
        int status;
        status = BusqueEInsira(&atual->filhos[i], chave, promocao, promovida, novo);

        if(status == 1 && *promocao == 1){
            if(atual->nElementos < atual->ordem-1){// nao esta cheio
                printf("ENTROU\n");
                printf("VAL DA CHAVE: %f\n", chave);
                insereComNo(atual, *promovida, novo);
                *promocao = 0;
            }else{
                No aux;
                criaNo(atual->ordem, &aux);
                printf("ESTA AQUI!!!!!\n");
                printf("O valor da promovida é: %f\n", *promovida);
                printf("O valor da promovida2 é: %f\n", promovida);
                divida(atual, *promovida, novo, &aux , promovida); //ACHO Q O PRBLEMA ESTA AQUI
                int i;
                for(i = 0; i<atual->nElementos; i++){
                    printf("Elementos de ATUAL: %f\n", atual->elementos[i]);
                }
                for(i = 0; i<aux.nElementos; i++){
                    printf("Elementos de AUX: %f\n", aux.elementos[i]);
                }
                for(i = 0; i<novo->nElementos; i++){
                    printf("Elementos de NOVO: %f\n", novo->elementos[i]);
                }
                printf("Promovida eh: %f\n", *promovida);
                *novo = aux;
            }
        }
        return status;
    }
}



/*Função de Insercao na Arvore B*/
int insereFinal(No *raiz, float chave){
    if(raiz->nElementos == 0){//A arvore esta vazia
        insere(raiz, chave);
        return 1;
    }else{
        if(BuscaRecursiva(*raiz, chave)){
            printf("ERRO: A chave ja esta na arvore\n");
            return 0;
        }else{
            int promocao;
            float promovida;
            No novo;
            int status;
            status = BusqueEInsira(raiz, chave, &promocao, &promovida, &novo);//ja insere se puder
            if(promocao == 1){
                No novaRaiz;
                criaArvoreB(raiz->ordem, &novaRaiz);
                insere(&novaRaiz, promovida);
                novaRaiz.filhos[0] = *raiz;
                novaRaiz.filhos[1] = novo;
                novaRaiz.tipo=0;
                novaRaiz.ehFolha = 0;
                novaRaiz.ehRaiz = 1;
                raiz->ehRaiz = 0;
                raiz->tipo = 1;
                *raiz = novaRaiz;
                int i;
            }
            return status;
        }
    }
}
