
#include <stdlib.h>
#include <gtk/gtk.h>
#include <stdio.h>



void signScreen(GtkWidget *window){
    GtkWidget *pVBox;
    GtkWidget *pHBox;
    GtkWidget *pButton[5];

    pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(pWindow), "Les GtkBox");
    gtk_window_set_default_size(GTK_WINDOW(pWindow), 700, 500);
    g_signal_connect(G_OBJECT(pWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la GtkBox verticale */
    pVBox = gtk_vbox_new(TRUE, 0);
    /* Ajout de la GtkVBox dans la fenetre */
    gtk_container_add(GTK_CONTAINER(pWindow), pVBox);

    /* Creation des boutons */
    pButton[0] = gtk_button_new_with_label("Connexion");
    pButton[1] = gtk_button_new_with_label("S'inscrire");
    pButton[2] = gtk_button_new_from_stock(GTK_STOCK_QUIT);
    g_signal_connect(G_OBJECT(pButton[2]), "clicked", G_CALLBACK(gtk_main_quit), NULL);


    /* Création de la box horizontale */
    pHBox = gtk_hbox_new(TRUE, 0);

    /* Ajout de la GtkHBox dans la GtkVBox */
    gtk_box_pack_start(GTK_BOX(pVBox), pHBox, TRUE, TRUE, 0);
    /* Ajout de Bouton 1 et 2 dans la GtkVBox */
    gtk_box_pack_start(GTK_BOX(pHBox), pButton[0], TRUE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(pHBox), pButton[1], TRUE, TRUE, 0);



    /* Ajout des boutons 3 dans la GtkHBox */
    gtk_box_pack_start(GTK_BOX(pVBox), pButton[2], TRUE, TRUE, 0);



}
