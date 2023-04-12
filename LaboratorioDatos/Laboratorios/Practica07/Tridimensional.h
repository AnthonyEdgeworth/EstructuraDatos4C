#ifndef TRIDIMENSIONAL_H
#define TRIDIMENSIONAL_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//TODO: Datos que se van a usar

typedef struct {
    int p;
    int r;
    int c;
} Indrcp;



extern int cntelem,m,n, pl;
extern int ***tridi;
extern Indrcp indrcp;
extern int dato;


//TODO: Funciones que se van a usar



bool InsertarDesordenado(int);
bool EliminaDesorden(int);
void imprimir();
Indrcp BuscaSec(int);
bool EsVacia();
bool ModificaDesordenado(Indrcp, int);
void OrdenaDesordenado();
bool Crear(int,int,int);
int cmpfunc(const void *a, const void *b);
void menuModificar();
int comparar(const void *a, const void *b);

#endif