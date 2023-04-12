//MARIANA ESTEFANIA BARCENAS RODRIGUEZ
//ESTRUCTURA DE DATOS
//11 FEBRERO 2022
#include <stdio.h>     
#include <string.h>
#include <stdlib.h>

struct NumerosNaturales
 {
	int a;
	int b;
 };
typedef struct NumerosNaturales NumerosNaturales;

struct NumerosNaturales Crear(int a, int b)
{
	struct NumerosNaturales naturalN;
	naturalN.a=a;
	naturalN.b=b;
	return naturalN;
}

 int Suma(struct NumerosNaturales num1)
 {
 int natu;
 natu = num1.a + num1.b;
 return natu;
 }
		
 int Multiplicacion(struct NumerosNaturales num2)
 {
 int natu;
 natu = num2.a * num2.b; 
 return natu;
 }
			
 void Ordenar(struct NumerosNaturales num3)
 {
 if(num3.a<num3.b){ 
	printf("El orden es: a=%d, b=%d\n",num3.a,num3.b);
 }
	else if (num3.a>num3.b)
    {
		printf("El orden es: b=%d, a=%d\n",num3.b,num3.a);
	}
	else
    {
		printf("Ambos numeros ingresados son iguales! a=%d y b=%d.\n",num3.a,num3.b);
	}
				
	}	



