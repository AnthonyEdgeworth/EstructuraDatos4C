#include "ColaDobleSalidaR.h"

void CrearCDSR(int max)
{

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

bool esLlena() {
    return Final_Final == maximo-1;
}

void InsertaInicio(int d){
    if (!esLlena())
    {
        for (int i = Final_Final+1; i > 0; i--)   
            {ColaDoble[i] = ColaDoble[i-1];}
       
        FinalInicio=0;
        Final_Final++;
        ColaDoble[FinalInicio] = d;
        if(FinalInicio == 0 && Final_Final == 0)
            {Frente = 0;}
    }
    else
        printf("No se inserto por inicio %d, La cola esta llena",d);
    
    

    
}