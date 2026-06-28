#ifndef VEICULO_H
#define VEICULO_H
//4.1
typedef struct {
    char marca[50];
    char modelo[50];
    int ano;
    float valor_mercado;
    char tipo; // 'P' = Passeio, 'U' = Utilitário, 'E' = Esportivo
} Veiculo;

void cadastrarVeiculo(Veiculo *v);
void mostrarVeiculo(Veiculo v);

#endif