#include <stdio.h>
#include <conio.h>
#include <windows.h>
void logo()
{
    printf("              ____        _        _ _ _        _   _                  _      \n"
           "             |  _ \\      | |      (_) | |      | \\ | |                | |     \n"
           "             | |_) | __ _| |_ __ _ _| | | ___  |  \\| | __ ___   ____ _| | ___ \n"
           "             |  _ < / _` | __/ _` | | | |/ _ \\ | . ` |/ _` \\ \\ / / _` | |/ _ \\\n"
           "             | |_) | (_| | || (_| | | | |  __/ | |\\  | (_| |\\ V / (_| | |  __/\n"
           "             |____/ \\__,_|\\__\\__,_|_|_|_|\\___| |_| \\_|\\__,_| \\_/ \\__,_|_|\\___|");
    printf("\n\n\n\n");
}
void menu()
{
    logo();

    printf("                                        |    |    |\n"
           "                                       )_)  )_)  )_)\n"
           "                                      )___))___))___)\\\n"
           "                                     )____)____)_____)\\\\\n"
           "                                   _____|____|____|____\\\\\\__\n"
           "                          ---------\\                   /---------\n"
           "                            ^^^^^ ^^^^^^^^^^^^^^^^^^^^^\n"
           "                              ^^^^      ^^^^     ^^^    ^^\n"
           "                                   ^^^^      ^^^\n"
           "                          \n"
           "---------------------------------------------------------------------------------------------------------\n");
    printf("\n\n\n\n\n\n\n");
    printf("APPUYER SUR ENTER POUR JOUER");
    printf("                                                                    ");
    printf("F1 AIDE");
    printf("\n");
}
void grille_fixe()
        {
    int ch;
    logo();
            printf("                              CHOISISSEZ VOTRE MER...");
            printf("\n\n\n");
            printf("                                   1. MER FIXE");
            printf("\n\n\n\n\n\n\n\n\n");
            printf("APPUYER SUR LE NUMERO CORRESPONDANT POUR CONTINUER :   ");
            do {


                ch = _getch();

            } while (ch != 27);
        }
void afficher_aide()
        {
      int ch;
      logo();

            printf("\n"
                   "                                         _____ _____  ______ \n"
                   "                                   /\\   |_   _|  __ \\|  ____|\n"
                   "                                  /  \\    | | | |  | | |__   \n"
                   "                                / /\\ \\   | | | |  | |  __|  \n"
                   "                                / ____ \\ _| |_| |__| | |____ \n"
                   "                               /_/    \\_\\_____|_____/|______|\n"
                   "                                                            \n"
                   "                                                             ");
            printf("\n\n\n\n\n");
            printf("La bataille navale oppose deux joueurs qui s'affrontent. Chacun a une flotte composée de 5 bateaux, qui sont, en général, les suivants : 1 porte-avion (5 cases), 1 croiseur (4 cases), 1 contre-torpilleur (3 cases), 1 sous-marin (3 cases), 1 torpilleur (2 cases). \n"
                   "\n"
                   "Au début du jeu, chaque joueur place ses bateaux sur sa grille. Celle-ci est toujours numérotée de A à J verticalement et de 1 à 10 horizontalement. Un à un, les joueurs vont \"tirer\" sur une case de l'adversaire : par exemple, B.3 ou encore H.8. Le but est donc de couler les bateaux adverses. Au fur et à mesure, il faut mettre les pions sur sa propre grille afin de se souvenir de ses tirs passés.[réf. nécessaire]\n"
                   "\n"
                   "Un fonctionnement plus sophistiqué mettant en œuvre de la stratégie est de tirer une salve (trois coups par exemple) et de donner le résultat global de la salve.");
            do {
                ch = _getch();

            } while (ch != 27);

        }
int main()
{
#pragma execution_caracter_set("UTF-8")

    int ch;
    system("color f1");
    int touche = -1;

    do {
       // system("cls");
        menu();
        touche = _getch();
        if(touche != 27)
        {
            switch (touche)
            {
                case 59 :
                    system("cls");
                    afficher_aide();
                    break;
                case 13:
                    system("cls");
                    grille_fixe();
                    break;

                default: main();
                    main();
            }
            printf("a\n");
        }

    } while (touche != 27);
    return 0;
}