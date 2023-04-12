#include <stdio.h>
#include <stdlib.h>
#define tam 50

int prioridad(char simbolo);


    

int main()
{
    char notacion[tam];
   // int notacion;
    printf("\n ingrese la notacion: ");
    gets(notacion);
    
    
    
    if((notacion=='+' && notacion=='-' && notacion=='*' && notacion=='/' && notacion=='+' && notacion=='^') )  
      printf("\n es prefija");
    else if(((notacion>='a')&&(notacion<='z') || (notacion>='A')&&(notacion<='Z')) ) 
      printf("\n es posfija");
    else 
      printf("\n es posfija");
    return 0;
}

