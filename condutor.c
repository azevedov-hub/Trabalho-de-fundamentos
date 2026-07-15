

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "condutor.h"

void condutores(Condutor *condutor){

    /* Nome */
    while (1){

        getchar(); 

        printf("Escreva seu nome: ");
        fgets(condutor->nome, sizeof(condutor->nome), stdin);

        size_t tam_nome = strlen(condutor->nome);

        if (tam_nome > 0 && condutor->nome[tam_nome - 1] == '\n'){
            condutor->nome[tam_nome - 1] = '\0';
            tam_nome--;
        }

        if (tam_nome < 3 || tam_nome > 50){
            printf("Nome inválido.\n");
            continue;
        }

        int ver = 0;

        for (size_t i = 0; i < tam_nome; i++){
            if (isdigit((unsigned char)condutor->nome[i])){
                printf("Não pode escrever números no nome.\n");
                ver = 1;
                break;
            }
        }

        if (ver == 0)
            break;
    }

    /* RG */
    while (1){

        printf("Escreva seu RG: ");
        fgets(condutor->rg, sizeof(condutor->rg), stdin);

        size_t tam_rg = strlen(condutor->rg);

        if (tam_rg > 0 && condutor->rg[tam_rg - 1] == '\n'){
            condutor->rg[tam_rg - 1] = '\0';
            tam_rg--;
        }

        if (tam_rg == 0 || tam_rg > 5){
            printf("RG inválido.\n");
            continue;
        }

        int valido = 1;

        for (size_t i = 0; i < tam_rg; i++){
            if (!isdigit((unsigned char)condutor->rg[i])){
                printf("Digite somente números.\n");
                valido = 0;
                break;
            }
        }

        if (valido)
            break;
    }

    /* Idade */
    while (1){

        getchar();

        printf("Escreva sua idade: ");

        if (scanf("%d", &condutor->idade) != 1){
            printf("Digite somente números.\n");

            while (getchar() != '\n');
            continue;
        }

        while (getchar() != '\n');

        if (condutor->idade >= 18 && condutor->idade <= 120)
            break;

        printf("Idade inválida.\n");
    }

    /* Sinistros */
    while (1){

        printf("Número de sinistros nos últimos 3 anos: ");

        if (scanf("%d", &condutor->sinistros) != 1){
            printf("Digite somente números.\n");

            while (getchar() != '\n');
            continue;
        }

        while (getchar() != '\n');

        if (condutor->sinistros >= 0 && condutor->sinistros <= 100)
            break;

        printf("Número de sinistros inválido.\n");
    }

    /* CNH */
    while (1){

        printf("Classificação da CNH (A, B ou C): ");

        if (scanf(" %c", &condutor->cnh) != 1){
            printf("Erro de leitura.\n");
            continue;
        }

        condutor->cnh = toupper((unsigned char)condutor->cnh);

        if (condutor->cnh == 'A' ||
            condutor->cnh == 'B' ||
            condutor->cnh == 'C')
            break;

        printf("Digite apenas A, B ou C.\n");
    }
}