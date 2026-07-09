#ifndef CONDUTOR_H
#define CONDUTOR_H


typedef struct {
      char nome[80];
      char rg[5];
      int  idade;
      int  sinistros;
      char cnh;             /* 'A', 'B' ou 'C' */
} Condutor;

void condutores(Condutor *condutor);

//void condutores(Condutor *condutor){



    
//}

#endif