#include <stdio.h>
#include "condutor.h"

  typedef struct {
      char  marca[50];
      char  modelo[50];
      int   ano;
      float valor_mercado;
      char  tipo;           /* 'P', 'U' ou 'E' */
  } Veiculo;

  typedef struct {
      char nome[80];
      char rg[5];
      int  idade;
      int  sinistros;
      char cnh;             /* 'A', 'B' ou 'C' */
  } Condutor;

  typedef struct {
      Veiculo  veiculo;
      Condutor condutor;
      float    premio_anual;
      float    premio_mensal;
      char     data[11];    /* formato DD/MM/AAAA */
  } Cotacao;


int main(void){

    int opcao; 
Condutor x;

menu_inicial(&opcao);
condutor(&x);

    return 0;
}