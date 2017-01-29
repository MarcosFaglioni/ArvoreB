/*TRABALHO 2 DE ORI - ÁRVORES B */
/*ALUNOS: Bruna Zamith, RA: 628093
Leonardo Utida, RA: 628182
Marcos Faglioni, RA: 628301
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
void criaNo(int, No*);

/*Função "insere"
Chamada dentro da função insereRecursivo*/
int insere(No *atual, float chave);

int BusqueEInsira(No* atual, float chave, int promocao, float promovida, No* novo);

/*Função "insereRecursivo"
Recebe o No atual e faz a inserção*/
int insereRecursivo(No *atual);

/*Função "buscaBin"
Chamada dentro da função buscaRecursiva*/
int BuscaBin(No atual, float chave);

/*Função "buscaRecursiva"
Recebe a Arvore e faz a busca*/
int BuscaRecursiva(No atual, float chave);

///*****************************************************************///
///FUNÇÃO PRINCIPAL///
int main(){
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
            insereRecursivo(&teste); //insere na arvore
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
}

/*Função cria Nó*/
void criaNo(int ordem, No* no){
    no->ordem = ordem;
    no->elementos = (float*)malloc((ordem -1) * sizeof(float));
    no->filhos = (No*)malloc((ordem) * sizeof(No));
    no->nElementos = 0;
    no->tipo = 1; //folha
}

/*Função BuscaBin*/
int BuscaBin(No atual, float chave){
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

/*Função BuscaRecursiva*/
int BuscaRecursiva(No atual, float chave){
    if(atual.nElementos == 0){
        return 0;
    }else{
        if(BuscaBin(atual, chave)){
            return 1;
        }else{
            if(atual.tipo == 1){
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
            }
            atual->elementos[i] = chave;
            atual->nElementos++;
        }
        return 1;
    }
}

int BusqueEInsira(No* atual, float chave, int promocao, float promovida, No* novo){
    if(BuscaBin(*atual, chave)){
        printf("ERRO: Chave ja esta na arvore\n");
        return 0;
    }else{
        if(atual->tipo == 1){
            if(atual->nElementos < atual->ordem-1){
                insere(atual, chave);
            }
        }
    }
}



/*Função de Insercao na Arvore B*/
int insereRecursivo(No *atual){
    float chave;
    printf("Digite o valor que deseja inserir: ");
    scanf("%d", &chave);

    if(atual->nElementos == 0){
        insere(atual, chave);
        return 1;
    }else{

    }
}
