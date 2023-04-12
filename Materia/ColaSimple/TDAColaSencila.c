#include "TDAColaSencila.h"

//TODO: Datos de la biblioteca

com Componente;
int Frente;
int Final;
int* ColaS;

int *CreateCS(int size){
    int *Cola = (int*)calloc(size,sizeof(int));
    return Cola;
}

bool isEmpy(){
    return Frente == Final;
}

bool isFull(){
    int size = 5; // Ejemplo de tamaño fijo de la cola
    return Final == size-1;
}

bool QueueCS(int* Cola,int ele){
    if(isFull() == true){
        return false;
    }
    Final++;
    Cola[Final] = ele;
    if (Final == 0){
        Frente = 0;
    }
    return true;
}

int DequeueCS(int* Cola){
    int e;
    if(isEmpy() == true){
        return NULL;
    }
    e = Cola[Frente];
    Cola[Frente] = NULL;
    Frente++;
    return e;
}

void VisualiceCS(int* Cola){
    printf("La cola es: ");
    for(int i=Frente; i<=Final; i++){
        printf("%d ", Cola[i]);
    }
    printf("\n");
}

int SizeCs(int* Cola){
    return Final - Frente + 1;
}

int GetItemCS(int* Cola, int pos){
    return Cola[pos];
}