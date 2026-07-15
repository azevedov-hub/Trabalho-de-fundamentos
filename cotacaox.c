#include <stdio.h>
#include <stdlib.h>
#include "veiculo.h"
#include "condutor.h"

typedef struct {
      Veiculo  veiculo;
      Condutor condutor;
      float    premio_anual;
      float    premio_mensal;
      char     data[11];    /* formato DD/MM/AAAA */
  } Cotacao;

void cotacao(Cotacao *c, Veiculo v, Condutor x){

    c->veiculo = v;
    c->condutor = x;
    c->premio_anual = 0.0;
    c->premio_mensal = 0.0;
    float base =0.0;

    /*Base:
  - Taxa base: 4% do valor de mercado do veículo ao ano

Acréscimos (aplicados sobre a taxa base):
  - Veículo com até 3 anos de fabricação     → +1,5%
  - Condutor com menos de 25 anos            → +2,0%
  - Condutor com 65 anos ou mais             → +1,0%
  - Cada sinistro nos últimos 3 anos         → +1,5% (máximo de 3 sinistros)

Multiplicador de tipo:
  - Tipo Esportivo (E)                       → prêmio final × 1,4
  - Tipos Passeio (P) e Utilitário (U)       → sem alteração

Desconto:
  - CNH categoria C                          → -0,5% sobre a taxa base

Fórmula resumida:
  taxa_total = taxa_base + acrescimos - descontos
  premio_anual = valor_mercado × taxa_total
  se tipo == 'E': premio_anual = premio_anual × 1,4
  premio_mensal = premio_anual / 12
  

  typedef struct {
      char  marca[50];
      char  modelo[50];
      int   ano;
      float valor_mercado;
      char  tipo;            'P', 'U' ou 'E' veiculo


  typedef struct {
      char nome[80];
      char rg[5];
      int  idade;
      int  sinistros;
      char cnh;              'A', 'B' ou 'C' condutor

  
  */

  base = c->veiculo.valor_mercado * 0.04;

 // Acréscimos (aplicados sobre a taxa base):

  //- Veículo com até 3 anos de fabricação  → +1,5%
    if (2026 - c->veiculo.ano <= 3) {
        c->premio_mensal += base * 0.015;
    }

//- Condutor com menos de 25 anos  → +2,0%
    if (c->condutor.idade < 25) {
        c->premio_mensal += base * 0.02;
    }

 //- Condutor com 65 anos ou mais  → +1,0% 
    if (c->condutor.idade >= 65) {
          c->premio_mensal += base * 0.01;
     }

//- Cada sinistro nos últimos 3 anos  → +1,5% (máximo de 3 sinistros)

if (c->condutor.sinistros > 0) {
    if (c->condutor.sinistros <= 3) {
        c->premio_mensal += base * 0.015 * c->condutor.sinistros;
    }else
    {
        c->premio_mensal += base * 0.015 * 3;
    }
}

//Multiplicador de tipo:
//  - Tipo Esportivo (E)  → prêmio final × 1,4

if(c->veiculo.tipo == 'E'){
    c->premio_mensal *= 1.4;
}

//- Tipos Passeio (P) e Utilitário (U)   → sem alteração

//Desconto:
// - CNH categoria C   → -0,5% sobre a taxa base
if(c->condutor.cnh == 'C'){
    c->premio_mensal -= c->premio_mensal * 0.005;
}

c->premio_anual = c->premio_mensal * 12;

    
}