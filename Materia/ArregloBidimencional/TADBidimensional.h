#include <stdbool.h>
#ifndef TADBIDIMENSIONAL_H
#define TADBIDIMENSIONAL_H

typedef struct 
{
    int i;
    int j;

}Indij;


int cntelem =0;
int m = 0;
int n = 0;

int **matriz;
Indij indij;
int dato = 0;


bool InsertarOrdenado(int){};
bool EliminaDesordent(int){};
void ImprimeMatriz(){};
Indij BuscaSec(int){}
bool Esllena(){};
bool EsVacia(){};
void OrdenarDesordenado(){};
bool ModificaDesordenado(int datoB, int dato){};


#endif