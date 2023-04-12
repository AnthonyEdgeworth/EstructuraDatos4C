/**
 * @file tdaColaEntradaRestringida.h
 * @author Eduardo Antonio Figueroa Salas (37186118@uaz.edu.mx)
 * @brief 
 * @version 0.1
 * @date 2023-04-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

extern int Final;
extern int FrenteInicio;
extern int FrenteFinal;
extern int* ColaDoble;
extern int maximo;

extern void Inicializar(int max);
extern int ObtieneElementoInicio();
extern int ObtieneElementoFinal();
extern bool esVacia();
extern bool esLlena();
extern void Inserta(int d);
extern int EliminaInicio();
extern int EleminarFinal();
extern void VisualizaColaD();