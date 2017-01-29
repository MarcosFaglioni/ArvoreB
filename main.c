/*TRABALHO 2 DE ORI - ÁRVORES B */
/*ALUNOS: Bruna Zamith, RA: 628093
Leonardo Utida, RA: 628182
Marcos Faglioni, RA: 628301
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

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
