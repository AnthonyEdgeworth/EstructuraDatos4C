/**
 * @file operacionesTdaColaEntradaRestringida.c
 *@author Eduardo Antonio Figueroa Salas (37186118@uaz.edu.mx)
 *
 * @brief
 * @version 0.1
 * @date 2023-04-07
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "tdaColaEntradaRestringida.h"

void Inicializar(int max)
{

    Final = -1;
    FrenteInicio = -1;
    FrenteFinal = -1;
    ColaDoble = calloc(max, sizeof(int));
    maximo = max;
}

int ObtieneElementoInicio()
{

    return ColaDoble[FrenteInicio];
}

int ObtieneElementoFinal()
{

    return ColaDoble[FrenteFinal];
}

bool esVacia()
{

    return Final == -1;
}

bool esLlena()
{

    return Final == maximo - 1;
}

void Inserta(int d)
{
    if (!esLlena())
    {
        Final++;
        ColaDoble[Final] = d;
        FrenteFinal = Final;
        if (Final == 0)
            FrenteInicio = 0;
    }
    else
        printf("\n Desbordamiento");
}

int EliminaInicio(){
    int elemento;
    if(esVacia())
        return 0;

    elemento = ColaDoble[FrenteInicio];
    int i;
    for (i = 1; i <= Final; i++)
        ColaDoble[i - 1] = ColaDoble[i];

    ColaDoble[i - 1] = 0;
    Final--;
    if (Final == -1)
        FrenteInicio = FrenteFinal = -1;
    else
        FrenteInicio++;

    return elemento;
}


int EleminarFinal(){

    int elemento;
    if(esVacia())
        return 0;

    elemento = ColaDoble[FrenteFinal];
    ColaDoble[FrenteFinal] = 0;

    if (FrenteFinal == FrenteInicio)
    {
        FrenteInicio = FrenteFinal = Final = -1;
        return elemento;        
    }

    FrenteFinal--;
    Final--;
    return elemento;

}

void VisualizaColaD(int max){

    printf("\n Estado de la estructura \n");

    for (int i = 0; i < max; i++)
    {
        printf("\n Elemento [%d] = %d",i,ColaDoble[i]);
    }
    

}