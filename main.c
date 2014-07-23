//! Estrutura de Dados e Algoritmos I - MATA40
// 2º Trabalho de Estrutura de Dados e Algortimos I - 2014.1
//! Aluno: Jeferson Lima de Almeida
//! Prof.: Flávio M. Assis Silva

/*!
 * \file
 * \brief   Programa de busca binária em árvore
 * \author  Jeferson Lima
 *
 * Programa para implementação de uma árvore de busca binária contendo todas
 * as funcionalidades requisitadas no segundo trabalho de Estrutura
 * de Dados e Algoritmos I do professor Flávio M. Assis Silva
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "arvore.h"
//#include "arvore.c"

/*
 * Funções de manutenção do programa
 */

/*!
 * \brief pot Potencia de base 10
 *
 * Realiza a potência de base 10 com o nível indicado
 *
 * \param x     Expoente da potência
 * \return      O resultado da potência de base 10 e expoente x
 */
int pot(int x){
    int res;
    for(res = 1; x > 0 ; x--)
        res *= 10;                                  /* Enquanto x for maior que 0 multiplique o resultado por 10 */
    return res;
}

/*!
 * \brief stringParaInt Converte uma string para um inteiro
 *
 * Função com fim de converter a string no formato do trabalho para um inteiro
 * a ser utilizado nas funções posteriores
 *
 * \param str   String a ser analisada
 * \param x     Ponteiro do inteiro de retorno
 */
void stringParaInt(char *str, int *x){
    int i, n;                                           /* Formato de conversão de base númerica */
    for(i = strlen(str) - 1, n = 0; i >= 2; i--, n++)   /* Subtrai 48 do valor númerico do char */
        *x += (((int) str[i]) - 48) * pot(n);           /* E multiplica isto por uma potência de base 10 */
}                                                       /* Referente a posição do char em relação ao inteiro */

/*!
 * \brief consultarChave Imprime o resultado da consulta
 *
 * Consulta uma chave na arvore e retorna a possibilidade de sua existência
 *
 * \param a     Arvore binaria
 * \param x     Inteiro a ser pesquisado
 */
void consultarChave(ArvoreInt *a, int x){
    if(consulta(a, x))
        printf("existe no com chave: %d\n", x);
    else
        printf("nao existe no com chave: %d\n", x);
}

/*!
 * \brief visitaEmOrdemCrescente Imprime os nós da arvore em ordem crescente
 *
 * Realiza uma visita em ordem e imprime a árvore em ordem crescente
 *
 * \param a     Árvore a ter os nós impressos
 */
void visitaEmOrdemCrescente(noArvoreInt *a){
    if(a){
        visitaEmOrdemCrescente(a->no_esq);
        printf("%d\n", a->chave);
        visitaEmOrdemCrescente(a->no_dir);
    }
}

/*!
 * \brief visitaEmOrdemDecrescente Imprime os nós da arvore em ordem decrescente
 *
 * Realiza uma visita em ordem e imprime a árvore em ordem decrescente
 *
 * \param a     Árvore a ter os nós impressos
 */
void visitaEmOrdemDecrescente(noArvoreInt *a){
    if(a){
        visitaEmOrdemDecrescente(a->no_dir);
        printf("%d\n", a->chave);
        visitaEmOrdemDecrescente(a->no_esq);
    }
}

/*!
 * \brief listarTodasChavesEmOrdem  Lista todas as chaves uma por linha em ordem
 *
 * Lista todas as chaves uma por linha, seguindo a ordem pedida, podendo
 * ser tanto crescente como decrescente
 *
 * \param a     Árvore a ter os nós impressos
 * \param o     Opção escolhida
 */
void listarTodasChavesEmOrdem(ArvoreInt *a, char o){
    if(o == 'c')
        visitaEmOrdemCrescente(*a);
    else
        visitaEmOrdemDecrescente(*a);
}

/*!
 * \brief listarChavesDoNivel Lista a chave do nível escolhido
 *
 * Lista todas as chaves de um determinado nível de forma recursiva
 *
 * \param a     Árvore a ser consulta
 * \param atual Nivel atual
 * \param nivel Nivel desejado para impressão
 */
void listarChavesDoNivel(noArvoreInt *a, int atual, int nivel){
    if(atual == nivel)
        printf("%d\n", a->chave);
    else
        if(a){
            ++atual;
            if(a->no_esq != NULL)
                listarChavesDoNivel(a->no_esq, atual, nivel);
            if(a->no_dir != NULL)
                listarChavesDoNivel(a->no_dir, atual, nivel);
        }
}

/*!
 * \brief imprimirArvore Imprime a árvore binária
 *
 * Imprime a árvore binária, mostrando os nós a direita e a esquerda
 * de uma visualização em ordem da mesma
 * Obs.: A sequência nil indica a falta de próximo nó
 *
 * \param a Árvore a ser impressa
 */
void imprimirArvore(noArvoreInt *a){
    if(a){
        imprimirArvore(a->no_esq);
        if((a->no_esq == NULL) && (a->no_dir == NULL))
            printf("chave: %d fesq: nil fdir: nil\n", a->chave);
        else if((a->no_esq == NULL) || (a->no_dir == NULL))
            if((a->no_esq == NULL))
                printf("chave: %d fesq: nil fdir: %d\n", a->chave, a->no_dir->chave);
            else
                printf("chave: %d fesq: %d fdir: nil\n", a->chave, a->no_esq->chave);
        else
            printf("chave: %d fesq: %d fdir: %d\n", a->chave, a->no_esq->chave, a->no_dir->chave);
        imprimirArvore(a->no_dir);
    }
}

/*
 * Escopo principal do programa
 */
int main(void){
    ArvoreInt a;
    int x;
    char opcao[14];
    inicializa(&a);

    do{
        x = 0;
        scanf(" %[^\n]s", opcao);
        if((opcao[0] != 'l') && (opcao[0] != 'p'))
            stringParaInt(opcao, &x);
        switch(opcao[0]){
            case 'i':insere(&a, x); break;                              /* Insere Chave */
            case 'c':consultarChave(&a, x); break;                      /* Consulta Chave */
            case 'r':retira(&a, x); break;                              /* Remove Chave */
            case 'p':listarTodasChavesEmOrdem(&a, opcao[2]); break;     /* Lista todas as chaves dos nós da árvore */
            case 'n':listarChavesDoNivel(a, 1, x); break;               /* Lista chaves de um determinado nível da árvore */
            case 'd':imprimirArvore(a); break;                          /* Imprime a árvore */
        }
    }while(opcao[0] != 'e');

    return 0;
}
