/**
 * @file main.c
 * @author Eduardo Antonio Figueroa Salas (37186118@uaz.edu.mx)
 * @brief 
 * @version 0.1
 * @date 2023-03-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 5

int Frente = -1;
int Final = -1;
int ColaS[MAX_SIZE];

bool isEmpy(){
    return Frente == -1 && Final == -1;
}

bool isFull(){
    return Final == MAX_SIZE-1;
}

bool QueueCS(int ele){
    if(isFull()){
        printf("La cola está llena, no se puede agregar el elemento %d.\n", ele);
        return false;
    }
    if(isEmpy()){
        Frente = 0;
    }
    Final++;
    ColaS[Final] = ele;
    return true;
}

int DequeueCS(){
    int e;
    if(isEmpy()){
        printf("La cola está vacía, no se puede remover ningún elemento.\n");
        return -1;
    }
    e = ColaS[Frente];
    if(Frente == Final){
        Frente = -1;
        Final = -1;
    }
    else{
        Frente++;
    }
    return e;
}

void VisualizeCS(){
    if(isEmpy()){
        printf("La cola está vacía.\n");
        return;
    }
    printf("La cola es: ");
    for(int i=Frente; i<=Final; i++){
        printf("%d ", ColaS[i]);
    }
    printf("\n");
}

int SizeCs(){
    if(isEmpy()){
        printf("La cola está vacía.\n");
        return 0;
    }
    return Final - Frente + 1;
}

int main(){
    int opcion = 0;
    int valor;
    while(opcion != 5){
        printf("\nSelecciona una opción:\n");
        printf("1. Agregar elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Visualizar cola\n");
        printf("4. Obtener tamaño de la cola\n");
        printf("5. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                printf("Ingresa el elemento que deseas agregar: ");
                scanf("%d", &valor);
                QueueCS(valor);
                break;
            case 2:
                DequeueCS();
                break;
            case 3:
                VisualizeCS();
                break;
            case 4:
                printf("El tamaño de la cola es: %d\n", SizeCs());
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
                break;
        }
    }
    return 0;
}
