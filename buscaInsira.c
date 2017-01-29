int BusqueEInsira(No* atual, float chave, int promocao, float promovida, No* novo){
    if(BuscaBin(*atual, chave)){
        printf("ERRO: Chave ja esta na arvore\n");
        return 0;
    }else{
        if(atual->tipo == 1){
            if(atual->nElementos < atual->ordem-1){
                insere(atual, chave);
                promocao = 0;
            }else{
                //divida(atual, chave);
                promocao = 1;
            }
            return 1;
        }else{
            int i;
            for(i = 0; i < atual->nElementos;i++){ //busca o filho correto para descer
                if(chave < atual->elementos[i]){
                    break;
                }
            }
            int status;
            //status = BusqueEInsira(atual.filhos[i], ,promocao,promovida);

            if(status && promocao){
                if(atual->nElementos < atual->ordem-1){
                    //Insira a chave promovida no nodo atual
                    //Ajuste o ponteiro à direita da chave promovida para novo nodu
                    //houve promocao ← Falso
                }else{
                    //divida()

                }
            }
            return status;
        }
    }
}
