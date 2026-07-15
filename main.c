#include <stdio.h>
#include "condutor.h"
#include "veiculo.h"
//#include "cotacaox.h"
#include "menu.h"
#include <stdlib.h>
#include "relatorio.h"


int main(void){

    int opcao = 0; 
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
    fwrite(&total_clientes, sizeof(int), 1, arquivo);
    fclose(arquivo);
}else{
    fread(&total_clientes, sizeof(int), 1, arquivo);
    fclose(arquivo);
}


Cotacao *p = (Cotacao *) malloc(sizeof(Cotacao) * total_clientes);

if (p == NULL) {
    printf("Erro ao alocar memória.\n");
    return 0;
}else{
    printf("Memória alocada com sucesso.\n");
    system("sleep 2");
}

Veiculo veiculo;
Condutor condutor;

if(opcao != 1){
    arquivo = fopen("teste.txt" , "rb");
    fread(p,sizeof(Cotacao),total_clientes,arquivo);
    fclose(arquivo);
}



while(1){


    menu_inicial(&opcao);


//Cadastro de um novo cliente

    if(opcao == 1){

                total_clientes++;
                p = (Cotacao *) realloc(p, sizeof(Cotacao) * total_clientes);
                if (p == NULL) {
                    printf("Erro ao realocar memória.\n");
                    return 0;
                } 
                


                system("clear");
                cadastro();
                printf("\n\n\n\n                                                          \033[1;31mCadastro do condutor\033[0m\n");
                printf("\n                                                          \033[1;31mCadasstro do veiculo\033[0m\n");
                condutores(&condutor);

                system("clear");
                cadastro();
                printf("\n\n\n\n                                                          \033[9;32mCadastro do condutor\033[0m\n");
                printf("\n                                                          \033[1;31mCadastro do veiculo\033[0m\n");
                cadastrarVeiculo(&veiculo);

                cotacao(&p[total_clientes-1], veiculo, condutor);

                system("clear");
                cadastro();
                printf("\n\n\n\n                                                          \033[9;32mCadastro do condutor\033[0m\n");
                printf("\n                                                          \033[9;32mCadastro do veiculo\033[0m\n");
                printf("\n                                  Premio Anual: %.2f                 Premio Mensal: %.2f\n", p[total_clientes-1].premio_anual, p[total_clientes-1].premio_mensal);
                printf("\n\n                                                         \033[1;32mCadastrado com sucesso!\033[0m\n");
                system("sleep 10");
        //leitura de dados do clientes

        //gravando os dados no arquivo

        arquivo = fopen("teste.txt" , "wb");
        fwrite(p, sizeof(Cotacao), total_clientes, arquivo);
        fclose(arquivo);

    }
    if(opcao == 2){


        while(1){

            menu_inicial2(&opcao);

            if(opcao == 1){}
            if(opcao == 2){}
            if(opcao == 3){}
            if(opcao == 4){
                exibirMenorCotacao(p, total_clientes);
                system("sleep 10");
            }
            if(opcao == 67){
                opcao = 0;
                break;
            }
        }
    }
    if(opcao == 3){


    }

//Fechar o programa

    if(opcao == 67){
        system("clear");
        break;
    }

}
    return 0;
}