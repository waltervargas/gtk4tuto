#include <gtk/gtk.h>

static void
close_cb (GtkButton *btn, GtkWindow* win) {
    g_print("Clicked.\n");
    gtk_window_destroy(win);
}

static void
btn2_cb (GtkButton *btn) {
    const char *s;
    s = gtk_button_get_label(btn);
    if (g_strcmp0(s,"Hello.") == 0)
        gtk_button_set_label(btn, "good-bye.");
    else
        gtk_button_set_label(btn, "Hello.");

}

static void
app_activate (GApplication *app) {

    GtkWidget* win;
    win = gtk_application_window_new(GTK_APPLICATION(app));
    gtk_window_set_title(GTK_WINDOW(win), "gtk4tuto");
    gtk_window_set_default_size(GTK_WINDOW(win), 300, 200);

    // there can be only one child for a given window
    // to have more than one widget we need to use a container widget
    // for example GtkBox
    GtkWidget* box;
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_set_homogeneous(GTK_BOX(box), TRUE);
    gtk_window_set_child(GTK_WINDOW(win), box);

    GtkWidget* lab;
    lab = gtk_label_new("Hello barrbara");
    gtk_box_append(GTK_BOX(box), lab);

    GtkWidget* btn;
    btn = gtk_button_new_with_label("Close");
    g_signal_connect(btn, "clicked", G_CALLBACK(close_cb), win);
    gtk_box_append(GTK_BOX(box), btn);

    GtkWidget* btn2;
    btn2 = gtk_button_new_with_label("Clickme");
    g_signal_connect(btn2, "clicked", G_CALLBACK(btn2_cb), NULL);
    gtk_box_append(GTK_BOX(box), btn2);

    // show the window
    gtk_window_present(GTK_WINDOW(win));
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
