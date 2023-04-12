#ifndef VENTANA_H
#define VENTANA_H

#include <gtk/gtk.h>
#include "TADBidimensional.h"

GtkWidget *window;
GtkWidget *grid;
GtkWidget *label_titulo;
GtkWidget *label_dimensiones;
GtkWidget *entry_filas;
GtkWidget *entry_columnas;
GtkWidget *label_resultado;
GtkWidget *scrolled_window;
GtkWidget *table;
GtkWidget *button_crear;
GtkWidget *button_buscar;
GtkWidget *button_modificar;
GtkWidget *button_eliminar;
GtkWidget *button_ordenar;
GtkWidget *button_imprimir;

void MostrarMenu();
void Crear(GtkWidget *widget, gpointer data);
void Buscar(GtkWidget *widget, gpointer data);
void Modificar(GtkWidget *widget, gpointer data);
void Eliminar(GtkWidget *widget, gpointer data);
void Ordenar(GtkWidget *widget, gpointer data);
void Imprimir(GtkWidget *widget, gpointer data);
void LlenarTabla();

#endif /* VENTANA_H */
