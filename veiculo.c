#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include "Veiculo.h"

void cadastrarVeiculo(Veiculo *v)
{
    int i, valido;

    setlocale(LC_ALL, "Portuguese_Brazil");

    printf("========================\n");
    printf("*Inicio do cadastro\n");
    printf("========================\n");

    printf("========================\n");
    printf("Cadastro de veiculo\n");
    printf("========================\n");

    // Marca
    while (1)
    {
        printf("\n========================\n");
        printf("Marca do carro: ");
        printf("\n========================\n");

        scanf("%49s", v->marca);

        valido = 1;

        for (i = 0; v->marca[i] != '\0'; i++)
        {
            if (!isalpha(v->marca[i]))
            {
                valido = 0;
            }
        }

        if (valido)
            break;

        printf("\nMarca invalida! Digite apenas letras.\n");
    }

    // Modelo
    while (1)
    {
        printf("\n========================\n");
        printf("Modelo do carro: ");
        printf("\n========================\n");

        scanf("%49s", v->modelo);

        valido = 1;

        for (i = 0; v->modelo[i] != '\0'; i++)
        {
            if (!isalnum(v->modelo[i]))
            {
                valido = 0;
            }
        }

        if (valido)
            break;

        printf("\nModelo invalido!\n");
    }

    // Ano
    while (1)
    {
        printf("\n========================\n");
        printf("Ano de fabricacao: ");
        printf("\n========================\n");

        if (scanf("%d", &v->ano) != 1)
        {
            while (getchar() != '\n');
            printf("Digite apenas numeros.\n");
            continue;
        }

        if (v->ano >= 1886 && v->ano <= 2026)
            break;

        printf("Ano invalido!\n");
    }

    // Valor de mercado
    while (1)
    {
        printf("\n========================\n");
        printf("Valor de mercado (R$): ");
        printf("\n========================\n");

        if (scanf("%f", &v->valor_mercado) != 1)
        {
            while (getchar() != '\n');
            printf("Digite apenas numeros.\n");
            continue;
        }

        if (v->valor_mercado > 0)
            break;

        printf("Valor invalido!\n");
    }

    // Tipo
    while (1)
    {
        printf("\n========================\n");
        printf("Tipo:\n");
        printf("(P) Passeio\n");
        printf("(U) Utilitario\n");
        printf("(E) Esportivo\n");
        printf("========================\n");

        scanf(" %c", &v->tipo);

        v->tipo = toupper(v->tipo);

        if (v->tipo == 'P' || v->tipo == 'U' || v->tipo == 'E')
            break;

        printf("Tipo invalido!\n");
    }
}

void mostrarVeiculo(Veiculo v)
{
    printf("\n========================\n");
    printf("DADOS DO VEICULO\n");
    printf("========================\n");

    printf("Marca: %s\n", v.marca);
    printf("Modelo: %s\n", v.modelo);
    printf("Ano: %d\n", v.ano);
    printf("Valor de mercado: R$ %.2f\n", v.valor_mercado);

    printf("Tipo: ");
    switch (v.tipo)
    {
        case 'P':
            printf("Passeio\n");
            break;
        case 'U':
            printf("Utilitario\n");
            break;
        case 'E':
            printf("Esportivo\n");
            break;
        default:
            printf("Desconhecido\n");
    }
}