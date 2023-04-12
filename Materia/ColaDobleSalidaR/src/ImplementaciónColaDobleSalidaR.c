#include "ColaDobleSalidaR.h"

void CrearCDSR(int max)
{
    maximo = max;
    FinalInicio = -1;
    Final_Final = -1;
    Frente = -1;

    ColaDoble = (int *)calloc(max, sizeof(int));
}

int ObtieneElemento()
{
    return ColaDoble[Frente];
}

bool esVacia()
{
    return Frente == -1;
}

bool esLlena()
{
    return Final_Final == maximo - 1;
}

void InsertaInicio(int d)
{
    if (!esLlena())
    {
        for (int i = Final_Final + 1; i > 0; i--)
        {
            ColaDoble[i] = ColaDoble[i - 1];
        }

        FinalInicio = 0;
        Final_Final++;
        ColaDoble[FinalInicio] = d;
        if (FinalInicio == 0 && Final_Final == 0)
        {
            Frente = 0;
        }
    }
    else
    {
        printf("No se inserto por inicio %d, La cola esta llena", d);
    }
}

void InsertarFinal(int d)
{
    if (!esLlena())
    {
        Final_Final++;
        ColaDoble[Final_Final] = d;

        if (FinalInicio == -1)
        {
            Frente = 0;
            FinalInicio = 0;
        }
    }
    else
    {
        printf("\n No se inserto por final %d La cola esta llena", d);
    }
}

int Eliminar()
{
    int elemento;
    if (esVacia())
    {
        printf("Desbordeamiento");
        return 0;
    }

    elemento = ColaDoble[Frente];
    ColaDoble[Frente] = 0;

    if (Frente == FinalInicio && Final_Final == 0)
    {
        FinalInicio = -1;
        Final_Final = -1;
        Frente = -1;
        return elemento;
    }

    if (Frente == FinalInicio)
    {
        Frente++;
        FinalInicio++;
    }
    else
    {
        Frente++;
    }

    return elemento;
}

void muestraColaDoble()
{
    for (int i = 0; i < maximo; i++)
    {
        printf("\n Elemento %d = %d", i, ColaDoble[i]);
    }
}