#include "TDAColaCircular.h"

// Definición de la estructura de la cola circular


// Funciones para manejar la cola circular
ColaCircular crearCc(int tamano) {
    ColaCircular cola;
    cola.datos = calloc(tamano, sizeof(int));
    cola.tamano = tamano;
    cola.cntele = 0;
    cola.Prim = 0;
    cola.sl = 0;
    return cola;
}

bool isEmpy(ColaCircular cola) {
    return cola.cntele == 0;
}

bool isFull(ColaCircular cola) {
    return cola.cntele == cola.tamano;
}

int SizeCc(ColaCircular cola) {
    return cola.tamano;
}

void QueueCc(ColaCircular *cola, int ele) {
    if (isFull(*cola)) {
        printf("Desbordamiento\n");
    } else {
        cola->datos[cola->sl] = ele;
        cola->sl = (cola->sl + 1) % cola->tamano;
        cola->cntele++;
    }
}

int DequeueCc(ColaCircular *cola) {
    if (isEmpy(*cola)) {
        printf("Subdesbordamiento\n");
        return 0;
    } else {
        int e = cola->datos[cola->Prim];
        cola->Prim = (cola->Prim + 1) % cola->tamano;
        cola->cntele--;
        if (isEmpy(*cola)) {
            cola->Prim = cola->sl = 0;
        }
        return e;
    }
}

void VisualiceCc(ColaCircular* cola) {
    printf("Estado actual de la cola circular:\n");
    if (isEmpy(*cola)) {
        printf("La cola está vacía.\n");
    } else {
        int f = cola->Prim;
        do {
            printf("Elemento %d = %d\n", f, cola->datos[f]);
            f = (f + 1) % cola->tamano;
        } while (f != cola->sl);
    }
}
