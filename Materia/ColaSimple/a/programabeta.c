/*#include <gtk/gtk.h>
#include "TDAColaSencila.h"


//-------------------------------------------------------------------------------
//! IMPLEMENTACIÓN DE LAS FUNCIONES DE LOS BOTONES
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
//! IMPLEMENTACIÓN DE LAS VARIABLES GLOBALES
int elementSize=0;
int ValorButton02 = 0;
int ValorButton03 = 0;



//-------------------------------------------------------------------------------
int value;

// Declaración de funciones
void on_button1_clicked(GtkWidget *widget, gpointer data);
void on_button2_clicked(GtkWidget *widget, gpointer data);
void on_button3_clicked(GtkWidget *widget, gpointer data);
void on_button4_clicked(GtkWidget *widget, gpointer data);

//ventanas emergentes Con Posibilidad de introducir Texto
void on_button_emergente_clicked(GtkWidget *widget, gpointer data);
void on_button_emergente_clicked_Button02(GtkWidget *widget, gpointer data);
void on_button_emergente_clicked_Button03(GtkWidget *widget, gpointer data);


// CREACIÓN DE LA VARIABLE GLOBAL PARA PODER ACCEDER A LA CAJA DEL TEXTO
GtkWidget *popup;

int main(int argc, char *argv[]) {
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


//-------------------------------------------------------------------------------
//! IMPLEMENTACIÓN DE LAS FUNCIONES DE LOS BOTONES
//-------------------------------------------------------------------------------

// Implementación de las funciones de los botones

void on_button1_clicked(GtkWidget *widget, gpointer data) {
    gtk_label_set_text(GTK_LABEL(data), "Has presionado el Botón 1");
    on_button_emergente_clicked(widget, data);
}

void on_button2_clicked(GtkWidget *widget, gpointer data) {
    gtk_label_set_text(GTK_LABEL(data), "Has presionado el Botón 2");
    on_button_emergente_clicked_Button02(widget, data);
}

void on_button3_clicked(GtkWidget *widget, gpointer data) {
    gtk_label_set_text(GTK_LABEL(data), "Has presionado el Botón 3");
    on_button_emergente_clicked_Button03(widget, data);
}

void on_button4_clicked(GtkWidget *widget, gpointer data) {
    gtk_label_set_text(GTK_LABEL(data), "Has presionado el Botón 4");
}

void on_button_emergente_clicked(GtkWidget *widget, gpointer data) {
GtkWidget *dialog;
GtkWidget *content_area;
GtkWidget *accept_button;
GtkWidget *hbox;
GtkWidget *label;
// Creación del diálogo emergente
dialog = gtk_dialog_new_with_buttons("Ingresar elementos", GTK_WINDOW(gtk_widget_get_toplevel(widget)),
                                    GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
                                    "Cancelar", GTK_RESPONSE_CANCEL, "Aceptar", GTK_RESPONSE_ACCEPT, NULL);

content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

// Creación del hbox y su etiqueta
hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
label = gtk_label_new("Dame el tamaño del elemento:");

gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);

// Creación de la entrada de texto para el elemento
GtkWidget *entry = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(hbox), entry, TRUE, TRUE, 0);

// Agregamos el hbox al diálogo
gtk_container_add(GTK_CONTAINER(content_area), hbox);
gtk_widget_show_all(dialog);

gint result = gtk_dialog_run(GTK_DIALOG(dialog));

// Si se presionó el botón de Aceptar
if (result == GTK_RESPONSE_ACCEPT) {
    // Obtenemos el texto ingresado en la entrada de texto
    gchar *text = gtk_entry_get_text(GTK_ENTRY(entry));
    // Convertimos el texto a entero
    elementSize = atoi(text);

    // TODO: Agregar el elemento a la cola
}

// Destruimos el diálogo
gtk_widget_destroy(dialog);
}

void on_button_emergente_clicked_Button02(GtkWidget *widget, gpointer data){
GtkWidget *dialog;
GtkWidget *content_area;
GtkWidget *accept_button;
GtkWidget *hbox;
GtkWidget *label;
// Creación del diálogo emergente
dialog = gtk_dialog_new_with_buttons("Ingresar elementos", GTK_WINDOW(gtk_widget_get_toplevel(widget)),
                                    GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
                                    "Cancelar", GTK_RESPONSE_CANCEL, "Aceptar", GTK_RESPONSE_ACCEPT, NULL);

content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

// Creación del hbox y su etiqueta
hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
label = gtk_label_new("Dame el elemento a Insertar:");

gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);

// Creación de la entrada de texto para el elemento
GtkWidget *entry = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(hbox), entry, TRUE, TRUE, 0);

// Agregamos el hbox al diálogo
gtk_container_add(GTK_CONTAINER(content_area), hbox);
gtk_widget_show_all(dialog);

gint result = gtk_dialog_run(GTK_DIALOG(dialog));

// Si se presionó el botón de Aceptar
if (result == GTK_RESPONSE_ACCEPT) {
    // Obtenemos el texto ingresado en la entrada de texto
    gchar *text = gtk_entry_get_text(GTK_ENTRY(entry));
    // Convertimos el texto a entero
    ValorButton02 = atoi(text);

    // TODO: Agregar el elemento a la cola
}

// Destruimos el diálogo
gtk_widget_destroy(dialog);
}

void on_button_emergente_clicked_Button03(GtkWidget *widget, gpointer data){
GtkWidget *dialog;
GtkWidget *content_area;
GtkWidget *accept_button;
GtkWidget *hbox;
GtkWidget *label;
// Creación del diálogo emergente
dialog = gtk_dialog_new_with_buttons("Ingresar elementos", GTK_WINDOW(gtk_widget_get_toplevel(widget)),
                                    GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
                                    "Cancelar", GTK_RESPONSE_CANCEL, "Aceptar", GTK_RESPONSE_ACCEPT, NULL);

content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

// Creación del hbox y su etiqueta
hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
label = gtk_label_new("Dame el elemento a Eliminar:");

gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);

// Creación de la entrada de texto para el elemento
GtkWidget *entry = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(hbox), entry, TRUE, TRUE, 0);

// Agregamos el hbox al diálogo
gtk_container_add(GTK_CONTAINER(content_area), hbox);
gtk_widget_show_all(dialog);

gint result = gtk_dialog_run(GTK_DIALOG(dialog));

// Si se presionó el botón de Aceptar
if (result == GTK_RESPONSE_ACCEPT) {
    // Obtenemos el texto ingresado en la entrada de texto
    gchar *text = gtk_entry_get_text(GTK_ENTRY(entry));
    // Convertimos el texto a entero
    ValorButton03 = atoi(text);

    // TODO: Agregar el elemento a la cola
}

// Destruimos el diálogo
gtk_widget_destroy(dialog);
}


*/
