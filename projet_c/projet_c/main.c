
#include <stdlib.h>
#include <gtk/gtk.h>
#include <stdio.h>


GtkWidget *signInScreen(GtkWidget *window);
GtkWidget *signUpScreen();
void on_activate_entry(GtkWidget *pEntry, gpointer data);
void on_copier_button(GtkWidget *pButton, gpointer data);




GtkWidget *signInScreen(GtkWidget *window){
    GtkWidget *pVBox;
    GtkWidget *pHBox;
    GtkWidget *pButton[2];


    GtkWidget *pseudo;
    GtkWidget *password;


    GtkWidget *pseudoLabel;
    GtkWidget *passwordLabel;


    GtkWidget *signInContainer;
    GtkWidget *signUpContainer;

    GtkWidget *pNotebook;

    GtkWidget *labelSignUpPage;
    GtkWidget *labelSignInPage;


    gchar *labelSignUp = {"S'inscrire"};
    gchar *labelSignIn = {"Connexion"};





    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Les GtkBox");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 700);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);


    /* Création de la GtkBox verticale */
    pVBox = gtk_vbox_new(TRUE, 0);

    /* Creation du GtkNotebook */
    pNotebook = gtk_notebook_new();
    gtk_box_pack_start(GTK_BOX(pVBox), pNotebook, TRUE, TRUE, 0);
    /* Position des onglets : en bas */
    gtk_notebook_set_tab_pos(GTK_NOTEBOOK(pNotebook), GTK_POS_BOTTOM);
    /* Ajout des boutons de navigation */
    gtk_notebook_set_scrollable(GTK_NOTEBOOK(pNotebook), TRUE);


    /* Ajout du notebook dans la fenêtre */
    gtk_container_add(GTK_CONTAINER(window), pVBox);


    /* Creation des label le notebook */
    labelSignInPage = gtk_label_new(labelSignIn);
    labelSignUpPage = gtk_label_new(labelSignUp);


    signInContainer = gtk_event_box_new();
    signUpContainer = gtk_event_box_new();

    /* Création de la GtkBox verticale */
    pVBox = gtk_vbox_new(TRUE, 0);


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





    /* Ajout de la GtkVBox dans le container */
    gtk_container_add(GTK_CONTAINER(signInContainer), pVBox);



    /* Ajout des GtkEntries et des labels */
    // PSEUDO
    gtk_box_pack_start(GTK_BOX(pVBox),pseudoLabel,TRUE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(pVBox),pseudo,TRUE,TRUE,0);


    // PASSWORD
    gtk_box_pack_start(GTK_BOX(pVBox),passwordLabel,TRUE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(pVBox),password,TRUE,TRUE,0);





    /* Creation des boutons */
    pButton[0] = gtk_button_new_with_label("Connexion");
    pButton[1] = gtk_button_new_from_stock(GTK_STOCK_QUIT);
    g_signal_connect(G_OBJECT(pButton[1]), "clicked", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(pButton[0]), "clicked", G_CALLBACK(gtk_main_quit), pNotebook);





    /* Création de la box horizontale */
    pHBox = gtk_hbox_new(TRUE, 0);


    /* Ajout de Bouton 1 dans la GtkVBox */
    gtk_box_pack_start(GTK_BOX(pVBox), pButton[0], TRUE, TRUE, 0);


    /* Ajout des boutons 2 dans la GtkHBox */
    gtk_box_pack_start(GTK_BOX(pVBox), pButton[1], TRUE, TRUE, 0);



    /* Insertion de la page */
    gtk_notebook_append_page(GTK_NOTEBOOK(pNotebook), signInContainer, labelSignInPage);




    signUpContainer = signUpScreen();


    /* Insertion de la page */
    gtk_notebook_append_page(GTK_NOTEBOOK(pNotebook), signUpContainer, labelSignUpPage);



    return window;
}



/* Fonction de création d'inscription */
GtkWidget *signUpScreen(){
    GtkWidget *pVBox;
    GtkWidget *pHBox;
    GtkWidget *pButton[2];


    GtkWidget *pseudo;
    GtkWidget *password;
    GtkWidget *passwordConfirmation;


    GtkWidget *pseudoLabel;
    GtkWidget *passwordLabel;
    GtkWidget *passwordConfirmationLabel;


    GtkWidget *containerTab;

    GtkNotebook *pNotebook;

    gchar *buttonLabel = {"S'incrire"};



    containerTab = gtk_event_box_new();



    /* Création de la GtkBox verticale */
    pVBox = gtk_vbox_new(TRUE, 0);


    /* Creation des label pour GtkEntry */
    pseudoLabel = gtk_label_new("Pseudo :");
    passwordLabel = gtk_label_new("Mot de passe :");
    passwordConfirmationLabel = gtk_label_new("Confirmation du mot de passe :");


    /* Creation du GtkEntry */
    pseudo = gtk_entry_new();
    password = gtk_entry_new();
    passwordConfirmation = gtk_entry_new();


    /* Mode mot de passe */
    gtk_entry_set_visibility(GTK_ENTRY(password), FALSE);

    /* Modification du caractere affiche */
    gtk_entry_set_invisible_char(GTK_ENTRY(password), '*');


    /* Mode mot de passe */
    gtk_entry_set_visibility(GTK_ENTRY(passwordConfirmation), FALSE);

    /* Modification du caractere affiche */
    gtk_entry_set_invisible_char(GTK_ENTRY(passwordConfirmation), '*');


    gtk_entry_set_placeholder_text  (pseudo,"Pseudo");
    gtk_entry_set_placeholder_text  (password,"Mot de Passe");
    gtk_entry_set_placeholder_text  (passwordConfirmation,"Confirmation mot de Passe");



    /* Ajout de la GtkVBox dans la fenetre */
    gtk_container_add(GTK_CONTAINER(containerTab), pVBox);



    /* Ajout des GtkEntries et des labels */
    // PSEUDO
    gtk_box_pack_start(GTK_BOX(pVBox),pseudoLabel,TRUE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(pVBox),pseudo,TRUE,TRUE,0);


    // PASSWORD
    gtk_box_pack_start(GTK_BOX(pVBox),passwordLabel,TRUE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(pVBox),password,TRUE,TRUE,0);


    // PASSWORD CONFIRMATION
    gtk_box_pack_start(GTK_BOX(pVBox),passwordConfirmationLabel,TRUE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(pVBox),passwordConfirmation,TRUE,TRUE,0);





    /* Creation des boutons */
    pButton[0] = gtk_button_new_with_label(buttonLabel);
    pButton[1] = gtk_button_new_from_stock(GTK_STOCK_QUIT);
    g_signal_connect(G_OBJECT(pButton[1]), "clicked", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(pButton[0]), "clicked", G_CALLBACK(gtk_main_quit), pNotebook);




    /* Création de la box horizontale */
    pHBox = gtk_hbox_new(TRUE, 0);

    /* Ajout de la GtkHBox dans la GtkVBox */
    gtk_box_pack_start(GTK_BOX(pVBox), pHBox, TRUE, TRUE, 0);

    /* Ajout de Bouton 1 et 2 dans la GtkVBox */
    gtk_box_pack_start(GTK_BOX(pHBox), pButton[0], TRUE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(pHBox), pButton[1], TRUE, TRUE, 0);




    return containerTab;
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








void OnButton(GtkWidget *pButton, gpointer data)
{
    GtkWidget *pDialog;
    GtkWidget *pChild;
    gint iPageNum;
    const gchar *sLabel;
    const gchar *sTabLabel;
    gchar *sDialogText;

    /* Recuperation de la page active */
    iPageNum = gtk_notebook_get_current_page(GTK_NOTEBOOK(data));
    /* Recuperation du widget enfant */
    pChild = gtk_notebook_get_nth_page(GTK_NOTEBOOK(data), iPageNum);

    /* Recuperation du label */
    sLabel = gtk_label_get_text(GTK_LABEL(pChild));
    /* Recuperation du label de l'onglet */
    sTabLabel = gtk_notebook_get_tab_label_text(GTK_NOTEBOOK(data), pChild);

    /* Creation du label de la boite de dialogue */
    sDialogText = g_strdup_printf("C'est la page %d\n"
        "Le label est \"%s\"\n"
        "Le label de l'onglet est \"%s\"\n",
        iPageNum,
        sLabel,
        sTabLabel);

    pDialog = gtk_message_dialog_new(NULL,
        GTK_DIALOG_MODAL,
        GTK_MESSAGE_INFO,
        GTK_BUTTONS_OK,
        sDialogText);

    gtk_dialog_run(GTK_DIALOG(pDialog));

    gtk_widget_destroy(pDialog);

    g_free(sDialogText);
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
