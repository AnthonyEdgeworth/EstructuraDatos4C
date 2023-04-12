#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "TADBidimensional.h"
#include "BoxToysEstructuras.h"
#include <glib.h>
#include <limits.h>

bool EsVacia(){

    return cntelem == 0;

}
bool EsVacia(){

 return cntelem >= (m * n);

}

bool InsertarOrdenado(int d){


if (!EsVacia())
{
    if(!Esllena())  
        return false;
    else
        if(!(MayorEqual(indij.j,(n-1))))
            indij.j

}




indij.i = 0;
indij.j = 0;
matriz[indij.i][indij.j] = d;
cntelem++;
return true;


}