//COLOCA ISSO NA MAIN PRA TESTAR
    No testeS, novo;
    criaNoFolha(4, &testeS);
    insere(&testeS, 1);
    insere(&testeS, 2);
    insere(&testeS, 3);
    float promovida;

    divida(&testeS, 4, &novo, &promovida);
    printf("Elemento 0: %f\n", novo.elementos[0]);
    printf("promovida: %f\n", promovida);
    int i;
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
        int i;
        int pos = 0;
        for(i = m; i<atual->nElementos; i++){
            novo->elementos[pos] = atual->elementos[m];
            novo->filhos[pos+1] = atual->filhos[m+1];
            novo->nElementos++;
            atual->nElementos--;
            pos++;
        }
        insere(&atual, novaChave);
    }else{
        printf("Entrou no ELSE\n");
        int i;
        int pos = 0;
        for(i = m+1; i<atual->nElementos; i++){
            novo->elementos[pos] = atual->elementos[m];
            novo->filhos[pos+1] = atual->filhos[m+1];
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
