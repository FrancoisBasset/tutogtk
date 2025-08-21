#include <gtk/gtk.h>
#include "data.h"

void on_number_clicked(GtkWidget *button) {
    const char *txt = gtk_button_get_label(GTK_BUTTON(button));

	strcat(word, txt);
	g_print("\033[2J\033[H");
    g_print("Le mot: %s\n", word);
}