#ifndef VENTANAEMERGENTEBOX_H
#define VENTANAEMERGENTEBOX_H

#include <gtk/gtk.h>

// TODO:Declaraciones Globales
int valorQueRegresa = 0;

// TODO: Declaración de la función
gchar *show_dialog_with_entry(GtkWidget *parent_widget, const gchar *dialog_title, const gchar *label_text);
void on_button_emergente_clicked(GtkWidget *widget, gpointer data, const gchar *label_text2, const gchar *label_text3);

// TODO: Implementación de la función
gchar *show_dialog_with_entry(GtkWidget *parent_widget, const gchar *dialog_title, const gchar *label_text)
{
    GtkWidget *dialog;
    GtkWidget *content_area;
    GtkWidget *accept_button;
    GtkWidget *hbox;
    GtkWidget *label;
    GtkWidget *entry;

    GtkWindow *parent_window = NULL;

    if (GTK_IS_WINDOW(parent_widget))
    {
        parent_window = GTK_WINDOW(parent_widget);
    }
    else
    {
        parent_window = GTK_WINDOW(gtk_widget_get_toplevel(parent_widget));
    }

    // Creación del diálogo emergente
    dialog = gtk_dialog_new_with_buttons(dialog_title, parent_window,
                                         GTK_DIALOG_MODAL,
                                         "_Cancel", GTK_RESPONSE_CANCEL,
                                         "_OK", GTK_RESPONSE_OK, NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    // Creación del hbox y su etiqueta
    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    label = gtk_label_new(label_text);

    gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);

    // Creación de la entrada de texto para el elemento
    entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), entry, TRUE, TRUE, 0);

    // Agregamos el hbox al diálogo
    gtk_container_add(GTK_CONTAINER(content_area), hbox);
    gtk_widget_show_all(dialog);

    gint response = gtk_dialog_run(GTK_DIALOG(dialog));
    gchar *text = NULL;

    if (response == GTK_RESPONSE_ACCEPT)
    {
        text = g_strdup(gtk_entry_get_text(GTK_ENTRY(entry)));
    }

    gtk_widget_destroy(dialog);

    return text;
}

// TODO: Implemtentación de la función:

void on_button_emergente_clicked(GtkWidget *widget, gpointer data, const gchar *label_text2, const gchar *label_text3)
{
    GtkWindow *parent_window = NULL;

    if (GTK_IS_WINDOW(widget))
    {
        parent_window = GTK_WINDOW(widget);
    }
    else
    {
        parent_window = GTK_WINDOW(gtk_widget_get_toplevel(widget));
    }

    gchar *text = show_dialog_with_entry(GTK_WIDGET(parent_window), label_text2, label_text3);

    if (text != NULL)
    {
        valorQueRegresa = atoi(text);
        g_free(text);
        // TODO: Agregar el elemento a la cola
    }
}

// TODO: Ejemplo de Uso:

/*#include "ventanaEmergenteBox.h"

// función que llama a on_button_emergente_clicked con dos textos adicionales
void mi_funcion(GtkWidget *widget, gpointer data) {
    const gchar *label_text2 = "Texto 2";
    const gchar *label_text3 = "Texto 3";
    on_button_emergente_clicked(widget, data, label_text2, label_text3);
}
*/

#endif