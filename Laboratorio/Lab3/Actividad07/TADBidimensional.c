/**
 * @file TADBidimensional.c
 * @author Eduardo Antonio Figueroa Salas (37186118@uaz.edu.mx)
 * @brief
 * @version 0.1
 * @date 2022-02-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_FILAS 100
#define MAX_COLUMNAS 100

typedef int TADcadena[MAX_FILAS];
typedef int TADcadena2[MAX_COLUMNAS];

int mayor = INT_MIN;

bool EsVacia(TADcadena2 e, TADcadena s, int n, int m) {
    return s[n] > mayor && e[m] > mayor;
}

bool EsLlena(TADcadena2 e, TADcadena s, int n, int m) {
    return s[n] == mayor && e[m] == mayor;
}

bool InsertarDesordenado(TADcadena2 e, TADcadena s, int ng)
{
    int i, j, num_guardar;
    int max_filas = ng, max_columnas = 1;

    s[ng] = mayor;

    for (j = 0; j < MAX_COLUMNAS; j++)
    {
        e[j] = mayor;
    }

    while (true)
    {
        fflush(stdin);
        printf("\n Dame el elemento que quieras insertar");
        printf(" \n Recuerda, para salir del 'modo inserccion' solo tienes que precionar '2022' \n");
        scanf("%d", &num_guardar);

        if (num_guardar == 2022)
        {
            break;
        }

        if (i >= MAX_FILAS || j >= MAX_COLUMNAS)
        {
            printf("\n Insuficiente 'RAM'");
            return false;
        }

        // Insertar el elemento de manera ordenada
        i = 0;
        while (i < j && e[i] <= num_guardar)
        {
            i++;
        }
        for (int k = j; k > i; k--)
        {
            e[k] = e[k - 1];
        }
        e[i] = num_guardar;

        if (j == 0)
        {
            s[ng] = num_guardar;
        }

        j++;
        if (j > max_columnas)
        {
            max_columnas = j;
        }
    }

    if (max_columnas > MAX_COLUMNAS)
    {
        printf("\n Insuficiente 'RAM'");
        return false;
    }

    for (i = 0; i <= ng; i++)
    {
        if (s[i] == mayor)
        {
            break;
        }
    }

    if (i >= MAX_FILAS)
    {
        printf("\n Insuficiente 'RAM'");
        return false;
    }

    if (max_columnas > 1)
    {
        for (i = 0; i < MAX_FILAS; i++)
        {
            if (e[i] != mayor)
            {
                break;
            }
        }

        if (i >= MAX_FILAS)
        {
            printf("\n Insuficiente 'RAM'");
            return false;
        }
    }

    return true;
}

void imprimir(TADcadena2 e, TADcadena s) {
    printf("\n *********** Arreglo Bidimensional ***********");
    for (int i = 0; s[i] != mayor && i < MAX_FILAS; i++) {
        printf("\n [%d] ", s[i]);
        for (int j = 0; e[j] != mayor && j < MAX_COLUMNAS; j++) {
            printf("[%d] ", e[j]);
        }
    }
    printf("\n");
}


