//COLOCA ISSO NA MAIN PRA TESTAR
    No testeS, novo;
    criaNoFolha(7, &testeS);
    insere(&testeS, 2);
    insere(&testeS, 3);
    insere(&testeS, 4);
    insere(&testeS, 5);
    insere(&testeS, 6);
    insere(&testeS, 7);
    int i;
    float promovida;

    divida(&testeS, 1, &novo, &promovida);
    printf("promovida: %f\n", promovida);
    for(i = 0; i<testeS.nElementos; i++){
        printf("Elemento de testeS: %f\n", testeS.elementos[i]);
    }
    for(i = 0; i<novo.nElementos; i++){
        printf("Elemento de novo: %f\n", novo.elementos[i]);
    }






void divida(No* atual, float novaChave, No* novo, float* promovida){
    criaNoFolha(atual->ordem, novo);
    printf("valor: %d\n", atual->ordem);
    printf("valor: %d\n", novo->tipo);
    novo->tipo = atual->tipo;
    int m;
    m = floor((atual->ordem)/2);
    printf("valor: %d\n", m);
    printf("valor: %f\n", atual->elementos[m]);
    printf("valor: %f\n",novaChave);
    if(novaChave < atual->elementos[m]){
        printf("Entrou no IF\n");
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
        printf("Saiu do FOR\n");
        insere(atual, novaChave);
        printf("Inseriu o valor\n");
    }else{
        printf("Entrou no ELSE\n");
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
        printf("Saiu do FOR\n");
        insere(novo, novaChave);
        printf("Inseriu o valor\n");
    }
    novo->filhos[0] = atual->filhos[atual->nElementos];
    *promovida = atual->elementos[atual->nElementos-1];
    atual->nElementos--;
}
