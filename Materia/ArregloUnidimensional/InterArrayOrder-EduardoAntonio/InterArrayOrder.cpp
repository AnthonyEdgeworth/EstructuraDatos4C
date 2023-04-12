#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "InterArrayOrder.h"
int main (){
	char opc;
	int pos;
	printf("\nImplementa las operaciones basicas de un arreglo unidimensional\n\n");
	printf("Proporcione el tamaño del arreglo\n");
	scanf("%d",&max);
	fflush(stdin);
	if (!CrearArray(max)){
		printf("No se creo el arreglo en memoria");
		return 0;
	}
	do{
		printf("\nOperaciones Arreglo Unidimensional\n");
		printf ("1.......Insertar\n");
		printf("2.......Eliminar\n");
		printf("3.......Visualizar\n");
		printf("4.......Modificar\n");
		printf("0.......Salir\n Elige una Opcion\n");
		scanf("%c",&opc);
		fflush(stdin);
		switch (opc){
		case '1': printf("\nDame el elemento a insertar\n ");
		scanf ("%d", &d);
		fflush(stdin);
		if (Add(d)==1)
			printf ("\nEl elemento se inserto correctamente\n");
		else
			printf("\nEl elemento No se inserto\n"); 
		Visualice();					
		break;		
		case '2':
			printf("\nDame el elemento a eliminar ");
			scanf("%d",&d);
			fflush(stdin);
			if (Remove(d)==1)
				printf ("El elemento se elimino correctamente\n");
			else
				printf("El elemento No se elimino \a\n"); 
			Visualice();
			break;
		case '3':
			Visualice();
			break;
		case '0':
			break;
		case '4':
		  printf("\n Cual es la pocision que desea modificar?(tomando el cero como una posicion)");
		  scanf("%d",&pos);
		 int i;
		  if(pos<=max)
			 
			  for(i=0;i<=max;i++)
			     if (i==pos){
				  printf("\n Cual es la valor?\n");
				  scanf("%d",&db);
				  array[i]=db;}
			  
			  for(int i=0;i<max;i++)
			  {
				  printf("[%d]",array[i]);
			  }
			  printf("\n");		  
			
			break;
			
			
		}		 
	}while(opc!='0');
	
	return 0;
}
