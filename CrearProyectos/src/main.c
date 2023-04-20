#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

void directorio(void);
void crearMakeFile(void);
int cambiar_directorio_materia();
int cambiar_directorio_laboratorio();
void cambiar_directorio();
void eliminarArchivo();
char *obtener_directorio_actual();

short int eliminar = 0;
char *directorio_actual;

int main(void)
{
    obtener_directorio_actual();

    do
    {

        short int option = 0;
        char nombre[100];
        char direccion[100];

        system("clear");
        cambiar_directorio();

        printf("\nCambiado al directorio %s\n", direccion);
        getchar();
        eliminar = 1;

        do
        {
            system("clear");
            printf("Bienvenido, ¿Qué es lo que vas a hacer?\n");
            printf("[ 1 ] Materia\n");
            printf("[ 2 ] Laboratorio\n");
            printf("[ 3 ] Cambiar direcctorio\n");
            printf(":_ ");
            fflush(stdin);
            scanf("%hd", &option);

            if (option != 1 && option != 2 && option != 3)
                printf("No es una opción valida.\n");

        } while (option != 1 && option != 2 && option != 3);

        switch (option)
        {
        case 1:

            if (cambiar_directorio_materia() != 0)
            {
                printf("Ha ocurrido un error al cambiar al directorio Materia\n");
                return 1;
            }

            {
                printf("\n¿Cuál será el nombre del proyecto?:_");
                fflush(stdin);
                while ((getchar()) != '\n')
                    ; // limpia el buffer de entrada
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = 0;

                if (mkdir(nombre, 0777) != 0)
                {
                    printf("Error al crear el directorio.\n");
                    return 1;
                }

                printf("El directorio '%s' se ha creado exitosamente.\n", nombre);

                if (chdir(nombre) != 0)
                {
                    printf("Error al cambiar al directorio '%s'.\n", nombre);
                    return 1;
                }

                printf("Cambiado al directorio '%s'.\n", nombre);

                directorio();
                crearMakeFile();

                if (chdir("src") != 0)
                {
                    printf("Error al cambiar al directorio");
                    return 1;
                }

                printf("Cambiado al directorio src");

                FILE *principal = fopen("main.c", "w");
                if (principal == NULL)
                {
                    printf("Error al abrir el archivo principal.\n");
                    return 1;
                }
                fclose(principal);

                printf("\n");
                printf("--------------------------------------\n");
                chdir("..");
                system("ls");
                printf("--------------------------------------\n");
                chdir("..");
                system("ls");
                printf("--------------------------------------\n");
                printf("\nPresione enter para cerrar el programa...");
                getchar();
                if (chdir(directorio_actual) != 0)
                {
                    printf("Error al cambiar al directorio\n");
                    return 1;
                }
                printf("Cambiado al directorio %s\n", directorio_actual);
                break;
            }

        case 2:

            if (cambiar_directorio_laboratorio() != 0)
            {
                printf("Ha ocurrido un error al cambiar al directorio Materia\n");
                return 1;
            }

            printf("\n¿Cuál será el nombre del proyecto?:_");
            fflush(stdin);
            while ((getchar()) != '\n')
                ; // limpia el buffer de entrada
            fgets(nombre, sizeof(nombre), stdin);
            nombre[strcspn(nombre, "\n")] = 0;

            if (mkdir(nombre, 0777) != 0)
            {
                printf("Error al crear el directorio.\n");
                return 1;
            }

            printf("El directorio '%s' se ha creado exitosamente.\n", nombre);

            if (chdir(nombre) != 0)
            {
                printf("Error al cambiar al directorio '%s'.\n", nombre);
                return 1;
            }

            printf("Cambiado al directorio '%s'.\n", nombre);

            directorio();
            crearMakeFile();

            if (chdir("src") != 0)
            {
                printf("Error al cambiar al directorio");
                return 1;
            }

            printf("Cambiado al directorio src");

            FILE *principal = fopen("main.c", "w");
            if (principal == NULL)
            {
                printf("Error al abrir el archivo principal.\n");
                return 1;
            }
            fclose(principal);

            printf("\n");
            printf("--------------------------------------\n");
            chdir("..");
            system("ls");
            printf("--------------------------------------\n");
            chdir("..");
            system("ls");
            printf("--------------------------------------\n");
            printf("\nPresione enter para cerrar el programa...");
            getchar();
            if (chdir(directorio_actual) != 0)
            {
                printf("Error al cambiar al directorio\n");
                return 1;
            }
            printf("Cambiado al directorio %s\n", directorio_actual);

            break;

        case 3:

            eliminarArchivo("directorio.txt");
            eliminar = 0;

            break;

        default:

            printf("No se ha seleccionado una opción valida");
            break;

            return 0;
        }

    } while (eliminar != 1);
}
void directorio(void)
{
    mkdir("src", 0777);
    mkdir("bin", 0777);
    mkdir("lib", 0777);
    mkdir("output", 0777);
    mkdir("include", 0777);
}
void crearMakeFile()
{

    FILE *archivo;
    archivo = fopen("Makefile", "w");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo Makefile.\n");
        return;
    }

    fputs("#\n", archivo);
    fputs("# 'make'        build executable file 'main'\n", archivo);
    fputs("# 'make clean'  removes all .o and executable files\n", archivo);
    fputs("#\n", archivo);
    fputs("\n", archivo);
    fputs("# define the C compiler to use\n", archivo);
    fputs("CC = gcc\n", archivo);
    fputs("\n", archivo);
    fputs("# define any compile-time flags\n", archivo);
    fputs("CFLAGS\t:= -Wall -Wextra -g `pkg-config --cflags gtk+-3.0`\n", archivo);
    fputs("\n", archivo);
    fputs("# define library paths in addition to /usr/lib\n", archivo);
    fputs("#   if I wanted to include libraries not in /usr/lib I'd specify\n", archivo);
    fputs("#   their path using -Lpath, something like:\n", archivo);
    fputs("LFLAGS =\n", archivo);
    fputs("\n", archivo);
    fputs("# define output directory\n", archivo);
    fputs("OUTPUT\t:= output\n", archivo);
    fputs("\n", archivo);
    fputs("# define source directory\n", archivo);
    fputs("SRC\t\t:= src\n", archivo);
    fputs("\n", archivo);
    fputs("# define include directory\n", archivo);
    fputs("INCLUDE\t:= include\n", archivo);
    fputs("\n", archivo);
    fputs("# define lib directory\n", archivo);
    fputs("LIB\t:= lib\n", archivo);
    fputs("\n", archivo);
    fputs("ifeq ($(OS),Windows_NT)\n", archivo);
    fputs("MAIN\t:= main.exe\n", archivo);
    fputs("SOURCEDIRS\t:= $(SRC)\n", archivo);
    fputs("INCLUDEDIRS\t:= $(INCLUDE)\n", archivo);
    fputs("LIBDIRS\t\t:= $(LIB)\n", archivo);
    fputs("FIXPATH = $(subst /,\\,$1)\n", archivo);
    fputs("RM\t\t:= del /q /f\n", archivo);
    fputs("MD\t:= mkdir\n", archivo);
    fputs("else\n", archivo);
    fputs("MAIN\t:= main\n", archivo);
    fputs("SOURCEDIRS\t:= $(shell find $(SRC) -type d)\n", archivo);
    fputs("INCLUDEDIRS\t:= $(shell find $(INCLUDE) -type d)\n", archivo);
    fputs("LIBDIRS\t\t:= $(shell find $(LIB) -type d)\n", archivo);
    fputs("FIXPATH = $1\n", archivo);
    fputs("RM = rm -f\n", archivo);
    fputs("MD\t:= mkdir -p\n", archivo);
    fputs("endif\n", archivo);
    fputs("\n", archivo);
    fputs("# define any directories containing header files other than /usr/include\n", archivo);
    fputs("INCLUDES\t:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))\n", archivo);
    fputs("\n", archivo);
    fputs("# define the C libs\n", archivo);
    fputs("LIBS\t\t:= $(patsubst %,-L%, $(LIBDIRS:%/=%)) `pkg-config --libs gtk+-3.0`\n", archivo);
    fputs("\n", archivo);
    fputs("# define the C source files\n", archivo);
    fputs("SOURCES\t\t:= $(wildcard $(patsubst %,%/*.c, $(SOURCEDIRS)))\n", archivo);
    fputs("\n", archivo);
    fputs("# define the C object files \n", archivo);
    fputs("OBJECTS\t\t:= $(SOURCES:.c=.o)\n", archivo);
    fputs("\n", archivo);
    fputs("# define the dependency output files\n", archivo);
    fputs("DEPS\t\t:= $(OBJECTS:.o=.d)\n", archivo);
    fputs("\n", archivo);
    fputs("#\n", archivo);
    fputs("# The following part of the makefile is generic; it can be used to \n", archivo);
    fputs("# build any executable just by changing the definitions above and by\n", archivo);
    fputs("# deleting dependencies appended to the file from 'make depend'\n", archivo);
    fputs("#\n", archivo);
    fputs("\n", archivo);
    fputs("OUTPUTMAIN\t:= $(call FIXPATH,$(OUTPUT)/$(MAIN))\n", archivo);
    fputs("\n", archivo);
    fputs("all: $(OUTPUT) $(MAIN)\n", archivo);
    fputs("\t@echo Executing 'all' complete!\n", archivo);
    fputs("\n", archivo);
    fputs("$(OUTPUT):\n", archivo);
    fputs("\t$(MD) $(OUTPUT)\n", archivo);
    fputs("\n", archivo);
    fputs("$(MAIN): $(OBJECTS) \n", archivo);
    fputs("\t$(CC) $(CFLAGS) $(INCLUDES) -o $(OUTPUTMAIN) $(OBJECTS) $(LFLAGS) $(LIBS)\n", archivo);
    fputs("\n", archivo);
    fputs("# include all .d files\n", archivo);
    fputs("-include $(DEPS)\n", archivo);
    fputs("\n", archivo);
    fputs("# this is a suffix replacement rule for building .o's and .d's from .c's\n", archivo);
    fputs("# it uses automatic variables $<: the name of the prerequisite of\n", archivo);
    fputs("# the rule(a .c file) and $@: the name of the target of the rule (a .o file) \n", archivo);
    fputs("# -MMD generates dependency output files same name as the .o file\n", archivo);
    fputs("# (see the gnu make manual section about automatic variables)\n", archivo);
    fputs(".c.o:\n", archivo);
    fputs("\t$(CC) $(CFLAGS) $(INCLUDES) -c -MMD $<  -o $@\n", archivo);
    fputs("\n", archivo);
    fputs(".PHONY: clean\n", archivo);
    fputs("clean:\n", archivo);
    fputs("\t$(RM) $(OUTPUTMAIN)\n", archivo);
    fputs("\t$(RM) $(call FIXPATH,$(OBJECTS))\n", archivo);
    fputs("\t$(RM) $(call FIXPATH,$(DEPS))\n", archivo);
    fputs("\t@echo Cleanup complete!\n", archivo);
    fputs("\n", archivo);
    fputs("run: all\n", archivo);
    fputs("\t./$(OUTPUTMAIN)\n", archivo);
    fputs("\t@echo Executing 'run: all' complete!\n", archivo);

    fclose(archivo);
}

int cambiar_directorio_materia()
{
    char *directorio = "Materia ";
    struct stat st = {0};

    // Verificar si la carpeta ya existe
    if (stat(directorio, &st) == 0)
    {
        printf("Se ha encontrado la carpeta %s\n", directorio);
        printf("Entrando al directorio...\n");
    }
    else
    {
        printf("No se ha encontrado la carpeta %s\n", directorio);
        printf("Desea crear la carpeta %s? (y/n): ", directorio);
        char respuesta;
        scanf(" %c", &respuesta);

        if (respuesta == 'y' || respuesta == 'Y')
        {
            // Crear la carpeta
            if (mkdir(directorio, 0777) != 0)
            {
                printf("Error al crear la carpeta\n");
                return 1;
            }
            printf("La carpeta %s ha sido creada exitosamente\n", directorio);
        }
        else
        {
            // Salir de la función
            printf("Saliendo de la función...\n");
            return 0;
        }
    }

    // Cambiar al directorio
    if (chdir(directorio) != 0)
    {
        printf("Error al cambiar al directorio\n");
        return 1;
    }
    printf("Cambiado al directorio %s\n", directorio);

    return 0;
}

int cambiar_directorio_laboratorio()
{
    char *directorio = "Laboratorio ";
    struct stat st = {0};

    // Verificar si la carpeta ya existe
    if (stat(directorio, &st) == 0)
    {
        printf("Se ha encontrado la carpeta %s\n", directorio);
        printf("Entrando al directorio...\n");
    }
    else
    {
        printf("No se ha encontrado la carpeta %s\n", directorio);
        printf("Desea crear la carpeta %s? (y/n): ", directorio);
        char respuesta;
        scanf(" %c", &respuesta);

        if (respuesta == 'y' || respuesta == 'Y')
        {
            // Crear la carpeta
            if (mkdir(directorio, 0777) != 0)
            {
                printf("Error al crear la carpeta\n");
                return 1;
            }
            printf("La carpeta %s ha sido creada exitosamente\n", directorio);
        }
        else
        {
            // Salir de la función
            printf("Saliendo de la función...\n");
            return 0;
        }
    }

    // Cambiar al directorio
    if (chdir(directorio) != 0)
    {
        printf("Error al cambiar al directorio\n");
        cambiar_directorio();
        return 1;
    }
    printf("Cambiado al directorio %s\n", directorio);

    return 0;
}

void cambiar_directorio()
{
    printf("presiona (enter) para continuar");
    getchar();
    char direccion[100];
    FILE *archivo = fopen("directorio.txt", "r");
    if (archivo == NULL)
    { // El archivo no existe, se pide al usuario la dirección
        printf("\n¿En qué directorio vas a trabajar?: ");
        fgets(direccion, sizeof(direccion), stdin);
        direccion[strcspn(direccion, "\n")] = 0;

        archivo = fopen("directorio.txt", "w"); // Se crea el archivo

        if (archivo == NULL)
        { // Error al crear el archivo
            printf("Error al crear el archivo directorio.txt\n");
            exit(1);
        }

        if (chdir(direccion) != 0)
        { // Se cambia al directorio
            printf("Error al cambiar al directorio\n");
            exit(1);
        }
        printf("\nCambiado al directorio %s\n", direccion);
        fprintf(archivo, "%s", direccion); // Se guarda la dirección en el archivo
        fclose(archivo);
    }
    else
    { // El archivo existe, se lee la dirección
        fgets(direccion, sizeof(direccion), archivo);
        direccion[strcspn(direccion, "\n")] = 0;
        fclose(archivo);

        if (access("directorio.txt", F_OK) == 0)
        { // El archivo existe, se lee la dirección
            archivo = fopen("directorio.txt", "r");
            if (archivo == NULL)
            {
                printf("Error al abrir el archivo directorio.txt\n");
                exit(1);
            }
            fgets(direccion, sizeof(direccion), archivo);
            direccion[strcspn(direccion, "\n")] = 0;
            fclose(archivo);
        }
        else
        { // El archivo no existe, se pide al usuario la dirección
            printf("\n¿En qué directorio vas a trabajar?: ");
            fflush(stdin);
            fgets(direccion, sizeof(direccion), stdin);
            direccion[strcspn(direccion, "\n")] = 0;

            archivo = fopen("directorio.txt", "w"); // Se abre el archivo en modo escritura
            if (archivo == NULL)
            {
                printf("Error al abrir el archivo directorio.txt\n");
                exit(1);
            }
            fprintf(archivo, "%s", direccion); // Se guarda la dirección en el archivo
            fclose(archivo);
        }

            if (chdir(direccion) != 0)
            {
                printf("Error al cambiar al directorio\n");

            }
            printf("Cambiado al directorio %s\n", direccion);
    }
}

void eliminarArchivo()
{
    char confirmacion;
    printf("¿Está seguro de que desea eliminar el archivo 'directorio.txt'? (s/n): ");
    scanf(" %c", &confirmacion);
    if (confirmacion == 's' || confirmacion == 'S')
    {
        FILE *archivo = fopen("directorio.txt", "r");
        if (archivo == NULL)
        {
            printf("Error al abrir el archivo.\n");
            exit(1);
        }
        fclose(archivo);
        int resultado = remove("directorio.txt");
        if (resultado == 0)
        {
            printf("El archivo se ha eliminado correctamente.\n");
        }
        else
        {
            printf("Error al eliminar el archivo.\n");
        }
    }
    else
    {
        printf("El archivo no se ha eliminado.\n");
    }
}

char *obtener_directorio_actual()
{
    directorio_actual = malloc(sizeof(char) * 1024); // reserva espacio para el nombre del directorio
    getcwd(directorio_actual, 1024);                 // obtiene el directorio actual y lo guarda en la variable
    return directorio_actual;                        // devuelve la variable
}
