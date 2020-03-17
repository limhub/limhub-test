#include <gtk/gtk.h>

void
debug_gtk_version()
{
  guint version_1 = gtk_get_major_version();
  guint version_2 = gtk_get_minor_version();
  guint version_3 = gtk_get_micro_version();
  g_print("gtk version  %d %d %d\n", version_1, version_2, version_3);
}

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  GtkWidget* window;
  GtkWidget* box;
  GtkWidget* entry;
  GtkWidget* scrolled_window;
  GtkWidget* text_view;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "GTK 3  input test");
  gtk_window_set_default_size(GTK_WINDOW(window), 720, 450);

  box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
  gtk_container_add(GTK_CONTAINER(window), box);

  entry = gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);

  scrolled_window = gtk_scrolled_window_new(NULL, NULL);
  gtk_box_pack_start(GTK_BOX(box), scrolled_window, TRUE, TRUE, 0);

  text_view = gtk_text_view_new();
  gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);

  gtk_widget_show_all(window);

  g_print("DEBUG  init ok\n");
}

int
main(int    argc,
     char** argv)
{
  GtkApplication* app;
  int status;

  debug_gtk_version();

  app = gtk_application_new("org.sceext.gtk3_input_test", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
