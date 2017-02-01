///FUNÇÕES///
/*Função entradaComandoInicial
Objetivo: Realizar a verificação e validação dos dados digitados pelo usuário em primeira instancia (ajuda ou criação da arvore)
Parametros formais:
	int* : Ponteiro para a variavel ordem, passado por referência
Retornos:
	Valor inteiro: 0 caso o usuário digitou ajuda, ou 1 no caso do usuario digitar -t [ordem], onde inicializa a árvore
	Valor passado por referência é alterado para o valor da ordem da arvore, no caso do comando ser -t [ordem] */
int entradaComandoInicial(int *ordem){
    char entrada[20];
    char text[10];
    gets(entrada);
    strncpy(text,entrada,9);
    text[9]='\0';

    //se os primeiros 9 caracteres forem "arvoreB -"
    while(strcmp(text,"arvoreB -")){
        //se o 10o caracter for t ou h
        while(entrada[9]!='t' && entrada[9]!='h'){
            printf("\nComando invalido, tente novamente\n");
            gets(entrada);
            strncpy(text,entrada,9);
            text[9]='\0';
        }
    }

    //se o comando for t
    if(entrada[9]=='t'){
        //recebe a ordem
        *ordem=((int)entrada[11])-((int)'0');
        return 1;
    }

    //se o comando for h
    if(entrada[9]=='h'){
        return 0;
    }
}

/*Função entradaComandoSecundario
Objetivo: Realizar a verificação e validação dos dados digitados pelo usuário em segunda instancia (busca, inserção ou encerramento)
Parametros formais:
	Sem paramêtros de entrada
Retornos:
	Valor inteiro: 1 no caso de inserção; 2 no caso de busca; ou 3 no caso de encerramento do programa*/
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
        printf("############################################################################################");
}

/*Funções "criaArvoreB", "criaNoFolha" e "criaNo"
Objetivo: Cria os nós determinados para a árvore, no "criaArvoreB" é criado um nó raiz; na "criaNoFolha" é criado um nó folha, e no "criaNo" é criado um nó intermediário.
Parametros formais:
	Para as três funções acima:
	int ordem: contém a ordem que o nó a ser criado possuirá
	No* no: Ponteiro passado por referencia para o nó criado, esse ponteiro apontará para o nó criado.
Retornos:
	Retorno vazio*/
void criaArvoreB(int ordem, No* raiz){
    raiz->ordem = ordem;
    raiz->elementos = (float*)malloc((ordem -1) * sizeof(float));
    raiz->filhos = (No*)malloc((ordem) * sizeof(No));
    raiz->nElementos = 0;
    raiz->ehRaiz = 1;
    raiz->ehFolha = 1;
}

/*Funções "criaArvoreB", "criaNoFolha" e "criaNo"
Objetivo: Cria os nós determinados para a árvore, no "criaArvoreB" é criado um nó raiz; na "criaNoFolha" é criado um nó folha, e no "criaNo" é criado um nó intermediário.
Parametros formais:
	Para as três funções acima:
	int ordem: contém a ordem que o nó a ser criado possuirá
	No* no: Ponteiro passado por referencia para o nó criado, esse ponteiro apontará para o nó criado.
Retornos:
	Retorno vazio*/
//Função criaNoFolha
void criaNoFolha(int ordem, No* no){
    no->ordem = ordem;
    no->elementos = (float*)malloc((ordem -1) * sizeof(float));
    no->filhos = (No*)malloc((ordem) * sizeof(No));
    no->nElementos = 0;
    no->ehRaiz = 0;
    no->ehFolha = 1;
}

//Função criaNo
void criaNo(int ordem, No* no){
    no->ordem = ordem;
    no->elementos = (float*)malloc((ordem -1) * sizeof(float));
    no->filhos = (No*)malloc((ordem) * sizeof(No));
    no->nElementos = 0;
}

/*Função "buscaBin"
Objetivo: Realizar a busca binária dentro dos nós afim de detectar se uma dada chave já existe no nó.
Parametros formais:
	No* atual: Nó a ser analisado;
	float chave: Chave que contém o valor a ser pesquisado;
Retornos:
	Retorno inteiro: 1 caso a chave tenha sido encontrada, ou 0 em caso contrário.*/
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
                        return 1;
                    }
                    else if(atual.elementos[u] == chave){
                        return 1;
                    }else{
                        return 0;
                    }
                }
                if(p == u){
                    if(atual.elementos[p] == chave){
                        return 1;
                    }else{
                        return 0;
                    }
                }
            }
        }
    }
}

/*Função "buscaRecursiva"
Objetivo: Realizar a busca recursiva a partir de um dado nó, afim de detectar se uma dada chave já existe.
Parametros formais:
	No* atual: Nó inicial a ser analisado;
	float chave: Chave que contém o valor a ser pesquisado;
Retornos:
	Retorno inteiro: 1 caso a chave tenha sido encontrada, ou 0 em caso contrário.*/
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

/*Função "insere"
Objetivo: Insere no nó passado por referencia.  Este método faz apenas a verificação se o nó esta cheio, em caso negativo, insere, em caso positivo, retorna 0, indicando não inserção.
Parametros formais:
	No* atual: Ponteiro para o nó atual
	float chave: Contém o valor a ser inserido na árvore e é passado por valor
Retornos:
	Retorno inteiro, por valor, caso for inserido com sucesso, retorna 1, caso contrário, retorna 0.*/
int insere(No *atual, float chave){
    if(atual->nElementos == atual->ordem -1){
        printf("ERRO:O vetor esta cheio\n");
        return 0;
    }
    else {
        if(atual->nElementos == 0){
            atual->elementos[0] = chave;
            atual->nElementos = 1;
            printf("Inseriu na posicao(i): 1\n");
        }
        else{
            int i = 0;
	    //inserir na pos i+1
            while(atual->elementos[i] < chave && i < atual->nElementos){
                i++;
            }
            int c;
            for(c = atual->nElementos; c > i; c--){
                atual->elementos[c] = atual->elementos[c-1];
                atual->filhos[c+1] = atual->filhos[c];
            }
            atual->elementos[i] = chave;
            atual->nElementos++;
            printf("Inseriu na posicao(i): %d\n", (i+1));
        }
        return 1;
    }
}

/*Função "insereComNo"
Objetivo: Insere no nó passado por referencia. Este método faz apenas a verificação se o nó esta cheio, em caso negativo, insere, em caso positivo, retorna 0, indicando não inserção. Neste método é realizado o deslocamento dos ponteiros e chaves que por conta da inserção foram deslocados, sempre deslocando para a direita (sentido do maior valor), e ainda, aloca o novo nó a direita da chave inserida.
Parametros formais:
	No* atual: Ponteiro para o nó atual
	float chave: Contém o valor a ser inserido na árvore e é passado por valor;
	No* novo: Ponteiro para o nó a ser alocado a direita da posição que for inserido a chave.
Retornos:
	Retorno inteiro, por valor, caso for inserido com sucesso, retorna 1, caso contrário, retorna 0.*/
int insereComNo(No *atual, float chave, No* novo){
    if(atual->nElementos == atual->ordem -1){
        printf("ERRO:O vetor esta cheio\n");
        return 0;
    }
    else {
        if(atual->nElementos == 0){
        atual->elementos[0] = chave;
        atual->nElementos = 1;
        atual->filhos[1] = *novo;
        }
        else{
            int i = 0;
            //inserir na pos i+1
            while(atual->elementos[i] < chave && i < atual->nElementos){
                i++;
            }
            int c;
            for(c = atual->nElementos; c > i; c--){
                atual->elementos[c] = atual->elementos[c-1];
                atual->filhos[c+1] = atual->filhos[c];
            }
            atual->elementos[i] = chave;
            atual->filhos[i+1] = *novo;
            atual->nElementos++;
        }
        return 1;
    }
}

/*Função "divida"
Objetivo: Responsável pelo processo de dividir os nos, quando ocorre de um nó ficar cheio, e necessitar comportar mais um valor. Neste método ocorre a verificação de qual é a mediana com promoção, esta retornada como referencia, para ser tratada posteriormente.
Parametros formais:
	No* atual: Nó a ser dividido;
	float novaChave: Chave que contém o valor a ser inserido;
	No* dir: Auxiliar para a realocação do nó;
	No* novo: Novo nó passado por referencia, que recebera os elementos maiores que a mediana no nó atual;
	float promovida: Valor da chave que representa a mediana do nó a ser dividido, passado por referência.
Retornos:
	Retorno vazio, somente há alteração dos valores passados por referência.*/
void divida(No* atual, float novaChave, No* dir, No* novo, float* promovida){
    criaNo(atual->ordem, novo);
    novo->ehRaiz = atual->ehRaiz;
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

/*Função "buscaEInsere"
Objetivo: Função responsável por buscar a posição correta de inserção da chave e inserir em um dado nó. Este método tambem faz o tratamentos como divisões, splits, ou chaves promovidas.
Parametros formais:
	No* atual: Nó a ser analisado e ter uma nova chave inserida;
	float chave: Chave que contém o valor a ser inserido;
	int promoção: Recebe por referência, se houve promoção de chaves;
	float promovida: Valor da chave que representa a mediana do nó, passado por referência;
	No* novo: Novo nó passado por referencia, que recebera os elementos maiores que a mediana no nó atual, se houver divisão;
	No* inserido: Retorna um ponteiro para o nó que houve a inserção.
Retornos:
	Retorno inteiro: 1 caso a inserção tenha ocorrido com sucesso, ou 0 em caso contrário.*/
int BusqueEInsira(No* atual, float chave, int* promocao, float* promovida, No* novo, No** inserido){
    int status;

    if(atual->ehFolha == 1){
        if(atual->nElementos < atual->ordem -1){
            insere(atual, chave);
            *inserido = atual;
            *promocao = 0;
        }else{
            No dir;
            criaNo(atual->ordem, &dir);
            divida(atual, chave,&dir, novo, promovida);
            *promocao = 1;
        }
        return 1;
    }else{
        int i;
	//Encontra o filho de descida -> desce no filho i
        for(i = 0; i < atual->nElementos;i++){
            if(chave < atual->elementos[i]){
                break;
            }
        }
        status = BusqueEInsira(&atual->filhos[i], chave, promocao, promovida, novo, inserido);

        if(status == 1 && *promocao == 1){
            if(atual->nElementos < atual->ordem-1){
                insereComNo(atual, *promovida, novo);
                *inserido = atual;
                *promocao = 0;
            }else{
                No aux;
                criaNo(atual->ordem, &aux);
                divida(atual, *promovida, novo, &aux , promovida);
                *novo = aux;
            }
        }
        return status;
    }
}

/*Função "insereFinal"
Objetivo: Este método recebe como parametro a raiz da árvore. A partir deste, os métodos de inserção e de buscaEInsere são instanciados, assim esta função faz o controle se o valor já está presenta na árvore, em caso positivo, retorna 0, indicando erro de inserção; ou em caso contrário, 1, no caso da inserção ocorrer. Se a inserção ocorrer, este método já trata (ou instância funções que tratem) os casos de excessão como promoção de chaves e divisão da raiz.
Parametros formais:
	No* raiz: Ponteiro para o nó que aponta para a raiz da árvore;
	float chave: Contém o valor a ser inserido na árvore e é passado por valor;
    	No* inserido: Retorna um ponteiro para o nó que houve a inserção.
Retornos:
	Retorno inteiro, por valor, caso for inserido com sucesso, retorna 1, caso contrário, retorna 0.*/
int insereFinal(No *raiz, float chave, No ** inserido){
    //A arvore esta vazia
    if(raiz->nElementos == 0){
        insere(raiz, chave);
        *inserido = raiz;
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
            status = BusqueEInsira(raiz, chave, &promocao, &promovida, &novo, inserido);	//ja insere se puder
            if(promocao == 1){
                No novaRaiz;
                criaArvoreB(raiz->ordem, &novaRaiz);
                insere(&novaRaiz, promovida);
                *inserido = &novaRaiz;
                novaRaiz.filhos[0] = *raiz;
                novaRaiz.filhos[1] = novo;
                novaRaiz.ehFolha = 0;
                novaRaiz.ehRaiz = 1;
                raiz->ehRaiz = 0;
                *raiz = novaRaiz;
                int i;
            }
            return status;
        }
    }
}

/*Função "insereFinal"
Objetivo: Este método imprime todos os elementos de um nó.
	No* imprimir: ponteiro para o nó a ser impresso.
Retornos:
	Sem retorno.*/
void imprimeNo(No* imprimir){
    int i;
    printf("No: (%.1f", imprimir->elementos[0]);
    for(i=1; i< imprimir->nElementos; i++){
    float v = imprimir->elementos[i];
        printf(", %.1f", imprimir->elementos[i]);
    }
    printf(")\n");
}
