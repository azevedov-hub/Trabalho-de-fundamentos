#include <stdio.h>
#include "condutor.h"
#include "veiculo.h"
#include "cotacao.h"
#include "menu.h"
#include <stdlib.h>


int main(void){

    int opcao = -1; 
    int total_clientes = 0;
    int alok = 0;

    // Fazendo a leitura do arquivo

    FILE *arquivo;

    arquivo = fopen("teste.txt" , "rb");

if (arquivo == NULL){
    printf("Deu merda ao abrir o arquivo\n");

    printf("Dgite 1 para começar um novo arquivo ou pressione qualquer tecla para sair: ");
    scanf(" %d",&opcao);

    if(opcao == 1){
        system("touch teste.txt");
        arquivo = fopen("teste.txt" , "wb");

    }else{

        return 0;
    }
}

if(opcao == 1){
    fwrite(&total_clientes,sizeof(int),1,arquivo);
}else{
    fread(&total_clientes,sizeof(int),1,arquivo);
}

Cotacao clientes[total_clientes];

fread(clientes,sizeof(Cotacao),total_clientes,arquivo);

while(1){


    menu_inicial(&opcao);


//Cadastro de um novo cliente

    if(opcao == 1){
        //leitura de dados do clientes
       
    }
    if(opcao == 2){

        menu_inicial2(&opcao);
    }
    if(opcao == 3){


    }

//Fechar o programa

    if(opcao == 67){
        break;
    }

}
    return 0;
}