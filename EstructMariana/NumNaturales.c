#include <stdio.h>
#include <stdlib.h>
#include "NumNaturales.h"

				
 int main() 
 {			
 int x;
 int y;				
 struct NumerosNaturales natu=Crear(x,y);
					
 printf("Suma y la multiplicacion (a y b).-\n");
 printf("Numero a: \n");
 scanf("%d",&x);
 printf("Numero b: \n");
 scanf("%d",&y);
					
 if(x!=0 && y!=0)
 {
    
						
 struct NumerosNaturales naturalN = Crear(x,y);
						
 int natu=Suma(naturalN);
 printf("Resultado de la suma= %d\n",natu);
						
 int natu1=Multiplicacion(naturalN);
 printf("Resultado de la mutiplicacion= %d\n", natu1);
						
 printf("Orden de los numeros\n");
 Ordenar(naturalN);
 
 }
					
 return 0;

}