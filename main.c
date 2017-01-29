/*TRABALHO 2 DE ORI - ÁRVORES B */
/*ALUNOS: Bruna Zamith, RA: 628093
Leonardo Utida, RA: 628182
Marcos Faglioni, RA:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Define a estrutura do Nó da Arvore B*/
typedef struct noArvore No;

    struct noArvore{
    int nElementos;
    int* elementos;
    No* filhos;
    int ehFolha;
    int ehRaiz;
    int ordem;
};

/*Define a estrutura da Arvore B*/
typedef struct{
    No raiz;
    int ordem;
}Arvore;

/*Protótipo das Funções*/

/*Função "entradaComandoInicial"
Recebe os primeiros comandos do usuário;
Retorna 0 se for a tela help, ou comando 1 se for a inicialização da arvore
Por referência, o inteiro referente à ordem da árvore é retornado*/
int entradaComandoInicial(int*);

/*Função "entradaComandoSecundario"
Recebe o segundo comando do usuário;
Retorna 1 se for a tela insercao, ou comando 2 se for busca na arvore, ou 3 se o comando for encerrar programa*/
int entradaComandoSecundario();


/*Função "criaArvoreB"
Cria a ArvoreB*/
void criaArvoreB(int, No*);

void criaNo(int, No*);

int insere(No *atual, int chave);

int BuscaBin(No atual, int chave);

int BuscaRecursiva(No atual, int chave);

void split();

void BusqueEInsira();

int insereRecursivo(No *atual, int chave);


/*Função "insereNaArvoreB"
Recebe a Arvore e faz a inserção*/
void insereNaArvoreB(Arvore*);

/*Função "buscaNaArvoreB"
Recebe a Arvore e faz a inserção*/
void buscaNaArvoreB(Arvore*);

/*Função principal*/
int main(){
    //area de teste

    No teste;
    criaArvoreB(4, &teste);
    criaNo(4, &teste.filhos[0]);
    criaNo(4, &teste.filhos[1]);
    criaNo(4, &teste.filhos[2]);

    insere(&teste, 10);
    insere(&teste, 20);

    insere(&teste.filhos[0], 2);
    insere(&teste.filhos[0], 1);
    insere(&teste.filhos[1], 11);
    insere(&teste.filhos[1], 12);
    insere(&teste.filhos[2], 21);
    insere(&teste.filhos[2], 22);


    if(BuscaRecursiva(teste, 10)){
        printf("ACHOU\n");
    }else{
        printf("NAO ACHOU T.T\n");
    }




    printf("****Programa ArvoreB****\nComandos:\narvoreB -t [int] >> Inicializa a arvore definindo o grau minimo [int]\narvoreB -h [] >> Abre o menu de instrucoes\nDigite o Comando:\n");
    int comando,ordem; //cria os inteiros que receberão o comando e a ordem minima da arvore
    comando=entradaComandoInicial(&ordem); //recebe comando do usuario

    while(comando==0){//se o comando for a tela help
        printf("\n\nO programa arvoreB cria uma arvore B.\nPara inicializar, digite arvoreB -t [int], definindo o grau minimo [int]\nDigite o Comando:\n");
        comando=entradaComandoInicial(&ordem); //recebe novamenete o comando do usuario
    }
    Arvore arv;
    No raiz;
    criaArvoreB(ordem, &raiz); //cria a Arvore B
    comando = entradaComandoSecundario(); //chama o comando secundario do usuario (insercao, busca ou sair)
    if(comando==1){
        insereNaArvoreB(&arv); //insere na arvore
    }
    if(comando==2){
        buscaNaArvoreB(&arv); //busca na arvore
    }
    if(comando==3){ //encerra o programa
        return 0;
    }

    return 0;
}

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
    raiz->elementos = (int*)malloc((ordem -1) * sizeof(int));
    raiz->filhos = (No*)malloc((ordem) * sizeof(No));
    raiz->ehFolha = 0;
    raiz->ehRaiz = 1;
    raiz->nElementos = 0;
}

void criaNo(int ordem, No* no){
    no->ordem = ordem;
    no->elementos = (No*)malloc((ordem -1) * sizeof(No));
    no->filhos = (No*)malloc((ordem) * sizeof(No));
    no->nElementos = 0;
    no->ehFolha = 1;
}

int insere(No *atual, int chave){
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


int BuscaBin(No atual, int chave){
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

int BuscaRecursiva(No atual, int chave){
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


/*Função de Insercao na Arvore B*/
void insereNaArvoreB(Arvore* arv){
    float valor;
    printf("Digite o valor que deseja inserir: ");
    scanf("%d", &valor);
}

/*Função de Insercao na Arvore B*/
void buscaNaArvoreB(Arvore* arv){
    float valor;
    printf("Digite o valor que deseja buscar: ");
    scanf("%d", &valor);
}

int insereRecursivo(No *atual, int chave){
    if(atual->nElementos == 0){
        insere(atual, chave);
        return 1;
    }else{

    }
}
