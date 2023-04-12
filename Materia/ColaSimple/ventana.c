#include <gtk/gtk.h>
#include "ventana.h"
#include "VentanaEmergenteBox.h"


// función que llama a on_button_emergente_clicked con dos textos adicionales

int ventana(int argc, char *argv[]) {
    // Inicialización de GTK
    gtk_init(&argc, &argv);

    // Creación de la ventana principal
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Estructura De Datos tipo Cola");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 400, 300);

    // Creación de los widgets
    GtkWidget *label = gtk_label_new("Seleccione una opción");
    GtkWidget *button1 = gtk_button_new_with_label("Crear Estructura");
    GtkWidget *button2 = gtk_button_new_with_label("Insertar Elemento");
    GtkWidget *button3 = gtk_button_new_with_label("Eliminar Elemento");
    GtkWidget *button4 = gtk_button_new_with_label("Mostrar arreglo");

    // Conexión de las señales
    g_signal_connect(button1, "clicked", G_CALLBACK(on_button1_clicked), label);
    g_signal_connect(button2, "clicked", G_CALLBACK(on_button2_clicked), label);
    g_signal_connect(button3, "clicked", G_CALLBACK(on_button3_clicked), label);
    g_signal_connect(button4, "clicked", G_CALLBACK(on_button4_clicked), label);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Añadir los widgets a la ventana
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), button1, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), button2, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), button3, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), button4, TRUE, TRUE, 0);

    // Mostrar la ventana y ejecutar el bucle principal de GTK
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

// Implementación de las funciones de los botones

void on_button1_clicked(GtkWidget *widget, gpointer data) {
    GtkLabel *label = GTK_LABEL(data);
    gtk_label_set_text(label, "Has presionado el Botón 1");
    mi_funcion(widget, data);
}

void on_button2_clicked(GtkWidget *widget, gpointer data) {
    GtkLabel *label = GTK_LABEL(data);
    gtk_label_set_text(label, "Has presionado el Botón 2");
    mi_funcion(widget, data);
}

void on_button3_clicked(GtkWidget *widget, gpointer data) {
    GtkLabel *label = GTK_LABEL(data);
    gtk_label_set_text(label, "Has presionado el Botón 3");
    mi_funcion(widget, data);
}


void on_button_emergente_clicked(GtkWidget *widget, gpointer data) {
    const gchar *dialog_title = "Ingresar elementos";
    const gchar *label_text = "Dame el tamaño del elemento:";
    gchar *text = show_dialog_with_entry(GTK_WINDOW(widget), dialog_title, label_text);

    if (text != NULL) {
        elementSize = atoi(text);
        g_free(text);
        // TODO: Agregar el elemento a la cola
    }
}

void on_button_emergente_clicked_Button02(GtkWidget *widget, gpointer data) {
    const gchar *dialog_title = "Ingresar elementos";
    const gchar *label_text = "Dame el elemento a Insertar:";
    gchar *text = show_dialog_with_entry(GTK_WINDOW(widget), dialog_title, label_text);

    if (text != NULL) {
        gchar *element = g_strdup(text);
        g_free(text);
        // Aquí puedes hacer lo que quieras con la variable "element"
    }
}

void on_button_emergente_clicked_Button03(GtkWidget *widget, gpointer data) {
    const gchar *dialog_title = "Ingresar elementos";
    const gchar *label_text = "Dame el elemento a Eliminar:";
    gchar *text = show_dialog_with_entry(GTK_WINDOW(widget), dialog_title, label_text);

    if (text != NULL) {
        gchar *element = g_strdup(text);
        g_free(text);
        // Aquí puedes hacer lo que quieras con la variable "element"
    }
}
