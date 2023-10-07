#include <gtk/gtk.h>

static void app_activate (GApplication *app, gpointer *data) {
    g_print("application activated");
}

int main(int argc, char** argv){
    GtkApplication *app;
    int stat;

    app = gtk_application_new("com.github.walter.pr1", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(app_activate), NULL);

    stat = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return stat;
}
