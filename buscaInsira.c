/*Função: BuscaEInsere
  Parametros formais:
    No atual: Recebe o nó atual da busca;
    float chave: Chave a ser inserida na árvore
    int promocao: Caso promocao seja igual a 1, houve promoção e a árvore necessitará de ajustes; caso seja igual a 0, a inserção não causou promoção e não necessita de ajustes;
    float promovida: Valor que sofreu a promoção
    No novo: ##############################################################################
  Retorno:
    int : Caso retorno for igual a 1, a chave foi inserido com sucesso; Caso seja 0, houve problema na inserção da chave, e não foi inserido
*/

int BusqueEInsira(No atual, float chave, int promocao, float promovida, No novo){
    if(BuscaBin(atual, chave)){ //Busca a chave no nó, se ela estiver presente, não insere
        printf("ERRO: Chave ja esta na arvore\n");
        return 0;
    }else{ //Senão
        if(atual->tipo == 1){ //Se for nó folha
            if(atual->nElementos < atual->ordem-1){ //Se o nó não estiver cheio
                insere(atual, chave); //só insere
                promocao = 0; //Não promove nenhum
            }else{ //Senão
                //divida(atual, chave); //faz a divisão do nó
                promocao = 1; //promove
            }
            return 1; //retorna 1, inseriu
        }else{ // Se não for nó folha
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
