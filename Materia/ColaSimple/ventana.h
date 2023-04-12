#ifndef MAIN_H
#define MAIN_H

#include <gtk/gtk.h>

// Funciones de los botones
void on_button1_clicked(GtkWidget *widget, gpointer data);
void on_button2_clicked(GtkWidget *widget, gpointer data);
void on_button3_clicked(GtkWidget *widget, gpointer data);
void on_button4_clicked(GtkWidget *widget, gpointer data);

// Ventanas emergentes con posibilidad de introducir texto
void on_button_emergente_clicked_Button02(GtkWidget *widget, gpointer data);
void on_button_emergente_clicked_Button03(GtkWidget *widget, gpointer data);
gchar *show_dialog_with_entry(GtkWidget *parent_window, const gchar *dialog_title, const gchar *label_text);

// Variables globales
int elementSize = 0;
int ValorButton02 = 0;
int ValorButton03 = 0;
GtkWidget *popup;

//Ventana Principal
int ventana(int argc, char *argv[]);
#endif