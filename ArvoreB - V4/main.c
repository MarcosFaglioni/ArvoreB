/*Trabalho sobre Árvore B, apresentado á disciplina de Organização e Recuperação de Informação, ministrada pelo docente Jander Moreira na Universidade Fedeal de São Carlos - UFSCar
Data: 01 de Fevereiro de 2017
Autores, Registro Acadêmico (RA):
    Bruna Zamith, 628093
    Leonardo Utida, 628182
    Marcos Faglioni, 628301
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EstruturaNo.h"
#include "Funcao.h"



///FUNÇÃO PRINCIPAL///
int main(){
    //Instancia o menu inicial (recebe o comando primário do usuário)
    printf("****Programa ArvoreB****\n");
    printf("Comandos:\n");
    printf("arvoreB -t [int] >> Inicializa a arvore definindo o grau minimo [int]\n");
    printf("arvoreB -h [] >> Abre o menu de instrucoes\nDigite o Comando:\n");

    int comando,ordem;

    comando=entradaComandoInicial(&ordem); //recebe comando do usuario

    //se o comando for a tela help
while(comando==0){
    printf("\n\nO programa arvoreB cria uma arvore B.\n");
	printf("Para inicializar, digite arvoreB -t [int], definindo o grau minimo [int]\n");
	printf("Digite o Comando:\n");
	//recebe novamenete o comando do usuario
        comando=entradaComandoInicial(&ordem);
    }

    //Cria a ArvoreB
    No raiz;
    criaArvoreB(ordem, &raiz);

    fflush(stdin);


    //Instancia o menu secundário (recebe o comando do usuario)
    //Instancia o comando secundario do usuario (insercao, busca ou sair)
    comando = entradaComandoSecundario();

    while(comando!=3){
        //se o comando for 1 (insere)
        if(comando==1){
            float chave;
            No* inserido;
            printf("Digite o valor a ser inserido: ");
            scanf("%f", &chave);
            insereFinal(&raiz, chave, &inserido);
            imprimeNo(inserido);\
        }
        //se o comando for 2 (busca)
        if(comando==2){
            float chave;
            printf("Digite o valor que deseja buscar: ");
            scanf("%f", &chave);
            //busca na arvore
            if(BuscaRecursiva(raiz, chave)){
                printf("CHAVE ENCONTRADA!\n");
            }else{
                printf("CHAVE NÃO ENCONTRADA!\n");
            }
        }
        if(comando==3){ //encerra o programa
            printf("Entrou no 3");
            return 0;
        }
        //chama o comando secundario do usuario (insercao, busca ou sair)
        comando = entradaComandoSecundario();
    }
    return 0;
}
