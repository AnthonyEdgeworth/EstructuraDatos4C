//MARIANA ESTEFANIA BARCENAS RODRIGUEZ
//ESTRUCTURA DE DATOS
//11 FEBRERO 2022
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
#include "InterSumaSubsecMax.h"

int sumarLineal(int *d);

int Suma_sub_Max=0;
int n;
clock_t tm_inicial, tm_final,Tfinal;
int main(){
	leer();
	Suma_sub_Max=sumarLineal(a);
	imprimir(a);
	
	getch();
	return 0;
}
void leer()
{ 
		printf ("Dame el numero de elementos: \n");
		scanf("%d",&n);
		printf("Dame la secuencia de los numeros: \n");
		for (int i=0;i<n;i++){
			printf("Numero %d",i,",");
			scanf("%d",&a[i]);
		}
        /*
        FILE *fp;
    int *cadena;
    if( (fp=fopen("numero.txt","r")) !=NULL)
    {
       

        do
        {
            fgets(cadena, 10, fp);//fgets
            printf("%s",cadena);
        }while(!feof(fp));
        
        fclose(fp);
    }
    else
       printf("\n Error al leer el archivo");

		*/
}
		
int sumarLineal(int *d)
{ 
	tm_inicial = clock();
	int sumaMax=0; 
	int SumaActual=0;		
	for (int i=0, j=0; i<n ;j++)
    {
			SumaActual+=d[j];
			if(SumaActual>sumaMax){
				sumaMax=SumaActual;
				secIni=i;
				secFin=j;
			}
			else if (SumaActual<0)
      {
				i=j+1;
				SumaActual=0;
			}
		}
	tm_final=clock();
	Tfinal = (tm_final-tm_inicial)*1000 / CLOCKS_PER_SEC;
	return sumaMax;
}

void imprimir (int *b){
			printf("La subsecuencia maxima es: ");
			for (int i=secIni; i<=secFin; i++){ 
				printf("%d, ",b[i]);
			}
			printf("\n La suma maxima es %d: ",Suma_sub_Max);
			printf("\n El tiempo inicial y final de ejecucion es: %lf, %lf",(double)tm_inicial, (double)tm_final);
			printf("\n El tiempo final es: %lf\n", (double)(Tfinal));
	}