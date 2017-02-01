//Este código pertence ao arquivo main.c, referente a árvore B, elaborada especialmente para a disciplina de Organização e Recuperação de Informação, ministrada pelo docente Jander Moreira, na Universidade Federal de São Carlos. 
/*Tipo de dado: No
Objetivo: definir os tipos de dados utilizada na estrutura do nó
Dados:
    int nElementos: Número de elementos no nó
    float* elementos: Ponteiro para o ínicio do vetor contendo os elementos do nó
    No* filhos: Ponteiro para o ínicio do vetor contendo os ponteiros para os nós filhos
    int ehRaiz: Armazena se o nó é uma raiz
    int ehFolha: Armazena se o nó é uma folha
    int ordem: Representa a ordem da árvore, isto é, quantos filhos cada nó poderá ter e quantos elementos a arvore suporta, ordem-1 elementos*/
typedef struct noArvore No;
struct noArvore{
    int nElementos;
    float * elementos;
    No * filhos;
    int ehRaiz;
    int ehFolha;
    int ordem;
};
