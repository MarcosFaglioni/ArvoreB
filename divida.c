void divida(No* atual, float novaChave, No* dir, No* novo, float* promovida){
    criaNoFolha(atual->ordem, &novo);
    novo->tipo = atual->tipo;
    int m, pos1;
    m = floor((atual->ordem)/2);
    pos1 = m;
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
    promovida = atual[pos1];
    atual->nElementos--;
}
