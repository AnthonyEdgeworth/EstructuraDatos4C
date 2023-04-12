//Eduardo Antonio Figueroa Salas

/*La función strrev() se utiliza para invertir la cadena de caracteres que representa la notación 
para calcular el resultado en notación posfija y prefija. Sin embargo, esta función no está 
disponible en todas las implementaciones de C y puede no ser portable entre plataformas.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 50

int es_prefija(char simbolo);
int es_posfija(char simbolo);

int main()
{
    char notacion[tam];
    printf("\nIngrese la notacion: ");
    fgets(notacion, tam, stdin);
    
    // Verificar el tipo de notación
    if(es_posfija(notacion[0]))
    {
        printf("La expresion que se inserto esta en notacion posfija.\n");
    }
    else if(es_prefija(notacion[0]))
    {
        printf("La expresion que se inserto esta en notacion prefija.\n");
    }
    else
    {
        printf("La expresion que se inserto esta en notacion infija.\n");
    }
    
    // Calcular el resultado de la expresion en infija, posfija y prefija
    char* token = strtok(notacion, " ");
    int operando1, operando2, resultado;
    while(token != NULL)
    {
        if(*token >= '0' && *token <= '9')
        {
            // Es un operando
            if(operando1 == 0)
            {
                operando1 = atoi(token);
            }
            else
            {
                operando2 = atoi(token);
            }
        }
        else
        {
            // Es un operador
            switch(*token)
            {
                case '+':
                    resultado = operando1 + operando2;
                    break;
                case '-':
                    resultado = operando1 - operando2;
                    break;
                case '*':
                    resultado = operando1 * operando2;
                    break;
                case '/':
                    resultado = operando1 / operando2;
                    break;
                case '^':
                    resultado = operando1 ^ operando2;
                    break;
            }
            
            // Guardar el resultado y resetear los operandos
            operando1 = resultado;
            operando2 = 0;
        }
        
        token = strtok(NULL, " ");
    }
    
    printf("El resultado en infija es: %d\n", resultado);
    
    // Invertir la notacion para calcular el resultado en posfija
    strrev(notacion);
    token = strtok(notacion, " ");
    operando1 = 0;
    operando2 = 0;
    while(token != NULL)
    {
        if(*token >= '0' && *token <= '9')
        {
            // Es un operando
            if(operando1 == 0)
            {
                operando1 = atoi(token);
            }
            else
            {
                operando2 = atoi(token);
            }
        }
        else
        {
            // Es un operador
            switch(*token)
            {
                case '+':
                    resultado = operando1 + operando2;
                    break;
                case '-':
                    resultado = operando1 - operando2;
                    break;
                case '*':
                    resultado = operando1 * operando2;
                    break;
                case '/':
                    resultado = operando1 / operando2;
                    break;
                case '^':
                    resultado = operando1 ^ operando2;
                    break;
            }
            
            // Guardar el resultado y resetear los operandos
            operando1 = resultado;
            operando2 = 0;
        }
        
        token = strtok(NULL, " ");
    }
    
    printf("El resultado en posfija es: %d\n", resultado);
    // Invertir la notacion para calcular el resultado en prefija
    strrev(notacion);
    token = strtok(notacion, " ");
    operando1 = 0;
    operando2 = 0;
    while(token != NULL)
    {
        if(*token >= '0' && *token <= '9')
        {
            // Es un operando
            if(operando2 == 0)
            {
                operando2 = atoi(token);
            }
            else if(operando1 == 0)
            {
                operando1 = atoi(token);
            }
        }
        else
        {
            // Es un operador
            switch(*token)
            {
                case '+':
                    resultado = operando1 + operando2;
                    break;
                case '-':
                    resultado = operando1 - operando2;
                    break;
                case '*':
                    resultado = operando1 * operando2;
                    break;
                case '/':
                    resultado = operando1 / operando2;
                    break;
                case '^':
                    resultado = operando1 ^ operando2;
                    break;
            }
            
            // Guardar el resultado y resetear los operandos
            operando2 = resultado;
            operando1 = 0;
        }
        
        token = strtok(NULL, " ");
    }
    
    printf("El resultado en prefija es: %d\n", resultado);
    
    return 0;
}

int es_prefija(char simbolo)
{
    if(simbolo == '+' || simbolo == '-' || simbolo == '*' || simbolo == '/' || simbolo == '^')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int es_posfija(char simbolo)
{
    if(simbolo >= '0' && simbolo <= '9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}