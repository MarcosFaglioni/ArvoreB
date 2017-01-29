void divida(No* atual, float novaChave, No* dir, No* novo, float* promovida){
    criaNoFolha(atual->ordem, &novo);
    novo->tipo = atual->tipo;
    int m;
    m = floor((atual->ordem)/2);
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
        int i;
        int pos = 0;
        for(i = m+1; i<atual->nElementos; i++){
            novo->elementos[pos] = atual->elementos[m];
            novo->filhos[pos+1] = atual->filhos[m+1];
            novo->nElementos++;
            atual->nElementos--;
            pos++;
        }
        insere(&novo, novaChave);
    }
    novo->filhos[0] = atual->filhos[atual->nElementos];
    promovida = atual[atual->nElementos-1];
    atual->nElementos--;
}
