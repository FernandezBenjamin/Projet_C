
#include <stdlib.h>
#include <gtk/gtk.h>
#include <stdio.h>

GtkWidget *signScreen(GtkWidget *window);
void on_activate_entry(GtkWidget *pEntry, gpointer data);
void on_copier_button(GtkWidget *pButton, gpointer data);




GtkWidget *signInScreen(GtkWidget *window){
    GtkWidget *pVBox;
    GtkWidget *pHBox;
    GtkWidget *pButton[5];
    GtkWidget *pseudo;
    GtkWidget *password;
    GtkWidget *pseudoLabel;
    GtkWidget *passwordLabel;
    GtkWidget *switcher;
    GtkWidget *connectionStack;
    GtkWidget *signupStack;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Les GtkBox");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 700);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);


    /* Creation des label pour GtkEntry */
    pseudoLabel = gtk_label_new("Pseudo :");
    passwordLabel = gtk_label_new("Mot de passe :");


    /* Creation du GtkEntry */
    pseudo = gtk_entry_new();
    password = gtk_entry_new();


    /* Mode mot de passe */
    gtk_entry_set_visibility(GTK_ENTRY(password), FALSE);

    /* Modification du caractere affiche */
    gtk_entry_set_invisible_char(GTK_ENTRY(password), '*');


    gtk_entry_set_placeholder_text  (pseudo,"Pseudo");
    gtk_entry_set_placeholder_text  (password,"Mot de Passe");


    /* Cr�ation de la GtkBox verticale */
    pVBox = gtk_vbox_new(TRUE, 0);
    /* Ajout de la GtkVBox dans la fenetre */
    gtk_container_add(GTK_CONTAINER(window), pVBox);



    /* Ajout des GtkEntries et des labels */
    // PSEUDO
    gtk_box_pack_start(GTK_BOX(pVBox),pseudoLabel,TRUE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(pVBox),pseudo,TRUE,TRUE,0);


    // PASSWORD
    gtk_box_pack_start(GTK_BOX(pVBox),passwordLabel,TRUE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(pVBox),password,TRUE,TRUE,0);





    /* Creation des boutons */
    pButton[0] = gtk_button_new_with_label("Connexion");
    pButton[1] = gtk_button_new_with_label("S'inscrire");
    pButton[2] = gtk_button_new_from_stock(GTK_STOCK_QUIT);
    g_signal_connect(G_OBJECT(pButton[2]), "clicked", G_CALLBACK(gtk_main_quit), NULL);


    /* Cr�ation de la box horizontale */
    pHBox = gtk_hbox_new(TRUE, 0);

    /* Ajout de la GtkHBox dans la GtkVBox */
    gtk_box_pack_start(GTK_BOX(pVBox), pHBox, TRUE, TRUE, 0);
    /* Ajout de Bouton 1 et 2 dans la GtkVBox */
    gtk_box_pack_start(GTK_BOX(pHBox), pButton[0], TRUE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(pHBox), pButton[1], TRUE, TRUE, 0);



    /* Ajout des boutons 3 dans la GtkHBox */
    gtk_box_pack_start(GTK_BOX(pVBox), pButton[2], TRUE, TRUE, 0);





    return window;
}




void signUpScreen(GtkWidget *window){
    GtkWidget *pVBox;
    GtkWidget *pHBox;
    GtkWidget *pButton[5];
    GtkWidget *pseudo;
    GtkWidget *password;
    GtkWidget *pseudoLabel;
    GtkWidget *passwordLabel;
    GtkWidget *switcher;
    GtkWidget *connectionStack;
    GtkWidget *signupStack;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Les GtkBox");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 700);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);


    /* Creation des label pour GtkEntry */
    pseudoLabel = gtk_label_new("Pseudo :");
    passwordLabel = gtk_label_new("Mot de passe :");


    /* Creation du GtkEntry */
    pseudo = gtk_entry_new();
    password = gtk_entry_new();


    /* Mode mot de passe */
    gtk_entry_set_visibility(GTK_ENTRY(password), FALSE);

    /* Modification du caractere affiche */
    gtk_entry_set_invisible_char(GTK_ENTRY(password), '*');


    gtk_entry_set_placeholder_text  (pseudo,"Pseudo");
    gtk_entry_set_placeholder_text  (password,"Mot de Passe");


    /* Cr�ation de la GtkBox verticale */
    pVBox = gtk_vbox_new(TRUE, 0);
    /* Ajout de la GtkVBox dans la fenetre */
    gtk_container_add(GTK_CONTAINER(window), pVBox);



    /* Ajout des GtkEntries et des labels */
    // PSEUDO
    gtk_box_pack_start(GTK_BOX(pVBox),pseudoLabel,TRUE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(pVBox),pseudo,TRUE,TRUE,0);


    // PASSWORD
    gtk_box_pack_start(GTK_BOX(pVBox),passwordLabel,TRUE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(pVBox),password,TRUE,TRUE,0);





    /* Creation des boutons */
    pButton[0] = gtk_button_new_with_label("Connexion");
    pButton[1] = gtk_button_new_with_label("S'inscrire");
    pButton[2] = gtk_button_new_from_stock(GTK_STOCK_QUIT);
    g_signal_connect(G_OBJECT(pButton[2]), "clicked", G_CALLBACK(gtk_main_quit), NULL);


    /* Cr�ation de la box horizontale */
    pHBox = gtk_hbox_new(TRUE, 0);

    /* Ajout de la GtkHBox dans la GtkVBox */
    gtk_box_pack_start(GTK_BOX(pVBox), pHBox, TRUE, TRUE, 0);
    /* Ajout de Bouton 1 et 2 dans la GtkVBox */
    gtk_box_pack_start(GTK_BOX(pHBox), pButton[0], TRUE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(pHBox), pButton[1], TRUE, TRUE, 0);



    /* Ajout des boutons 3 dans la GtkHBox */
    gtk_box_pack_start(GTK_BOX(pVBox), pButton[2], TRUE, TRUE, 0);





    gtk_widget_show_all(window);
}







/* Fonction callback execute lors du signal "activate" */
void onActivateEntrySignIn(GtkWidget *pEntry, gpointer data)
{
    const gchar *sText;

    /* Recuperation du texte contenu dans le GtkEntry */
    sText = gtk_entry_get_text(GTK_ENTRY(pEntry));

    /* Modification du texte contenu dans le GtkLabel */
    gtk_label_set_text(GTK_LABEL((GtkWidget*)data), sText);
}








void on_copier_button(GtkWidget *pButton, gpointer data)
{
    GtkWidget *pTempEntry;
    GtkWidget *pTempLabel;
    GList *pList;
    const gchar *sText;

    /* Recuperation de la liste des elements que contient la GtkVBox */
    pList = gtk_container_get_children(GTK_CONTAINER((GtkWidget*)data));

    /* Le premier element est le GtkEntry */
    pTempEntry = GTK_WIDGET(pList->data);

    /* Passage a l element suivant : le GtkButton */
    pList = g_list_next(pList);

    /* Passage a l element suivant : le GtkLabel */
    pList = g_list_next(pList);

    /* Cet element est le GtkLabel */
    pTempLabel = GTK_WIDGET(pList->data);

    /* Recuperation du texte contenu dans le GtkEntry */
    sText = gtk_entry_get_text(GTK_ENTRY(pTempEntry));

    /* Modification du texte contenu dans le GtkLabel */
    gtk_label_set_text(GTK_LABEL(pTempLabel), sText);

    /* Liberation de la memoire utilisee par la liste */
    g_list_free(pList);
}







int main(int argc, char **argv)
{
    GtkWidget *pWindow;

    gtk_init(&argc,&argv);

    pWindow = signInScreen(pWindow);





    gtk_widget_show_all(pWindow);

    gtk_main();

    return EXIT_SUCCESS;
}