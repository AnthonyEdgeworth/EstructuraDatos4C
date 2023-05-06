/**
 * @file TDAListaDoblementeEnlazada.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <gtk/gtk.h>

#define MAX_ELEMENTOS 10

typedef struct pila
{
    int indice;
    int total;
    int datos[MAX_ELEMENTOS];

}Pila;

extern Pila *crear();
extern bool estaVacia(Pila pila);
extern bool estaLlena(Pila pila);
extern int push(Pila *pila, int dato);
extern int pop (Pila * pila);


//TODO: Archivos para la ventana
extern int ventana(int argc, char *argv[]);
extern void load_glade_file();
