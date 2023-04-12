#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

int *pilaReal;
int pila[MAX_SIZE];
int topeInicial = -1, topeFinal = MAX_SIZE;
int tamPila1, tamPila2;

void crearArreglo(int tamTotal)
{
    pilaReal = (int *)calloc(tamTotal, sizeof(int));
    if (pilaReal == NULL)
    {
        printf("Error: no se pudo crear el arreglo.\n");
        exit(0);
    }
}

void push1(int valor)
{
    if (topeInicial + 1 == topeFinal)
    {
        printf("Error: la pila 1 esta llena.\n");
        return;
    }
    topeInicial++;
    pilaReal[topeInicial] = valor;
    tamPila1++;
}

void push2(int valor)
{
    if (topeFinal - 1 == topeInicial)
    {
        printf("Error: la pila 2 esta llena.\n");
        return;
    }
    topeFinal--;
    pilaReal[topeFinal] = valor;
    tamPila2++;
}

int pop1()
{
    if (topeInicial == -1)
    {
        printf("Error: la pila 1 esta vacia.\n");
        return -1;
    }
    int valor = pilaReal[topeInicial];
    topeInicial--;
    tamPila1--;
    return valor;
}

int pop2()
{
    if (topeFinal == MAX_SIZE)
    {
        printf("Error: la pila 2 esta vacia.\n");
        return -1;
    }
    int valor = pilaReal[topeFinal];
    topeFinal++;
    tamPila2--;
    return valor;
}

int sumaPilas()
{
    int suma = 0;
    for (int i = 0; i < tamPila1; i++)
    {
        suma += pilaReal[i];
    }
    for (int i = MAX_SIZE - 1; i > MAX_SIZE - tamPila2 - 1; i--)
    {
        suma += pilaReal[i];
    }
    return suma;
}

int main()
{
    int tamTotal;
    printf("Ingrese el tamano total del arreglo: ");
    scanf("%d", &tamTotal);
    crearArreglo(tamTotal);

    int opcion = 0;
    while (opcion != 4)
    {
        printf("\nEliga una opcion:\n");
        printf("1. Insertar elemento en pila 1.\n");
        printf("2. Insertar elemento en pila 2.\n");
        printf("3. Sumar y eliminar elementos de ambas pilas.\n");
        printf("4. Salir.\n");
        scanf("%d", &opcion);

        int valor;
        switch (opcion)
        {
        case 1:
            printf("Ingrese un valor para la pila 1: ");
            scanf("%d", &valor);
            push1(valor);
            break;
        case 2:
            printf("Ingrese un valor para la pila 2: ");
            scanf("%d", &valor);
            push2(valor);
            break;
        case 3:
            printf("La suma de los elementos de las pilas es: %d\n", sumaPilas());
            while (topeInicial != -1)
            {
                printf("Eliminando elemento de la pila 01: %d\n", pop1());
            }
            while (topeFinal != MAX_SIZE)
            {
                printf("Eliminando elemento de la pila 02: %d\n", pop2());
            }
            free(pilaReal);
            printf("Se ha liberado la memoria asignada para el arreglo\n");
            break;
        case 4:
            printf("Saliendo del programa");
            opcion = 4;
            break;
        default:
            printf("No se a selección una opción");
            break;
        }
    }
    
return 0;    
}