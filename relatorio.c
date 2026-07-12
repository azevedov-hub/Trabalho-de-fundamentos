#include <stdio.h>
#include <string.h>
#include "relatorio.h"

/* Essa funcao so serve para imprimir os dados de UMA cotacao na tela.
   Fiz uma funcao separada para nao ficar copiando o mesmo printf
   varias vezes nas outras funcoes. */
void imprimirCotacao(Cotacao c, int numero)
{
    printf("\n------------------------------\n");
    printf("Cotacao numero: %d\n", numero);
    printf("Data: %s\n", c.data);
    printf("Condutor: %s\n", c.condutor.nome);
    printf("Idade: %d\n", c.condutor.idade);
    printf("CNH: %c\n", c.condutor.cnh);
    printf("Veiculo: %s %s (%d)\n", c.veiculo.marca, c.veiculo.modelo, c.veiculo.ano);
    printf("Tipo: %c\n", c.veiculo.tipo);
    printf("Premio anual: R$ %.2f\n", c.premio_anual);
    printf("Premio mensal: R$ %.2f\n", c.premio_mensal);
    printf("------------------------------\n");
}


/* Funcao 1: Listar todas as cotacoes que estao salvas */
void listarCotacoes(Cotacao lista[], int total)
{
    int i;

    printf("\n=== LISTA DE TODAS AS COTACOES ===\n");

    /* se nao tiver nenhuma cotacao, avisa e sai da funcao */
    if (total == 0) {
        printf("Nao ha nenhuma cotacao cadastrada ainda.\n");
        return;
    }

    /* passa por todas as posicoes do vetor e imprime uma por uma */
    for (i = 0; i < total; i++) {
        imprimirCotacao(lista[i], i + 1);
    }
}


/* Funcao 2: Filtrar cotacoes pelo nome do condutor */
void filtrarPorCondutor(Cotacao lista[], int total, char nome[])
{
    int i;
    int achou = 0; /* uso essa variavel so pra saber se encontrou alguma coisa */

    printf("\n=== COTACOES DO CONDUTOR: %s ===\n", nome);

    for (i = 0; i < total; i++) {

        /* strstr procura se "nome" aparece dentro do nome do condutor
           que esta guardado na struct. Se achar, retorna diferente de NULL */
        if (strstr(lista[i].condutor.nome, nome) != NULL) {
            imprimirCotacao(lista[i], i + 1);
            achou = 1;
        }
    }

    if (achou == 0) {
        printf("Nenhuma cotacao encontrada para esse condutor.\n");
    }
}


/* Funcao 3: Mostrar a cotacao de menor valor (menor premio anual) */
void exibirMenorCotacao(Cotacao lista[], int total)
{
    int i;
    int indiceMenor;

    printf("\n=== COTACAO DE MENOR VALOR ===\n");

    if (total == 0) {
        printf("Nao ha nenhuma cotacao cadastrada ainda.\n");
        return;
    }

    /* comeca assumindo que a primeira cotacao e a menor */
    indiceMenor = 0;

    /* vai comparando com todas as outras para ver se acha uma menor */
    for (i = 1; i < total; i++) {
        if (lista[i].premio_anual < lista[indiceMenor].premio_anual) {
            indiceMenor = i;
        }
    }

    imprimirCotacao(lista[indiceMenor], indiceMenor + 1);
}
