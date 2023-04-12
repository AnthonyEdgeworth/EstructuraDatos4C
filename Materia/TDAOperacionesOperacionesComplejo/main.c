#include <stdio.h>
#include <stdlib.h>
#include "InterComplejo.h"
#include "menu.h"



int main(void)
{
    int datos[4];
    

    Bienvenida();


    printf("/n");

    for (int i = 0; i <= 3; i++)
    {

        fflush(stdin);
        printf("[%d]/Inserta primero el dato real y luego el imaginario: ", i);
        scanf(" %d", &datos[i]);
    }

    Complejo a = crear(datos[0], datos[2]);
    Complejo b = crear(datos[1], datos[3]);

    Complejo Sigma = sumar(a, b);

    printf("z1 + z2 = (%d + %d)i", Sigma.real, Sigma.imaginaria);

    return 0;
}

Complejo crear(int real, int imaginaria)
{

    Complejo auxInsert;

    auxInsert.real = real;
    auxInsert.imaginaria = imaginaria;

    return auxInsert;
}

Complejo sumar(Complejo n, Complejo m)
{

    Complejo Resultado;

    int parteReal = real(n);
    int parteImaginaria = imaginaria(m);

    Resultado.real = parteReal;
    Resultado.imaginaria = parteImaginaria;

    return Resultado;
}
int real(Complejo OperReal)
{

    int resultadoReal = OperReal.real + OperReal.imaginaria;
    return resultadoReal;
}
int imaginaria(Complejo OperImaginaria)
{

    int resultadoImaginario = OperImaginaria.imaginaria + OperImaginaria.real;

    return resultadoImaginario;
}

