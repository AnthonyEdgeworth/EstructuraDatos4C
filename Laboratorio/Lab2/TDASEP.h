#ifndef TDASEP_H
#define TDASEP_H

struct Kid {
    char NombreKid[60];
    char CURP[60];
    char NombrePadre[60];
    char InstitutoAnterior[60];
    float PromedioAnterior;
};

void IngresoDeDatos();
void MostrarKid(struct Kid *array, int tam);
void EscribirArchivo(struct Kid *array, int tam);

#endif

