#include "TDAListaDoblementeEnlazada.h"

Pila *crear()
{

    Pila *p;
    p = (Pila *)malloc(sizeof(Pila));
    p->indice = 0;
    p->total = 0;

    return p;
}

bool estaVacia(Pila pila)
{

    return pila.total == 0;
}

bool estaLlena(Pila pila)
{

    return pila.total == MAX_ELEMENTOS;
}

int push(Pila *pila, int dato)
{

    if (pila->total < MAX_ELEMENTOS)
    {

        pila->datos[pila->indice] = dato;
        pila->indice++;
        pila->total++;
        return 1;
    }

    else
    {
        printf("\n No se pudo insertar, está lleno el arreglo");
        return 0;
    }
}

int pop(Pila *pila)
{
    int aux;
    if (pila->total > 0)
    {
        aux = pila->datos[pila->indice-1];
        pila->indice--;
        pila->total--;
        return aux;
    }

    else
        return -1;
}
