/* EQUIPO:
           Victor Manuel Castillo Lujan
           Mariana Estefania Barcenas Rodriguez    
*/
//  FECHA: 11/03/2022

#include <stdio.h>
#include <math.h>
#define tam 20
 
void MostrarMatriz(int matriz[][tam], int orden);
int determinante(int matriz[][tam], int orden);
int cofactor(int matriz[][tam], int orden, int fila, int columna);
 
int main()
{
   int matriz[tam][tam];
   int orden, i, j;
   
   printf("Ingresa el orden de la matriz: ");
   scanf("%d", &orden);
   
   printf("\nIngrese los elementos de la matriz:\n\n");
   for (i = 0; i < orden; i++) {
      for (j = 0; j < orden; j++) {
         scanf("%d", &matriz[i][j]);
      }
   }
 
   printf("\nMostrando la matriz ingresada:");
   MostrarMatriz(matriz, orden);
   
   printf("\nEl determinante es: %d\n", determinante(matriz, orden));
 
   getchar();
   getchar();
   return 0;
}
 
void MostrarMatriz(int matriz[][tam], int orden)
{
	int i, j;
	
	printf("Orden: %d\n", orden);
   for (i = 0; i < orden; i++) {
      for (j = 0; j < orden; j++) {
      	printf("\t  %d ", matriz[i][j]);
      }
      printf("\n");
   }
}
 
 
int determinante(int matriz[][tam], int orden)
{
   int det = 0.0, j;
   
   if (orden == 1) {
      det = matriz[0][0];
   } else {
      for (j = 0; j < orden; j++) {
         det = det + matriz[0][j] * cofactor(matriz, orden, 0, j);
      }
   }
   
   return det;
}
 
 
int cofactor(int matriz[][tam], int orden, int fila, int columna)
{
   int submatriz[tam][tam];
   int n = orden - 1;
   int i, j;
   
   int x = 0;
   int y = 0;
   for (i = 0; i < orden; i++) {
      for (j = 0; j < orden; j++) {
         if (i != fila && j != columna) {
            submatriz[x][y] = matriz[i][j];
            y++;
            if (y >= n) {
               x++;
               y = 0;
            }
         }
      }
   }
   
   return pow(-1.0, fila + columna) * determinante(submatriz, n);
}
