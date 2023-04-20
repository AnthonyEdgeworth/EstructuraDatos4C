/**
 * @file TDAColaCircular.h
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
#include <stdlib.h>
#include <stdbool.h>


//TODO: Datos que se van a usar

typedef struct {
    int *datos;
    int tamano;
    int cntele;
    int Prim;
    int sl;
} ColaCircular;

typedef struct TDAColaCircular
{
    char propietario[100];
    char nombreDocumento[100];
    bool estado;
    int tamanoDocumento;
    

};




//TODO: Funciones a manejar

extern ColaCircular crearCc(int tamano);
extern bool isEmpy(ColaCircular cola);
extern bool isFull(ColaCircular cola);
extern void QueueCc(ColaCircular *cola, int ele);
extern int DequeueCc(ColaCircular *cola);
extern void VisualiceCc(ColaCircular* cola);
extern int SizeCc(ColaCircular cola);
extern int GetItem(ColaCircular* cola, int indice);