/**
 * @file TADUnidimensionales.h
 * @author Eduardo Antonio Figueroa Salas (you@domain.com)
 * @brief Hacer un arreglo Unidimensional que guarde n numero de elementos
 * @version 0.1
 * @date 2022-02-15
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Datos que manejara */
#ifndef TADUNIDIMENSIONALES_H
#define TADUNIDIMENSIONALES_H
#define MAX 10

typedef int *TADcadena;

/*Operaciones del TAD*/
#define H(a, b) ((a) > (b) ? (a) : (b))

void EliminaDesorden(TADcadena s, int d); // Posible apuntadortipo
void ImprimeArreglo(TADcadena s);
int BuscaSec(TADcadena s, int u); // Posible apuntador
void Menu(TADcadena s);
void Visualice(TADcadena s);
int Add(TADcadena s, int d);
bool IsFull(TADcadena s);
bool IsEmpty(TADcadena s);
int Remove(TADcadena s, int d);
void Ordenar(TADcadena s);
void Modificar(TADcadena s);

#endif
