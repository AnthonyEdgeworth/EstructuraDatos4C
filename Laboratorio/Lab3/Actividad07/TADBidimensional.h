/**
 * @file TADBidimensional.h
 * @author Eduardo Antonio Figueroa Salas (37186118@uaz.edu.mx)
 * @brief
 * @version 0.1
 * @date 2022-02-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdbool.h>
#ifndef TADBIDIMENSIONAL_H
#define TADBIDIMENSIONAL_H

#define MAX 10

typedef int **TADcadena;
typedef int **TADcadena2;

typedef struct
{

    int i, j, max_columnas, max_filas, CambioDeColumna, num_guardar, auxiliar;

} TADBidimensional;

#define H(a, b) ((a) > (b) ? (a) : (b))
bool InsertarDesordenado(TADcadena2 e, TADcadena s, int ng);
bool EliminarDesorden(TADcadena2 e, TADcadena s, int q);
void imprimir(TADcadena2 e, TADcadena s);
int BuscaSec(TADcadena2 e, TADcadena s, int t);
bool EsVacia(TADcadena2 e, TADcadena s, int n, int m);
bool EsLlena(TADcadena2 e, TADcadena s, int n, int m);
bool ModificaDesordenado(TADcadena2 e, TADcadena s, int v, int n);
void OrdenarDesordenado(TADcadena2 e, TADcadena s);
void Menu(TADcadena2 e, TADcadena s);
void CambioDeColumna(TADcadena2 e, TADcadena s);
bool InsertarOrdenado(TADcadena2 e, TADcadena s, int ng);
#endif
