#include <stdio.h>
#include "condutor.h"
#include "veiculo.h"
#include "cotacao.h"
#include "menu.h"


int main(void){

    int opcao; 
Condutor x;

menu_inicial(&opcao);
condutores(&x);

    return 0;
}