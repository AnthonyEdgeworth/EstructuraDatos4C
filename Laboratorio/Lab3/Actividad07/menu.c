#include "TADBidimensional.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //Establece Rango

int opc = 0;

TADBidimensional Limit_Max;

void Menu(TADcadena2 e, TADcadena s)
{
	printf("Implementa las operaciones basicas de un arreglo unidimensional\n");

	do
	{
		printf("\nOperaciones Arreglo Bidimensional\n");
		printf("1.......Insertar\n");
		printf("2.......Eliminar\n");
		printf("3.......Visualizar\n");
		// printf("4.......Ordenar\n");
		printf("5.......Modificar\n");
		printf("0.......Salir\n Elige una Opcion\n");
		scanf("%d", &opc);

		switch (opc)
		{
			case 1:
				printf("En que columna va a trabajar?:_ ");
				scanf("%d", &Limit_Max.CambioDeColumna);
				while ((getchar()) != '\n'); // lee y descarta los caracteres adicionales
				if (InsertarDesordenado(e, s, Limit_Max.CambioDeColumna) == true)
					printf("Los elementos se insertaron correctamente\n");
				else
					printf("El elemento No se insert%c\a\n", 162);
				break;

			case 2:
				printf("\nDame el elemento a eliminar ");
				scanf("%d", &Limit_Max.CambioDeColumna);
				while ((getchar()) != '\n'); // lee y descarta los caracteres adicionales
				/*if (Remove(s, Limit_Max.CambioDeColumna) == 1)
					printf("El elemento se elimin%c correctamente\n", 162);
				else
					printf("El elemento No se elimin%c \a\n", 162);*/
				break;

			case 3:
				imprimir(e, s);
				break;

			case 0:
				break;

			/*case 4:
				Ordenar(s);
				break;

			case 5:
				Modificar(s);
				break;*/
		}
	} while (opc != 0);
}

