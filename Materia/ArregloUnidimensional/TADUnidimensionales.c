/**
 * @file TADUnidimensionales.c
 * @author Eduardo Antonio Figueroa Salas (you@domain.com)
 * @brief Hacer un arreglo Unidimensional que guarde n numero de elementos
 * @version 0.1
 * @date 2022-02-15
 *
 * @copyright Copyright (c) 2022
 *
 */


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //Establece Rango
#include "TADUnidimensionales.h"

#define MAX 10

int ind = -1; // Se inicializa en -1 ya que el primer elemento se agregará en la posición 0
int cant;

bool IsFull(TADcadena s)
{
    return ind >= MAX - 1;
}

bool IsEmpty(TADcadena s)
{
    return ind <= -1;
}

int Add(TADcadena s, int d)
{
    if (IsFull(s)) {
        return 0;
    } else {
        ind++;
        s[ind] = d;
        return 1;
    }
}

int Remove(TADcadena s, int d)
{ 
    int pos = BuscaSec(s, d);
    if (pos == -1)
        return -1;
    for (int i = pos; i < ind; i++) {
        s[i] = s[i + 1];
    }
    s[ind] = 0;
    if (ind > -1) ind--;
    return 1;
}

void Ordenar(TADcadena s)
{
    int j, aux;
    for (int i = 1; i <= ind; i++)
    {
        j = i;
        aux = s[i];
        while (j > 0 && aux < s[j - 1])
        {
            s[j] = s[j - 1];
            j = j - 1;
        }
        s[j] = aux;
    }
}

void Modificar(TADcadena s)
{				
    printf("Que posici%cn quieres modificar?", 162);
    scanf("%d", &cant);
    if (cant < 0 || cant > ind) {
        printf("\n\n El indice esta fuera de rango\n");
    } else {
        printf("\n Que valor quieres poner?");
        scanf("%d", &cant);
        s[cant] = cant;
    }
}

void EliminaDesorden(TADcadena s, int d)
{
    d = 0;
}

int BuscaSec(TADcadena s, int u)
{
    int j = 0;
    if (IsEmpty(s))
        return -1;
    do {
        j++;
    } while (j <= ind && s[j] != u);
    if (j > ind) {
        printf("No se encontró el elemento %d\n", u);
        return -1;
    }
    printf("El elemento %d se encuentra en el índice %d\n", u, j);
    return j;
}

void Visualice(TADcadena s)
{
    if (IsEmpty(s)) {
        printf("Arreglo vacio\n");
    } else {
        printf("\n ---------- Arreglo Unidimensional ----------\n");
        for (int i = 0; i <= ind; i++) {
            printf("\n--------------------\n");
            printf("[%d] En la posicion %d", s[i], i);
        }
    }
    printf("\n--------------------\n");
}



