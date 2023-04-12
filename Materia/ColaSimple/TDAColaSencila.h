/**
 * @file TDAColaSencila.h
 * @author Eduardo Antonio Figueroa Salas (anthonyfse@hotmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef TDACOLASENCILA_H
#define TDACOLASENCILA_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//TODO: Datos que se van a ocupar
typedef struct 
{
    int elemento;
}com;

extern com Componente;
extern int Frente;
extern int Final;
extern int* ColaS;

//TODO: Funciones que se van a ocupar

int *CreateCS(int size);
bool isEmpy();
bool isFull();
bool QueueCS(int* Cola,int ele);
void VisualiceCS(int*);
int SizeCs(int*);
int GetItemCS(int* Cola, int pos);



#endif


