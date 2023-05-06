#include "TDAListaDoblementeEnlazada.h"
#include <gtk/gtk.h>

GtkBuilder *builder;
GtkWidget *VentanaPrincial, *IntroducirTexto, *Insertar_Elemento, *Eliminar_Elemento, *Error_Action;
GtkEntry *entry1;
GtkLabel *label1;

void Boton_Crear_Arreglo(GtkButton *button, gpointer user_data)
{
    gtk_widget_hide(VentanaPrincial); // Esconder la ventana1
}

void Boton_Push(GtkButton *button, gpointer user_data)
{
    gtk_widget_hide(VentanaPrincial); // Esconder la ventana1
}

void Boton_pop(GtkButton *button, gpointer user_data)
{
    gtk_widget_hide(VentanaPrincial); // Esconder la ventana1
}

void Boton_Print(GtkButton *button, gpointer user_data)
{
    gtk_widget_hide(VentanaPrincial); // Esconder la ventana1
}

void load_glade_file()
{

    GError *error = NULL;

    builder = gtk_builder_new();

    if (gtk_builder_add_from_file(builder, "/home/antho/Documentos/Proyectos Glade/TDAPilaEstatica.glade", &error) == 0)
    {
        g_printerr("Error loading file: %s\n", error->message);
        g_clear_error(&error);
        exit(EXIT_FAILURE);
    }
}

void on_window_destroy()
{
    // Salir de la aplicación cuando se cierra la ventana
    gtk_main_quit();
}

int ventana(int argc, char *argv[])
{

    gtk_init(&argc, &argv);
    

    load_glade_file();

    // Obtener elementos de la ventana1
    VentanaPrincial = GTK_WIDGET(gtk_builder_get_object(builder, "Ventana_Principal"));
    GtkButton *button1 = GTK_BUTTON(gtk_builder_get_object(builder, "Boton_Crear_Arreglo"));
    GtkButton *button2 = GTK_BUTTON(gtk_builder_get_object(builder, "Boton_Push"));
    GtkButton *button3 = GTK_BUTTON(gtk_builder_get_object(builder, "Boton_pop"));
    GtkButton *button4 = GTK_BUTTON(gtk_builder_get_object(builder, "Boton_Print"));

    // Conectar señales de la ventana1
    g_signal_connect(VentanaPrincial, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(button1, "clicked", G_CALLBACK(Boton_Crear_Arreglo), NULL);
    g_signal_connect(button2, "clicked", G_CALLBACK(Boton_Push), NULL);
    g_signal_connect(button3, "clicked", G_CALLBACK(Boton_pop), NULL);
    g_signal_connect(button4, "clicked", G_CALLBACK(Boton_Print), NULL);

    // Mostrar ventana1 y esconder ventana2
    gtk_widget_show_all(VentanaPrincial);

    gtk_main();

    return 0;
}
