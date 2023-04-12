//Mariana Estefania Barcenas Rodriguez
//  FECHA: 11/03/2022

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

bool PrimNumRecursivo(int num, int div);


int main()
{
	
	
	int n;

    printf("\n Se le indicara con un 1 si es un numero primo, en cambio si le sale un 0 significa que no es numero primo");
	printf("\nIngresa un numero: ");
	scanf("%d",&n);
	
	printf("%d", PrimNumRecursivo(n,2));
	
	
	
}

bool PrimNumRecursivo(int num, int div) {
	if (num/2 < div) 
    {
        return true;
    }
    else   
    {
		if ((num%div) == 0)
		{
			return false;
		}
		
		else 
		{ 
			PrimNumRecursivo(num,div+1);
		}
    }
}