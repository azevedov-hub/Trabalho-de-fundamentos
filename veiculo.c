#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include "Veiculo.h"

#define MAX_MODELOS 5

static const char *marcas[] = {
    "HONDA",
    "TOYOTA",
    "FIAT",
    "FORD",
    "CHEVROLET",
    "VOLKSWAGEN",
    "BMW",
    "MERCEDES",
    "AUDI",
    "HYUNDAI",
    "RENAULT",
    "NISSAN",
    "JEEP",
    "PEUGEOT",
    "CITROEN",
    "MITSUBISHI",
    "KIA",
    "VOLVO",
    "PORSCHE",
    "FERRARI"
};

#define TOTAL_MARCAS (sizeof(marcas) / sizeof(marcas[0]))

// Lista de modelos, na MESMA ordem das marcas acima
// (Obs.: nomes sem espacos/hifens, pois o modelo digitado so aceita alfanumericos)
static const char *modelos[TOTAL_MARCAS][MAX_MODELOS] = {
    /* HONDA      */ {"CIVIC", "CITY", "FIT", "CRV", "ACCORD"},
    /* TOYOTA     */ {"COROLLA", "HILUX", "YARIS", "CAMRY", "RAV4"},
    /* FIAT       */ {"UNO", "PALIO", "ARGO", "TORO", "MOBI"},
    /* FORD       */ {"KA", "FIESTA", "FOCUS", "RANGER", "ECOSPORT"},
    /* CHEVROLET  */ {"ONIX", "CELTA", "CORSA", "S10", "TRACKER"},
    /* VOLKSWAGEN */ {"GOL", "FOX", "POLO", "VIRTUS", "TCROSS"},
    /* BMW        */ {"SERIE3", "SERIE5", "X1", "X5", "M3"},
    /* MERCEDES   */ {"CLASSEA", "CLASSEC", "CLASSEE", "GLA", "GLC"},
    /* AUDI       */ {"A3", "A4", "Q3", "Q5", "TT"},
    /* HYUNDAI    */ {"HB20", "CRETA", "TUCSON", "IX35", "SANTAFE"},
    /* RENAULT    */ {"SANDERO", "LOGAN", "DUSTER", "KWID", "CAPTUR"},
    /* NISSAN     */ {"MARCH", "VERSA", "KICKS", "SENTRA", "FRONTIER"},
    /* JEEP       */ {"RENEGADE", "COMPASS", "COMMANDER", "WRANGLER", "CHEROKEE"},
    /* PEUGEOT    */ {"208", "2008", "3008", "308", "PARTNER"},
    /* CITROEN    */ {"C3", "C4CACTUS", "AIRCROSS", "C4LOUNGE", "JUMPY"},
    /* MITSUBISHI */ {"L200", "PAJERO", "ASX", "ECLIPSECROSS", "OUTLANDER"},
    /* KIA        */ {"SPORTAGE", "SORENTO", "CERATO", "PICANTO", "SOUL"},
    /* VOLVO      */ {"XC60", "XC90", "S60", "V40", "XC40"},
    /* PORSCHE    */ {"911", "CAYENNE", "MACAN", "PANAMERA", "BOXSTER"},
    /* FERRARI    */ {"488", "F8", "ROMA", "PORTOFINO", "SF90"}
};

void cadastrarVeiculo(Veiculo *v)
{
    int i, valido;
    int indiceMarca = -1;

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

    // Verifica se possui apenas letras
    for (i = 0; v->marca[i] != '\0'; i++)
    {
        if (!isalpha(v->marca[i]))
        {
            valido = 0;
            break;
        }
    }

    if (!valido)
    {
        printf("\nMarca invalida! Digite apenas letras.\n");
        continue;
    }

    // Converte a marca digitada para maiúsculas
    for (i = 0; v->marca[i] != '\0'; i++)
    {
        v->marca[i] = toupper(v->marca[i]);
    }

    // Procura a marca na lista
    valido = 0;

    for (i = 0; i < TOTAL_MARCAS; i++)
    {
        if (strcmp(v->marca, marcas[i]) == 0)
        {
            valido = 1;
            indiceMarca = i;
            break;
        }
    }

    if (valido)
        break;

    printf("\nMarca nao cadastrada!\n");
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
                break;
            }
        }

        if (!valido)
        {
            printf("\nModelo invalido! Digite apenas letras/numeros.\n");
            continue;
        }

        // Converte o modelo digitado para maiúsculas
        for (i = 0; v->modelo[i] != '\0'; i++)
        {
            v->modelo[i] = toupper(v->modelo[i]);
        }

        // Verifica se o modelo pertence a marca escolhida
        valido = 0;

        for (i = 0; i < MAX_MODELOS; i++)
        {
            if (strcmp(v->modelo, modelos[indiceMarca][i]) == 0)
            {
                valido = 1;
                break;
            }
        }

        if (valido)
            break;

        printf("\nModelo incompativel com a marca %s! Digite novamente.\n", v->marca);
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