#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define NULO '\0'

bool Vacia();
void ObtenerSubcadena(char cadena[], char Subcadena[], int inicio, int ndeletras);
int ndeletras;
char subcadena[50];
void muestra(char cadena[]);
char cadena[100];
int inicio;


int main(int argc, char *argv[]) {
	int opcion;
	int opc;
	int intentar=true;
	while(intentar==true){
		printf("Que desea realizar?\n");
		printf("1.Leer una cadena\n");
		printf("2.Sacar una subcadena\n");
		printf("3.Mostrar cada letra y mostrarlo con su direccion de memoria\n");
		do{
			scanf("%d",&opcion);
		}while(opcion<1 || opcion>3);
		switch(opcion){
			case 1:
				printf("Ingrese su cadena\n");
				scanf("%s",cadena);
				printf("Su cadena es;\n");
				puts(cadena);
				break;
			case 2:
			    if(Vacia()==true){
					printf("La cadena esta vacia, por favor ingrese una cadena\n");
					scanf("%s",cadena);
				}else{
					printf("Coloque posicion de inicio\n");
					scanf("%d",&inicio);
					printf("Coloque el numero de letras\n");
					scanf("%d",&ndeletras);
					ObtenerSubcadena(subcadena,cadena,inicio,ndeletras);
					printf("La subcadena es:\n");
					puts(subcadena);
				}
				break;
			default:
				printf("Elegir que se quiere mostrar en pantalla\n");
				printf("1. Cadena\n");
				printf("2.Subcadena\n");
					do{
						scanf("%d",&opc);
					}while(opc<1 || opc>2);
					switch(opc){
						case 1:
							if(Vacia(cadena)==true){
								printf("La cadena esta vacia, por favor ingrese una cadena\n");
								scanf("%s",cadena);
							}else{
							printf("Su cadena es;\n");
							puts(cadena);
							printf("Su visualizacion es:\n");
							muestra(cadena);
							}
							break;
						default:
							if(Vacia(subcadena)==true){
								printf("La subcadena esta vacia, por favor regrese y elija la opcion 2\n");
							}else{
							printf("Su subcadena es:\n");
							puts(subcadena);
							printf("Su visualizacion es:\n");					
							muestra(subcadena);
							}
							break;
					}
		}
		int opcion2;
		printf("Desea intentar otra cosa?\n");
		printf("1 Si\n");
		printf("2 No\n");
		do{
			scanf("%d",&opcion2);
		}while(opcion2<1 || opcion2>2);
		if(opcion2==2){
			intentar=false;
		}else
		   system("cls");	
	}
	system("pause");
	return 0;
}
bool Vacia(char cadena[]){
	if(cadena[0] == '\0'){
		return true;
	}
	if(cadena[0] != '\0'){
		return false;
	}
}
void muestra(char cadena[]){
	printf("Posicion\tCaracter\tDireccion\n");
	int i=0;
	for(i=0;cadena[i]!=NULO;i++){
		printf("%d%c%p\n",i,cadena[i],&cadena[i]);
	}
}	
void ObtenerSubcadena(char Subcadena[], char cadena[], int inicio, int ndeletras){
	int i,j;
	j=0;
	for(i=inicio;j<ndeletras;i++){
		Subcadena[j]=cadena[i];
		j++;
	}
	Subcadena[j]='\0';
}	