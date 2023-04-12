#ifndef VENTANA_BASICA_H
#define VENTANA_BASICA_H

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>


// Declaración de funciones para los botones

void on_button1_clicked(GtkWidget *widget, gpointer data);
void on_button2_clicked(GtkWidget *widget, gpointer data);
void on_button3_clicked(GtkWidget *widget, gpointer data); 

// Implementación de la ventana basica
int ventanConVentanas(int argc, char *argv[],const gchar *label_text1,const gchar *label_text2,const gchar *label_text3);

int ventanConVentanas(int argc, char *argv[],const gchar *label_text1,const gchar *label_text2,const gchar *label_text3) {
    // Inicialización de GTK
    gtk_init(&argc, &argv);

    // Creación de la ventana principal
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Mi aplicación GTK");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 400, 300);

    // Creación de los widgets
    GtkWidget *label = gtk_label_new("Presiona un botón");
    GtkWidget *button1 = gtk_button_new_with_label(label_text1);
    GtkWidget *button2 = gtk_button_new_with_label(label_text2);
    GtkWidget *button3 = gtk_button_new_with_label(label_text3); // Se crea el nuevo botón

    // Conexión de las señales
    g_signal_connect(button1, "clicked", G_CALLBACK(on_button1_clicked), label);
    g_signal_connect(button2, "clicked", G_CALLBACK(on_button2_clicked), label);
    g_signal_connect(button3, "clicked", G_CALLBACK(on_button3_clicked), label); // Se conecta la señal del nuevo botón
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Añadir los widgets a la ventana
    GtkWidget *vbox = gtk_vbox_new(FALSE, 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), button1, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), button2, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), button3, TRUE, TRUE, 0); // Se añade el nuevo botón a la caja vertical

    // Mostrar la ventana y ejecutar el bucle principal de GTK
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

// Implementación de las funciones de los botones 
//! A MODIFICACIÓN DEL USUARIO ESTOS DEBERÍAN DE ESTAR IMPLEMENTADOS DENTRO DEL .C (Solo son de prueba)

void on_button1_clicked(GtkWidget *widget, gpointer data) {
    gtk_label_set_text(GTK_LABEL(data), "Has presionado el Botón 1");
}

void on_button2_clicked(GtkWidget *widget, gpointer data) {
    gtk_label_set_text(GTK_LABEL(data), "Has presionado el Botón 2");
}

void on_button3_clicked(GtkWidget *widget, gpointer data) { // Se implementa la función del nuevo botón
    gtk_label_set_text(GTK_LABEL(data), "Has presionado el Botón 3");
}


/* Ejemplo de uso 

int main(int argc, char *argv[]) {
    ventanConVentanas(argc, argv, "Botón 1", "Botón 2", "Botón 3");
    return 0;
}


*/

#endif