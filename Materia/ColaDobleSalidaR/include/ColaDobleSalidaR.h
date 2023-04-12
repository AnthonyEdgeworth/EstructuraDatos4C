/**
 * @file ColaDobleSalidaR.h
 * @author Eduardo Antonio Figueroa Salas (37186118@uaz.edu.mx)
 * @brief 
 * @version 0.1
 * @date 2023-04-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//TODO: Datos que se van a utilizar



extern int FinalInicio;
extern int Final_Final;
extern int Frente;
extern int* ColaDoble;
extern int maximo;

extern void CrearCDSR(int max);
extern int ObtieneElemento();
extern bool esVacia();
extern bool esLlena();
extern void InsertaInicio(int d);

