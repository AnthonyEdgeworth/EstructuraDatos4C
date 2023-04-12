#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NINO 1 

struct registro{
	int  REG;
	char Nombre [30];
	char CURP[30];
	char NPOT[30];
	char Escuela [30];
	double promedio;
};


int main(int argc, char *argv[]) {
	
	int i=0;
	FILE *archivo;
	struct registro registros[NINO];
	archivo=fopen("registros.txt","w");
	
	while(i<NINO)
	
	{
		registros[i].REG=i+1;
		
		printf("Nombre del Nino :\n");
		fgets(registros[i].Nombre,30,stdin);
		
		printf("la CURP del Nino :\n");
		fgets(registros[i].CURP,30,stdin);
		
		printf("Nombre del pardre o tutor del Nino  %d:\n");
		fgets(registros[i].NPOT,30,stdin);
		
		printf("Nombre de la Escuela Anterior del Nino  :\n");
		fgets(registros[i].Escuela,30,stdin);
		
		printf("El  Promedio del Nino  %d:\n");
		scanf("%lf",&registros[i].promedio);
		fflush(stdin); 
		
		fprintf(archivo,"Numero de estudiante: %d\nNombre del estudiante: %sCURP: %sNombre del Padre o Tutor: %sNombre de la institucion anterior: %sPromedio anterior: %.4lf\n\n",
		registros[i].REG, registros[i].Nombre, registros[i].CURP, registros[i].NPOT, registros[i].Escuela, registros[i].promedio);
		i++;
	}
	
	fclose(archivo);
	system("pause");
	return 0;
}