/*Define a estrutura do Nó da Arvore B*/
typedef struct noArvore No; //define o tipo No

struct noArvore{ //estrutura No Arvore
    int nElementos; //numero de elementos no nó
    float* elementos; //elementos
    No* filhos; //filhos
    int tipo; //0-> raiz // 1->folha // 2-> meio
    int ordem; //ordem do nó
};

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
    int opcao; //opcao do usuário
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
void criaArvoreB(int ordem, No* raiz){ //para criar a arvore, trata o nó raiz
    raiz->ordem = ordem; //ordem do nó
    raiz->elementos = (float*)malloc((ordem -1) * sizeof(float)); //numero de elementos maximo = ordem - 1
    raiz->filhos = (No*)malloc((ordem) * sizeof(No)); //numero de filhos maximo = ordem
    raiz->tipo = 0; //raiz
    raiz->nElementos = 0; //numero de elementos atual (nenhuma inserção antes da criação)
}

/*Função cria Nó*/
void criaNo(int ordem, No* no){
    no->ordem = ordem;
    no->elementos = (float*)malloc((ordem -1) * sizeof(float));
    no->filhos = (No*)malloc((ordem) * sizeof(No));
    no->nElementos = 0;
    no->tipo = 1; //folha
}

/*Função cria Nó*/
void criaNoFolha(int ordem, No* no){ //para criar o nó
    no->ordem = ordem; //ordem do nó
    no->elementos = (float*)malloc((ordem -1) * sizeof(float)); //numero de elementos maximo = ordem - 1
    no->filhos = (No*)malloc((ordem) * sizeof(No)); //numero de filhos maximo = ordem
    no->tipo = 1; //folha
    no->nElementos = 0; //numero de elementos atual (nenhuma inserção antes da criação)
}

/*Função BuscaBin*/
int BuscaBin(No atual, float chave){ //faz a busca binária ITERATIVA no nó
    int p, u, m; //primeiro, ultimo e meio
    p=0; //primeiro é 0
    u = atual.nElementos -1; //ultimo é o numero de elementos no nó -1
    while(1){
        m = floor((p+u)/2); //meio
        if(atual.elementos[m] == chave){ //se o elemento do meio for a chave
            printf("CHAVE ENCONTRADA\n"); //encontrou
            return 1; //retorna 1
        }
        else{
            if(atual.elementos[m] < chave){ //se a chave for maior que o elemento do meio
                p = m; //primeiro = meio
            }else{ //senão
                u = m; //ultimo = meio
            }
            if(p+1 == u){ //se primeiro + 1 == ultimo, só tem 2 elementos
                if(atual.elementos[p] == chave){ //ou chave está no primeiro
                    printf("CHAVE ENCONTRADA\n");
                    return 1;
                }
                else if(atual.elementos[u] == chave){ //ou chave está no ultimo
                    printf("CHAVE ENCONTRADA\n");
                    return 1;
                }else{ //ou não tem a chave
                    printf("CHAVE NAO ENCONTRADA\n");
                    return 0;
                }
            }
            if(p == u){ //se primeiro == ultimo, então
                if(atual.elementos[p] == chave){ //ou chave está no primeiro
                    printf("CHAVE ENCONTRADA\n");
                    return 1;
                }else{ //ou não tem a chave
                    printf("CHAVE NAO ENCONTRADA\n");
                    return 0;
                }
            }
        }
    }
}

/*Função BuscaRecursiva*/
int BuscaRecursiva(No atual, float chave){ //faz a busca recursiva no nó
    if(atual.nElementos == 0){ //se o nó não tiver elementos, retorna 0
        return 0;
    }else{ //senão
        if(BuscaBin(atual, chave)){ //se a chave estiver no nó atual (busca binária), achou
            return 1; //retorna 1
        }else{ //senão estiver no nó atual
            if(atual.tipo == 1){ //se o atual for folha
                return 0; //então não achou
            }else{   //se o atual não for folha
                int i;
                for(i = 0; i < atual.nElementos;i++){
                    if(chave < atual.elementos[i]){
                        break;
                    }
                }
                BuscaRecursiva(atual.filhos[i], chave); //busca recursiva no nó a esquerda ou a direita
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
