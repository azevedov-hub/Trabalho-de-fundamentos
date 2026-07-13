#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "condutor.h"


void condutores(Condutor *condutor){
    while (1){
        
        printf("escreva seu nome");
        fgets(condutor->nome,50,stdin);
        size_t tam_nome = strlen(condutor->nome);
        if (tam_nome > 0 && condutor->nome[tam_nome-1] == '\n'){
            condutor->nome[tam_nome-1] = '\0';
            tam_nome--;
        }
        int c;
        while ((c = getchar()) != '\n' && c != EOF); //pra limpar o buffer sla
        if (tam_nome < 3 && tam_nome > 50){
            printf("nome invalido");
        } else if(tam_nome >= 3) { 
            int ver = 0;
            for (int i=0; i < tam_nome; i++){
                if (isdigit(condutor->nome[i]) == 1){
                    printf("Não podes escrever números no campo de nomes.");
                    ver++;
                    break;
            }
            if (ver == 0)
                return 0;
        }

    }
   

    while(1) {
        
        printf("escreva seu rg");
        fgets(condutor->rg,6,stdin);
    
        size_t rg_len = strlen(condutor->rg);
        if (rg_len > 0 && condutor->rg[rg_len-1] == '\n') {
            condutor->rg[rg_len-1] = '\0';
        }
        size_t tam_rg = strlen(condutor->rg);
        
        
        
        if (tam_rg > 0 && tam_rg <= 5) {
            int valido=0;
            for (int i= 0; i < tam_rg;i++){
                if (isdigit(condutor->rg[i]) != 1){
                    printf("escreva somente digitos");
                    valido++;
                    break;
                }
            }
            if (valido == 0)
                return 0;
        } else {
            printf("RG inválido. Digite um documento válido (máximo 5 caracteres).\n");
        }
    
    }
    while (1)
    {
        printf("escreva sua idade");
        
        if (scanf("%d",&condutor->idade) == 1){
            if (condutor->idade <= 120 && condutor->idade >=18)
                return 0;
            else 
                printf("idade invalida");    
        } else {
            printf("idade invalida,use números");
            continue;
        }
    }

    while (1)
    {
        printf("escreva o numero de sisnistros que voce teve em 3 anos");
        
        if (scanf("%d", &condutor->sinistros) != 1) {
            printf("Digite somente números.\n");
            continue;
        } else if (condutor->sinistros >= 0 && condutor->sinistros <= 100) 
            break;
        else 
            printf("Número de sinistros inválido. Digite um valor entre 0 e 100.\n");
        
    }
    
    while (1)
    {
        printf("escreva a classificação do seu cnh");
        if (scanf("%c",condutor->cnh) == 1)
            if (toupper(condutor->cnh) == 'A' || toupper(condutor->cnh) == 'B' || toupper(condutor->cnh) == 'C') 
                return 0;
            else 
            printf("Erro: voce deve escrever a classificação do cnh em A OU B OU C");
            
        else {
            printf("Erro: voce deve escrever a classificação do cnh em A OU B OU C");
        }
        
    }
    
    
    
}