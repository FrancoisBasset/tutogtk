#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "utils.h"
#include "events.h"

char* sentence;
Data data;

void on_close() {
	free(sentence);
	free(data.firstname);
	free(word);
}

void activate(GtkApplication *app, gpointer args) {
	data = *(Data*) args;

	sentence = getSentence(data.firstname);
	word = malloc(sizeof(char) * 100);
	strcpy(word, "");

    GtkBuilder* builder = gtk_builder_new_from_resource("/org/francoisbasset/app/main.ui");
    GtkWindow* window = GTK_WINDOW(gtk_builder_get_object(builder, "window"));

    gtk_window_set_application(window, app);
    gtk_window_set_title(window, sentence);
    gtk_window_set_default_size(window, 600, 300);

    gtk_window_present(window);

    g_object_unref(builder);
}

int main(int argc, char **argv) {
	data = getData(argc, argv);

	GtkApplication *app = gtk_application_new("org.francoisbasset.example", 0);
	
	g_signal_connect(app, "activate", G_CALLBACK(activate), &data);

	const int status = g_application_run(G_APPLICATION(app), 0, NULL);

	g_object_unref(app);
	on_close();

	return status;
}
