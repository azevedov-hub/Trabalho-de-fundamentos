#include "veiculo.h"
#include "condutor.h"

  typedef struct {
      Veiculo  veiculo;
      Condutor condutor;
      float    premio_anual;
      float    premio_mensal;
      char     data[11];    /* formato DD/MM/AAAA */
  } Cotacaox;