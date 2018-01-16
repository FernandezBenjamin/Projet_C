#include <windows.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <winsock.h>
#include <mysql.h>



void signInScreen();
GtkWidget *signUpScreen();
void on_activate_entry(GtkWidget *pEntry, gpointer data);
void connectUser(GtkWidget *pButton, gpointer data);
void signUpUser(GtkWidget *pButton, gpointer data);
int checkUser(char *request);
void sqlInsert(char *request);
int userExist(char *request);
void principalScreen();
GtkWidget *activities();


GtkWidget *connectArray[2];
GtkWidget *signUpArray[11];
GtkWidget *styleImages[6];
GtkWidget *window;

int isConnected = 0;



void signInScreen(){
    GtkWidget *pVBox;
    GtkWidget *pHBox;
    GtkWidget *pButton[2];

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
    gtk_window_set_title(GTK_WINDOW(window), "Login");
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 800);
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
    connectArray[0] = gtk_entry_new();
    connectArray[1] = gtk_entry_new();


    /* Mode mot de passe */
    gtk_entry_set_visibility(GTK_ENTRY(connectArray[1]), FALSE);

    /* Modification du caractere affiche */
    gtk_entry_set_invisible_char(GTK_ENTRY(connectArray[1]), '*');


    gtk_entry_set_placeholder_text  (connectArray[0],"Pseudo");
    gtk_entry_set_placeholder_text  (connectArray[1],"Mot de Passe");





    /* Ajout de la GtkVBox dans le container */
    gtk_container_add(GTK_CONTAINER(signInContainer), pVBox);



    /* Ajout des GtkEntries et des labels */
    // PSEUDO
    gtk_box_pack_start(GTK_BOX(pVBox),pseudoLabel,TRUE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(pVBox),connectArray[0],TRUE,TRUE,0);


    // PASSWORD
    gtk_box_pack_start(GTK_BOX(pVBox),passwordLabel,TRUE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(pVBox),connectArray[1],TRUE,TRUE,0);





    /* Creation des boutons */
    pButton[0] = gtk_button_new_with_label("Connexion");
    pButton[1] = gtk_button_new_from_stock(GTK_STOCK_QUIT);
    g_signal_connect(G_OBJECT(pButton[1]), "clicked", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(pButton[0]), "clicked", G_CALLBACK(connectUser),(GtkWidget *)&connectArray);





    /* Création de la box horizontale */
    pHBox = gtk_hbox_new(TRUE, 0);


    /* Ajout de Bouton 1 dans la GtkVBox */
    gtk_box_pack_start(GTK_BOX(pVBox), pHBox, TRUE, TRUE, 0);

    /* Ajout de Bouton 1 dans la GtkVBox */
    gtk_box_pack_start(GTK_BOX(pHBox), pButton[0], TRUE, TRUE, 0);


    /* Ajout des boutons 2 dans la GtkHBox */
    gtk_box_pack_start(GTK_BOX(pHBox), pButton[1], TRUE, TRUE, 0);



    /* Insertion de la page */
    gtk_notebook_append_page(GTK_NOTEBOOK(pNotebook), signInContainer, labelSignInPage);




    signUpContainer = signUpScreen();


    /* Insertion de la page */
    gtk_notebook_append_page(GTK_NOTEBOOK(pNotebook), signUpContainer, labelSignUpPage);



    gtk_widget_show_all(window);
}



/* Fonction de création d'inscription */
GtkWidget *signUpScreen(){
    GtkWidget *pVBox;
    GtkWidget *pHBox;
    GtkWidget *pButton[2];


    GtkWidget *pseudoLabel;
    GtkWidget *passwordLabel;
    GtkWidget *passwordConfirmationLabel;
    GtkWidget *sizeLabel;
    GtkWidget *weightLabel;
    GtkWidget *birthLabel;
    GtkWidget *genderLabel;
    GtkWidget *styleLabel;


    GtkWidget *containerTab;

    GtkNotebook *pNotebook;


    gchar *buttonLabel = {"S'incrire"};

    int i;


    containerTab = gtk_event_box_new();



    /* Création de la GtkBox verticale */
    pVBox = gtk_vbox_new(TRUE, 0);


    /* Creation des label pour GtkEntry */
    pseudoLabel = gtk_label_new("Pseudo :");
    passwordLabel = gtk_label_new("Mot de passe (max 40 caracteres) :");
    passwordConfirmationLabel = gtk_label_new("Confirmation du mot de passe (max 40 caracteres) :");
    sizeLabel = gtk_label_new("Votre taille (en cm) :");
    birthLabel = gtk_label_new("Votre annee de naissance (YYYY) :");
    genderLabel = gtk_label_new("Sexe :");
    styleLabel = gtk_label_new("Votre style vestimentaire :");


    /* Creation du GtkEntry */
    signUpArray[0] = gtk_entry_new();
    signUpArray[1] = gtk_entry_new();
    signUpArray[2] = gtk_entry_new();
    signUpArray[3] = gtk_entry_new();
    signUpArray[4] = gtk_entry_new();


    /* Ajout du label dans la box */
    gtk_box_pack_start(GTK_BOX(pVBox), genderLabel, TRUE, TRUE, 0);


    /* Création de la box horizontale */
    pHBox = gtk_hbox_new(TRUE, 0);

    /* Ajout de la GtkHBox dans la GtkVBox */
    gtk_box_pack_start(GTK_BOX(pVBox), pHBox, TRUE, TRUE, 0);


    /* Création du premier bouton radio */
    signUpArray[5] = gtk_radio_button_new_with_label(NULL, "Mr");
    gtk_box_pack_start(GTK_BOX (pHBox), signUpArray[5], FALSE, FALSE, 0);

    /* Ajout du deuxieme */
    signUpArray[6] = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON (signUpArray[5]), "Mme");
    gtk_box_pack_start(GTK_BOX (pHBox), signUpArray[6], FALSE, FALSE, 0);

    /* Ajout du troisième */
    signUpArray[7] = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON (signUpArray[5]), "Mlle");
    gtk_box_pack_start(GTK_BOX (pHBox), signUpArray[7], FALSE, FALSE, 0);


    /* Mode mot de passe */
    gtk_entry_set_visibility(GTK_ENTRY(signUpArray[1]), FALSE);

    /* Modification du caractere affiche */
    gtk_entry_set_invisible_char(GTK_ENTRY(signUpArray[1]), '*');


    /* Mode mot de passe */
    gtk_entry_set_visibility(GTK_ENTRY(signUpArray[2]), FALSE);

    /* Modification du caractere affiche */
    gtk_entry_set_invisible_char(GTK_ENTRY(signUpArray[2]), '*');


    gtk_entry_set_placeholder_text  (signUpArray[0],"Pseudo");
    gtk_entry_set_placeholder_text  (signUpArray[1],"Mot de Passe");
    gtk_entry_set_placeholder_text  (signUpArray[2],"Confirmation mot de Passe");
    gtk_entry_set_placeholder_text  (signUpArray[3],"Votre annee de naissance");
    gtk_entry_set_placeholder_text  (signUpArray[4],"Votre taille");



    gtk_entry_set_max_length  (signUpArray[0],100);
    gtk_entry_set_max_length  (signUpArray[1],40);
    gtk_entry_set_max_length  (signUpArray[2],40);
    gtk_entry_set_max_length  (signUpArray[3],4);
    gtk_entry_set_max_length  (signUpArray[4],3);


    /* Chargement d'une image a partir d'un fichier */
    styleImages[0] = gtk_image_new_from_file("sport.png");
    styleImages[1] = gtk_image_new_from_file("casual.png");
    styleImages[2] = gtk_image_new_from_file("dandy.png");


    /* Création des radiobox des images */
    signUpArray[8] = gtk_radio_button_new_with_label(NULL, "Sport");
    signUpArray[9] = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON (signUpArray[8]), "Casual");
    signUpArray[10] = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON (signUpArray[8]), "Dandy");





    /* Ajout de la GtkVBox dans la fenetre */
    gtk_container_add(GTK_CONTAINER(containerTab), pVBox);



    /* Ajout des GtkEntries et des labels */
    // PSEUDO
    gtk_box_pack_start(GTK_BOX(pVBox),pseudoLabel,TRUE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(pVBox),signUpArray[0],TRUE,TRUE,0);


    // PASSWORD
    gtk_box_pack_start(GTK_BOX(pVBox),passwordLabel,TRUE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(pVBox),signUpArray[1],TRUE,TRUE,0);


    // PASSWORD CONFIRMATION
    gtk_box_pack_start(GTK_BOX(pVBox),passwordConfirmationLabel,TRUE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(pVBox),signUpArray[2],TRUE,TRUE,0);

    // BIRTH DATE
    gtk_box_pack_start(GTK_BOX(pVBox),birthLabel,TRUE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(pVBox),signUpArray[3],TRUE,TRUE,0);


    // SIZE
    gtk_box_pack_start(GTK_BOX(pVBox),sizeLabel,TRUE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(pVBox),signUpArray[4],TRUE,TRUE,0);

    // STYLE
    gtk_box_pack_start(GTK_BOX(pVBox),styleLabel,TRUE,FALSE,0);


    /* Création de la box horizontale */
    pHBox = gtk_hbox_new(TRUE, 0);

    /* Ajout de la GtkHBox dans la GtkVBox */
    gtk_box_pack_start(GTK_BOX(pVBox), pHBox, TRUE, TRUE, 0);



    for (i = 0; i < 3; i++){
        // IMAGES
        gtk_box_pack_start(GTK_BOX(pHBox), styleImages[i], FALSE, FALSE, 5);
    }

    /* Création de la box horizontale */
    pHBox = gtk_hbox_new(TRUE, 0);

    /* Ajout de la GtkHBox dans la GtkVBox */
    gtk_box_pack_start(GTK_BOX(pVBox), pHBox, TRUE, TRUE, 0);

    for (i = 0; i < 3; i++){
        // IMAGES
        gtk_box_pack_start(GTK_BOX(pHBox), signUpArray[8+i], FALSE, FALSE, 5);
    }




    /* Creation des boutons */
    pButton[0] = gtk_button_new_with_label(buttonLabel);
    pButton[1] = gtk_button_new_from_stock(GTK_STOCK_QUIT);
    g_signal_connect(G_OBJECT(pButton[1]), "clicked", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(pButton[0]), "clicked", G_CALLBACK(signUpUser), (GtkWidget *)&signUpArray);




    /* Création de la box horizontale */
    pHBox = gtk_hbox_new(TRUE, 0);

    /* Ajout de la GtkHBox dans la GtkVBox */
    gtk_box_pack_start(GTK_BOX(pVBox), pHBox, TRUE, TRUE, 0);

    /* Ajout de Bouton 1 et 2 dans la GtkVBox */
    gtk_box_pack_start(GTK_BOX(pHBox), pButton[0], TRUE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(pHBox), pButton[1], TRUE, TRUE, 0);




    return containerTab;
}












void connectUser(GtkWidget *pButton, gpointer data) {
    GtkWidget **value = data;
    GtkWidget *pDialog;

    const gchar *sText;
    const gchar *password;
    const gchar *pseudo;

    char request[255] = "";

    gchar *sDialogText;

    int exist;

    pseudo = gtk_entry_get_text(value[0]);
    password = gtk_entry_get_text(value[1]);

    printf("\nPseudo : %s",pseudo);
    printf("\nPassword : %s",password);

    sprintf(request,"SELECT * FROM users WHERE pseudo='%s' AND password='%s'",pseudo,password);
    exist = userExist(request);

    if (exist == 0){

        sDialogText = g_strdup_printf("Le pseudo ou le mot de passe sont incorrects !\n Verifiez les champs utilise");

        pDialog = gtk_message_dialog_new(NULL,
            GTK_DIALOG_MODAL,
            GTK_MESSAGE_INFO,
            GTK_BUTTONS_OK,
            sDialogText);

        gtk_dialog_run(GTK_DIALOG(pDialog));

        gtk_widget_destroy(pDialog);
    } else {
        isConnected = 1;

        principalScreen();
    }
}




int checkUser(char *request){
    char *host = "localhost";  // server address
    char *user = "root";     // login
    char *pwd = "root";    // password
    char *db = "gtk";     // database
    unsigned int port = 3306;  // port
    int exist = 0;


    MYSQL *mysql;

    mysql = mysql_init(NULL);

    if(mysql_real_connect(mysql, host, user, pwd, db, port, NULL, 0)){

        printf("\n[OK] mysql_real_connect");
        mysql_query(mysql,request);


        MYSQL_RES *result = NULL;
        MYSQL_ROW row;

        //On met le jeu de résultat dans le pointeur result
        result = mysql_use_result(mysql);



        if ( row = mysql_fetch_row(result) ){
            exist = 1;
        }
        //Libération du jeu de résultat
        mysql_free_result(result);


        mysql_close(mysql);

    }else{
        fprintf(stderr, "[ERR] mysql_real_connect : '%s'\n", mysql_error(mysql));
        exit(EXIT_FAILURE);
    }

    return exist;
}








void signUpUser(GtkWidget *pButton, gpointer data) {
    GtkWidget **value = data;
    GtkWidget *pDialog;

    char request[255] = "";

    const gchar *sText;
    const gchar *pseudo;
    const gchar *password;
    const gchar *passwordConfirmation;
    const gchar *size;
    const gchar *birth;


    gchar *sDialogText;


    int error;
    int errorClose;
    int exist;
    int gender;
    int i = 5;
    int style;



        pseudo = gtk_entry_get_text(value[0]);
        password = gtk_entry_get_text(value[1]);
        passwordConfirmation = gtk_entry_get_text(value[2]);
        if ( strcmp(password,passwordConfirmation) == 0 ) {
            birth = gtk_entry_get_text(value[3]);
            size = gtk_entry_get_text(value[4]);


            while (i < 8){
                if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(value[i]))){

                    gender = i-5;
                    i = 9;
                }
                i++;
            }

            i = 8;
            while (i < 11){
                if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(value[i]))){

                    style = i-8;
                    i = 15;
                }
                i++;
            }

            printf("\nPseudo : %s",pseudo);
            printf("\nPassword : %s",password);
            printf("\nPassword Confirmation : %s",passwordConfirmation);
            printf("\nBirth : %s",birth);
            printf("\nSize : %s",size);
            printf("\nGender : %d",gender);
            printf("\nStyle : %d",style);

            sprintf(request,"SELECT * FROM users WHERE pseudo='%s'",pseudo);
            exist = userExist(request);

            if(exist == 0){
                sprintf(request,"INSERT INTO users(gender,pseudo,password,size,birth,style) VALUES('%d', '%s', '%s','%s','%s','%d')",gender,pseudo,password,size,birth,style);
                sqlInsert(request);
                printf("\nNew user added");
            } else {
                sDialogText = g_strdup_printf("Le pseudo est deja utilise !\n Veuillez en trouver un nouveau");

                pDialog = gtk_message_dialog_new(NULL,
                GTK_DIALOG_MODAL,
                GTK_MESSAGE_INFO,
                GTK_BUTTONS_OK,
                sDialogText);

                gtk_dialog_run(GTK_DIALOG(pDialog));

                gtk_widget_destroy(pDialog);
            }
        }


}


void sqlInsert(char *request){
  char *host = "localhost";  // server address
  char *user = "root";     // login
  char *pwd = "root";    // password
  char *db = "gtk";     // database
  unsigned int port = 3306;  // port

  MYSQL *mysql;

  mysql = mysql_init(NULL);

  if(mysql_real_connect(mysql, host, user, pwd, db, port, NULL, 0)){

    printf("[OK] mysql_real_connect\n");
    mysql_query(mysql,request);
    mysql_close(mysql);

  }else{
    fprintf(stderr, "[ERR] mysql_real_connect : '%s'\n", mysql_error(mysql));
    exit(EXIT_FAILURE);
  }
}




int userExist(char *request){
    char *host = "localhost";  // server address
    char *user = "root";     // login
    char *pwd = "root";    // password
    char *db = "gtk";     // database
    unsigned int port = 3306;  // port
    int exist = 0;


    MYSQL *mysql;

    mysql = mysql_init(NULL);

    if(mysql_real_connect(mysql, host, user, pwd, db, port, NULL, 0)){


        mysql_query(mysql,request);


        MYSQL_RES *result = NULL;
        MYSQL_ROW row;
        int i = 1;

        //On met le jeu de résultat dans le pointeur result
        result = mysql_use_result(mysql);


        if ( row = mysql_fetch_row(result) ){
            exist = 1;
        }
        //Libération du jeu de résultat
        mysql_free_result(result);


        mysql_close(mysql);

    }else{
        fprintf(stderr, "[ERR] mysql_real_connect : '%s'\n", mysql_error(mysql));
        exit(EXIT_FAILURE);
    }

    return exist;
}






void principalScreen(){
    if (isConnected == 1){
        gtk_widget_destroy(window);
        GtkWidget *pVBox;
        GtkWidget *pHBox;
        GtkWidget *pButton;
        GtkWidget *activitiesContainer;
        GtkWidget *labelActivities;
        GtkWidget *meteoContainer;
        GtkWidget *labelMeteo;

        GtkWidget *pNotebook;


        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(window), "Activite");
        gtk_window_set_default_size(GTK_WINDOW(window), 500, 800);
        g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);


        /* Création de la GtkBox verticale */
        pVBox = gtk_vbox_new(FALSE, 0);


        pButton = gtk_button_new_from_stock(GTK_STOCK_QUIT);
        g_signal_connect(G_OBJECT(pButton), "clicked", G_CALLBACK(gtk_main_quit), NULL);
        gtk_box_pack_start(GTK_BOX(pVBox), pButton, FALSE, FALSE, 0);


        /* Creation du GtkNotebook */
        pNotebook = gtk_notebook_new();

        gtk_box_pack_start(GTK_BOX(pVBox), pNotebook,FALSE , TRUE, 0);
        /* Position des onglets : en bas */
        gtk_notebook_set_tab_pos(GTK_NOTEBOOK(pNotebook), GTK_POS_BOTTOM);
        /* Ajout des boutons de navigation */
        gtk_notebook_set_scrollable(GTK_NOTEBOOK(pNotebook), TRUE);


        /* Ajout du notebook dans la fenêtre */
        gtk_container_add(GTK_CONTAINER(window), pVBox);

        activitiesContainer = activities();

        labelActivities = gtk_label_new("Activites");

        /* Insertion de la page */
        gtk_notebook_append_page(GTK_NOTEBOOK(pNotebook), activitiesContainer, labelActivities);



        //meteoContainer = getMeteo();

        //labelActivities = gtk_label_new("Meteo");

        /* Insertion de la page */
        //gtk_notebook_append_page(GTK_NOTEBOOK(pNotebook), meteoContainer, labelmeteo);


        gtk_widget_show_all(window);
        gtk_main();

    }

}



GtkWidget *activities(){
    GtkWidget *container;
    GtkWidget *pVBox;
    GtkWidget *pHBox;
    GtkWidget *box;
    GtkWidget *pFrame;
    GtkWidget *scrollbar;
    GtkWidget *moreButton;



    GtkWidget *tiles[20];

    char *host = "localhost";  // server address
    char *user = "root";     // login
    char *pwd = "root";    // password
    char *db = "gtk";     // database
    unsigned int port = 3306;  // port
    int exist = 0;



    char *request = "SELECT * FROM activite";

    container = gtk_event_box_new();



    /* Création de la GtkBox verticale */
    pVBox = gtk_vbox_new(TRUE, 0);


    gtk_container_add(GTK_CONTAINER(container),pVBox);

    MYSQL *mysql;

    mysql = mysql_init(NULL);

    if(mysql_real_connect(mysql, host, user, pwd, db, port, NULL, 0)){
        mysql_query(mysql,request);

         //Déclaration des objets
        MYSQL_RES *result = NULL;
        MYSQL_ROW row;

        unsigned int i = 0;
        unsigned int num_champs = 0;

        //On met le jeu de résultat dans le pointeur result
        result = mysql_use_result(mysql);



        //Tant qu'il y a encore un résultat ...
        while ( ( row = mysql_fetch_row(result) ) ){

            pFrame = gtk_frame_new("Activite");
            gtk_box_pack_start(GTK_BOX(pVBox), pFrame, TRUE, FALSE, 0);

            /* Création de la GtkBox verticale */
            box = gtk_vbox_new(TRUE, 0);

            /* Ajout de la box dans la scrollbar */
            gtk_container_add(GTK_CONTAINER(pFrame), box);

            /* Création de la GtkBox horizontale */
            pHBox = gtk_hbox_new(TRUE,0);

            /* Ajout de la box horizontale dans la box verticale */
            gtk_container_add(GTK_CONTAINER(box), pHBox);



            char text[255];

            sprintf(text, "%s", row[1]);

            tiles[0] = gtk_label_new(text);

            gtk_box_pack_start(GTK_BOX(pHBox), tiles[0], FALSE, FALSE, 5);


            sprintf(text, "%s", row[2]);

            tiles[1] = gtk_label_new(text);

            gtk_box_pack_start(GTK_BOX(pHBox), tiles[1], FALSE, FALSE, 5);



            /* Création de la GtkBox horizontale */
            pHBox = gtk_hbox_new(TRUE,0);

            /* Ajout de la box horizontale dans la box verticale */
            gtk_container_add(GTK_CONTAINER(box), pHBox);

            sprintf(text, "Style : %s", row[4]);

            tiles[2] = gtk_label_new(text);

            gtk_box_pack_start(GTK_BOX(pHBox), tiles[2], FALSE, FALSE, 5);


            sprintf(text, "Date : %s", row[7]);

            tiles[3] = gtk_label_new(text);

            gtk_box_pack_start(GTK_BOX(pHBox), tiles[3], FALSE, FALSE, 5);

            moreButton = gtk_button_new_with_label("Voir plus");
            g_signal_connect(G_OBJECT(moreButton), "clicked", G_CALLBACK(gtk_main_quit),&row);

            gtk_box_pack_start(GTK_BOX(pHBox), moreButton, FALSE, FALSE, 5);

        }

        //Libération du jeu de résultat
        mysql_free_result(result);


        mysql_close(mysql);

    }else{
        fprintf(stderr, "[ERR] mysql_real_connect : '%s'\n", mysql_error(mysql));
        exit(EXIT_FAILURE);
    }




    return container;
}







int main(int argc, char **argv) {

    gtk_init(&argc,&argv);

    signInScreen();

    gtk_main();

    return EXIT_SUCCESS;
}
