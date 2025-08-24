#include <gtk/gtk.h>
#include "data.h"

void concat_word(GtkButton* button) {
    const char *txt = gtk_button_get_label(GTK_BUTTON(button));

	strcat(word, txt);
}

void on_number_clicked_to_entry(GtkButton* button, GtkEntry* entry) {
    concat_word(button);
	
    gtk_entry_buffer_set_text(gtk_entry_get_buffer(entry), word, (int) strlen(word));
}

void on_number_clicked_to_label(GtkButton* button, GtkLabel* label) {
    concat_word(button);
	
    gtk_label_set_text(label, word);
}



void on_text_changed(GtkEntry *entry, GtkLabel* label) {
    const char* text = gtk_entry_buffer_get_text(gtk_entry_get_buffer(entry));

    strcpy(word, text);

    gtk_label_set_text(label, word);
}