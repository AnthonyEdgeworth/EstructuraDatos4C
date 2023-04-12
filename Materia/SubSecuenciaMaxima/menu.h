#ifndef MENU
#define MENU

// Aquí va el código que deseas incluir solo una vez




#include <stdio.h>
#include <stdlib.h>


int Bienvenida() {
    FILE *fp;
    char output[1024];

printf("************************************************************************************ \n");


    /* Open the command for reading. */
    fp = popen("whoami", "r");
    if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
    }

    /* Read the output */
    if (fgets(output, sizeof(output), fp) != NULL) {
        printf("Bienvenido: %s", output);
    }

    /* close */
    pclose(fp);

    return 0;
}

#endif
