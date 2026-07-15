#ifndef RELATORIO_H
#define RELATORIO_H

#include "cotacaox.h"


/* Mostra na tela todas as cotacoes que estao guardadas na lista */
void listarCotacoes(Cotacao lista[], int total);

/* Procura e mostra as cotacoes que tem o nome do condutor parecido com o nome digitado */
void filtrarPorCondutor(Cotacao lista[], int total, char nome[]);

/* Mostra a cotacao que tem o menor premio anual entre todas */
void exibirMenorCotacao(Cotacao lista[], int total);

#endif
