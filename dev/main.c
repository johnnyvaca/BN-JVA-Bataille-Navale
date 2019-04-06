// Auteur : Johnny Vaca
// Date   : 7 mars 2019
// Descriptions : Bataille Navale
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define TAB_SIZE 10


/// FONCTION QUI VA RETOURNER UN NOMBRE ALEATOIRE DE 1 à 10
int grilles_aleatoires() {
    int nombreAleatoire;

    srand(time(NULL));
    nombreAleatoire = (rand() % 10) + 1;

    return nombreAleatoire;
}

/// RACCOURCIS EN CONSTANTES
void constantes() {
#define DTLC 201 // +, Double Top Left Corner
#define DTRC 187 // +, Double Top Right Corner
#define DBLC 200 // +, Double Bottom Left Corner
#define DBRC 188 // +, Double Bottom Right Corner
#define DVSB 186 // ?, Double Vertical Simple Border
#define DVRB 185 // ?, Double Vertical Right Border
#define DVLB 204 // ?, Double Vertical Left Border
#define DHSB 205 // -, Double Horizontal Simple Border
#define DHBB 202 // -, Double Horizontal Bottom Border
#define DHTB 203 // -, Double Horizontal Top Border
#define DC   206 // +, Double Center
#define BLEU  17 //, BLEU SUR BLEU
#define BLEU_BLANC  241 //, BLEU SUR BLANC
#define BLANC  255 //, BLANC SUR BLANC
#define NOIR  0 //, NOIR
#define ROUGE  68 //, ROUGE
#define VIDE  0
#define TOUCHE_EAU  10
#define TOUCHE  10
#define COULE  20
#define COULER  2
#define BATEAU_2 1
#define BATEAU_3_1 2
#define BATEAU_3_2 3
#define BATEAU_4 4
#define BATEAU_5 5
#define EAU 0
#define EAUX (TAB_SIZE)*(TAB_SIZE)-BATEAU_2-BATEAU_3_1-BATEAU_3_2-BATEAU_4-BATEAU_5
#define GAGNE BATEAU_2+BATEAU_3_1+BATEAU_3_2+BATEAU_4+BATEAU_5+2
#define PERDU TAB_SIZE*TAB_SIZE-1
#define NBR_BATEAUX 6
#define ESCAPE 59
#define F1 27
#define N1 49
#define CARRE_COULEUR 219
#define ENTER 13
}
/*void vider_buffer() {

    int c;
    do {
        c = getchar();
    } while (c != EOF && c != '\n');

} */
/// TITRE PRINCIPALE
void titre_Bat_Nav() {
#pragma execution_caracter_set("UTF-8")
    SetConsoleOutputCP(CP_UTF8); // For accented characters
    printf("              ____        _        _ _ _        _    _                  _      \n"
           "             |   _ \\     | |      (_) | |      | \\ | |                | |     \n"
           "             | |_) | __ _| |_ __ _ _| | | ___  |  \\| | __ ___   ____ _| | ___ \n"
           "             |  _ < / _` | __/ _` | | | |/ _ \\ | . ` |/ _` \\ \\ / / _` | |/ _ \\\n"
           "             | |_) | (_| | || (_| | | | |  __/ | |\\  | (_| |\\ V / (_| | |  __/\n"
           "             |____/ \\__,_|\\__\\__,_|_|_|_|\\___| |_| \\_|\\__,_| \\_/ \\__,_|_|\\___|");
    printf("\n\n\n\n");
}

/// ASCII ART BATEAU
void bateau() {
#pragma execution_caracter_set("UTF-8")
    SetConsoleOutputCP(CP_UTF8); // For accented characters
    titre_Bat_Nav();

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

}

/// AFFICHER TEXT DU MENU
void textMenu() {
    printf("APPUYER SUR ENTER POUR JOUER");
    printf("                                                                    ");
    printf("                 ESCAPE:   POUR RETOURNER EN ARRIERE                          ");
    printf("F1 AIDE");
    printf("\n");
}

/// AFFICHE LES COINS ET LES ARRETES DU HAUT DE LA GRILLE
void top() {
#pragma execution_caracter_set("UTF-8")
    SetConsoleOutputCP(65001); // For accented characters
    SetConsoleOutputCP(437); // For semi-graphic characters
    for (int i = 0; i < TAB_SIZE; ++i) {
        if (i == 0) {
            printf("                               ");
            printf("        %d  ", i + 1);
        } else {
            printf("  %d  ", i + 1);
        }

    }
    printf("\n");
    printf("                               ");
    printf("      %c", DTLC);
    for (int i = 0; i < TAB_SIZE - 1; ++i) {
        if (i == 0) {

        }
        printf("%c%c%c%c%c", DHSB, DHSB, DHSB, DHSB, DHTB);
    }
    printf("%c%c%c%c%c", DHSB, DHSB, DHSB, DHSB, DTRC);
    printf("\n");

}

/// AFFICHE LES COINS ET LES ARRETES DU BAS DE LA GRILLE
void bottom() {

    SetConsoleOutputCP(65001); // For accented characters
    SetConsoleOutputCP(437); // For semi-graphic characters

    printf("                                     %c", DBLC);
    for (int i = 0; i < TAB_SIZE - 1; ++i) {
        printf("%c%c%c%c%c", DHSB, DHSB, DHSB, DHSB, DHBB);
    }
    printf("%c%c%c%c%c", DHSB, DHSB, DHSB, DHSB, DBRC);
}

/// CONFIGURATION DES REACTIONS DANS UNE PARITE
void commancer_partie() {
#pragma execution_caracter_set("UTF-8")
    SetConsoleOutputCP(CP_UTF8); // For accented characters

    int aleatoire;
    aleatoire = grilles_aleatoires(); // aleatoire recuper l'entier retourné par la fonction


    int grille[TAB_SIZE][TAB_SIZE];


    FILE *fichiergrilles;
    char nom_grille_recup[9];

    sprintf(nom_grille_recup, "..\\grilles\\grille%d.txt",
            aleatoire); // donne le nom du fichier text avec valeur aleatoire

    fichiergrilles = fopen(nom_grille_recup, "r"); // ouvrire en lecture
    if (fichiergrilles != NULL) { // si fichier existe donner valeur dans le fichier à la grille

        for (int f = 0; f < TAB_SIZE; f++) {
            for (int g = 0; g < TAB_SIZE; ++g) {
                grille[f][g] = fgetc(
                        fichiergrilles); // grille recuper valeurs decimal ASCII  du charactere lue du fichier
                grille[f][g] = grille[f][g] - 48; // donne la valeur decimal 0 pour la plus petite
            }
        }
        fclose(fichiergrilles);
    }


#pragma execution_caracter_set("UTF-8")
    SetConsoleOutputCP(CP_UTF8); // For accented characters

    SetConsoleOutputCP(65001); // For accented characters
    SetConsoleOutputCP(437); // For semi-graphic characters
    int y = 0, x = 0;
    char x1 ='/'; // reprends lattre selctionnée
    int liste_bateaux[NBR_BATEAUX] = {0, 0, 0, 0, 0,
                                      0}; // case 0 = eau   ||  case 1 = bateau1    ||   case 2 = bateau2  etc...
    int compteur_tout = 0; // compteur qui dira perdu
    int compteur_bateaux = 0; // compteur qui dira si gagné
    constantes(); // ajout des raccourcis pour les couleurs , grille, et cibles
    int switchs = 1; //pour sortir de la partie





    while (((compteur_tout < PERDU) || (compteur_bateaux < GAGNE)) && (switchs == 1)) {

        if (compteur_bateaux < GAGNE) {
            if ((y >= 0 || y < TAB_SIZE) || (x >= 0 || x < TAB_SIZE)) {

                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");


/// BODY QUI SE MODIFIE AVEC LES SELECTIONS DES CASES
///  DEBUT AFFICHAGE GRILLE     ---------------------------------------------------------------------------------------------------------------------------
                top();
                for (int j = 0; j < TAB_SIZE; ++j) {

                    for (int i = 0; i < TAB_SIZE; ++i) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                                BLEU_BLANC); // BLUE SUR BLANC POUR TOUT LE DEBUT DU JEU

                        if (i == 0) {


                            printf("                                %c", j + 'A');
                        }
                        if (i == 0) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLEU_BLANC);
                            printf("    ");
                        }
                        printf("%c", DVSB);
                        if (grille[j][i] == VIDE || grille[j][i] < TOUCHE_EAU) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLANC);
                        } else {
                            if (grille[j][i] == TOUCHE_EAU) {
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLEU);
                            } else {
                                if (grille[j][i] > TOUCHE && grille[j][i] < COULE) {
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NOIR);
                                } else {
                                    if (grille[j][i] > COULER) {
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ROUGE);
                                    } else {
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLANC);
                                    }

                                }

                            }

                        }

                        printf("%c%c%c%c", CARRE_COULEUR, CARRE_COULEUR, CARRE_COULEUR, CARRE_COULEUR);


                    }
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                            BLEU_BLANC); //DEFINIR QU'APRES LE CHANGEMENT DE COULEUR DES CASES DU BLEU SUR BLANC
                    printf("%c", DVSB);
                    printf("\n");
                    if (j != TAB_SIZE - 1) {
                        printf("                               ");
                        for (int i = 0; i < TAB_SIZE; ++i) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLEU_BLANC);
                            if (i == 0) {
                                printf("      %c", DVLB);
                            } else {
                                printf("%c", DC);
                            }
                            printf("%c%c%c%c", DHSB, DHSB, DHSB, DHSB);
                            if (i == TAB_SIZE - 1) {
                                printf("%c", DVRB);
                                if (j == 5) {
                                    if (grille[x][y] > COULE) {
                                        printf("                       COULE");
                                    } else if (grille[x][y] == TOUCHE_EAU) {
                                        printf("                       A L'EAU !!!");
                                    } else if (grille[x][y] > TOUCHE) {
                                        printf("                       TOUCHE");
                                    }

                                }


                            }
                        }
                        printf("\n");
                    }

                }
                bottom();
///     FIN AFFICHAGE GRILLE  ---------------------------------------------------------------------------------------------------------------------------


                printf("\n\n\n\n\nSelectionner votre case :  ");


                scanf("%c%d", &x1, &y);
                if ((x1 >= 65) && (x1 <= 74)) {
                    x = (int) x1 - 97 + 32;
                } else {
                    x = (int) x1 - 97;
                }


                y--;


                if (compteur_tout == 0) {

                } else {
                    y = -1;
                    x = -1;

                }


            }
            while ((y < 0 || y > TAB_SIZE) || (x < 0 || x > TAB_SIZE)) { //  tant que les valeur sont pas entre 0 et 9 en reaffiche la grille et redemande
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                top();


                for (int j = 0; j < TAB_SIZE; ++j) {

                    for (int i = 0; i < TAB_SIZE; ++i) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLEU_BLANC);

                        if (i == 0) {


                            printf("                                %c", j + 'A'); // lis dans la table ascii depuis la valeur de A jusqu'a Longuer de la grille
                        }
                        if (i == 0) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLEU_BLANC);

                            printf("    ");
                        }
                        printf("%c", DVSB);
                        if (grille[j][i] == VIDE || grille[j][i] < TOUCHE_EAU) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLANC);
                        } else {
                            if (grille[j][i] == TOUCHE_EAU) {
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLEU);
                            } else {
                                if (grille[j][i] > TOUCHE && grille[j][i] < COULE) {
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NOIR);
                                } else {
                                    if (grille[j][i] > COULER) {
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ROUGE);
                                    } else {
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLANC);
                                    }

                                }

                            }

                        }

                        printf("%c%c%c%c", CARRE_COULEUR, CARRE_COULEUR, CARRE_COULEUR, CARRE_COULEUR);


                    }
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLEU_BLANC);
                    printf("%c", DVSB);
                    printf("\n");
                    if (j != TAB_SIZE - 1) {
                        for (int i = 0; i < TAB_SIZE; ++i) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLEU_BLANC);
                            if (i == 0) {
                                printf("                               ");
                                printf("      %c", DVLB);
                            } else {
                                if (j == 0) {
                                    //
                                }
                                printf("%c", DC);
                            }
                            printf("%c%c%c%c", DHSB, DHSB, DHSB, DHSB);
                            if (i == TAB_SIZE - 1) {
                                printf("%c", DVRB);
                                if (j == 5) {
                                    printf("                       TERRE");
                                }
                            }
                        }
                        printf("\n");
                    }

                }

                bottom();


                printf("\n");
                printf("\n\n\n\n\nSelectionner votre case :  ");
                //_getch();
                scanf("%c%d", &x1, &y);
                if ((x1 >= 65) && (x1 <= 74)) {
                    x = (int) x1 - 48 - 49 + 32;
                } else {
                    x = (int) x1 - 48 - 49;
                }
                y--;
                printf("grille : %d%d\n\n", x, y);


            }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            if (grille[x][y] < 10) {
                compteur_tout++; // ADITIONNER 1 AU COMPTEUR POUR DONNER LE NOMBRE DE FOIS QU'IL A TOUCHE UN BATEAU OU EAU
            }

            if ((grille[x][y] != 10) && (grille[x][y] != 0)) {
                if (grille[x][y] < 10) {// ADITIONNER 1 AU COMPTEUR POUR DONNER LE NOMBRE DE FOIS QU'IL A TOUCHE UN BATEAU
                    compteur_bateaux++;
                }

            }
            if (compteur_bateaux == GAGNE) { // if compteur == addition des longeurs des bateaux alors sortir de la partie
                switchs = 0;
            }
            if (compteur_tout == PERDU) { // if compteur == addition des longeurs des bateaux alors sortir de la partie
                switchs = 0;
            }

        }


        if (grille[x][y] == EAU && grille[x][y] < TOUCHE_EAU && liste_bateaux[0] < EAUX) {
            grille[x][y] = grille[x][y] + 10;
            liste_bateaux[0]++;


        }
// ajouter 10 au bateau si touche ou coulé
        if (grille[x][y] == BATEAU_2) {
            grille[x][y] = grille[x][y] + TOUCHE;
            liste_bateaux[1]++;
            if (liste_bateaux[1] == BATEAU_2 + 1) { // si bateau 1 == longeur bateau augmenter de 10 a toute les cases du bateau
                for (int i = 0; i < TAB_SIZE; ++i) {
                    for (int j = 0; j < TAB_SIZE; ++j) {
                        if (grille[i][j] == BATEAU_2 + TOUCHE) {
                            grille[i][j] = grille[i][j] + 10;

                        }
                    }
                }
            }
        }

// ajouter 10 au bateau si touche ou coulé
        if (grille[x][y] == BATEAU_3_1) {
            grille[x][y] = grille[x][y] + TOUCHE;
            liste_bateaux[2]++;

            if (liste_bateaux[2] == BATEAU_3_1 + 1) {// si bateau 1 == longeur bateau augmenter de 10 a toute les cases du bateau
                for (int i = 0; i < TAB_SIZE; ++i) {
                    for (int j = 0; j < TAB_SIZE; ++j) {
                        if (grille[i][j] == BATEAU_3_1 + TOUCHE) {
                            grille[i][j] = grille[i][j] + 10;

                        }
                    }
                }
            }

        }
// ajouter 10 au bateau si touche ou coulé
        if (grille[x][y] == BATEAU_3_2) {
            grille[x][y] = grille[x][y] + 10;

            liste_bateaux[3]++;

            if (liste_bateaux[3] == BATEAU_3_2) {// si bateau 1 == longeur bateau augmenter de 10 a toute les cases du bateau
                for (int i = 0; i < TAB_SIZE; ++i) {
                    for (int j = 0; j < TAB_SIZE; ++j) {
                        if (grille[i][j] == BATEAU_3_2 + 10) {
                            grille[i][j] = grille[i][j] + 10;

                        }
                    }
                }
            }
        }
// ajouter 10 au bateau si touche ou coulé
        if (grille[x][y] == BATEAU_4) {
            grille[x][y] = grille[x][y] + 10;

            liste_bateaux[4]++;

            if (liste_bateaux[4] == BATEAU_4) {// si bateau 1 == longeur bateau augmenter de 10 a toute les cases du bateau
                for (int i = 0; i < TAB_SIZE; ++i) {
                    for (int j = 0; j < TAB_SIZE; ++j) {
                        if (grille[i][j] == BATEAU_4 + 10) {
                            grille[i][j] = grille[i][j] + 10;

                        }
                    }
                }
            }
        }
// ajouter 10 au bateau si touche ou coulé
        if (grille[x][y] == BATEAU_5) {
            grille[x][y] = grille[x][y] + 10;

            liste_bateaux[5]++;
            if (liste_bateaux[5] == BATEAU_5) {// si bateau 1 == longeur bateau augmenter de 10 a toute les cases du bateau
                for (int i = 0; i < TAB_SIZE; ++i) {
                    for (int j = 0; j < TAB_SIZE; ++j) {
                        if (grille[i][j] == BATEAU_5 + 10) {
                            grille[i][j] = grille[i][j] + 10;

                        }
                    }
                }
            }
        }


        system("cls");

    }


    system("cls");
    int score;
    if(compteur_tout == PERDU)
    {
        printf("VOUS AVEZ PERDU");
        score = 0;
    }
    else
    {
        printf("BRAVO  !!!");
        score = PERDU + 1 - (PERDU + 1 - compteur_tout) - GAGNE;
    }



    printf("\n\n votre scores est : %d\n\n", score);

    char nom_utilisateur[15]; // le nom du fichier
    char nom_utilisateur_recup[15]; // recupere le nom du fichier+extention

    bateau();
    printf("\n\n\n\nReecriver votre nom d'utilisateur pour enregistrer votre score\n\n\n");
    printf("taper votre nom d'utilisateur :\n");

    scanf("%s", nom_utilisateur);
    sprintf(nom_utilisateur_recup, "..\\loggins\\%s.txt", nom_utilisateur); // recupere le nom du fichier+extention


    FILE *fichierloggin; // ouvrir pour editer un fichier
    fichierloggin = fopen(nom_utilisateur_recup, "a"); // methode pour ecrire a la fin du fichier



    fprintf(fichierloggin, "score: %d\n", score); // ecrire le score dans le fichier
    fclose(fichierloggin);


    fichierloggin = fopen(nom_utilisateur_recup, "r");
    while (!feof(fichierloggin)) { // lire tout le fichier
        putchar(fgetc(fichierloggin));
    }
    fclose(fichierloggin);

    system("pause");
    system("cls");

}

/// AFFICHE UN MENU POUR LES GRILLES
void menuGrilles() {
#pragma execution_caracter_set("UTF-8")
    SetConsoleOutputCP(CP_UTF8); // For accented characters
    int ch = -1;


    do {

        system("cls");

        titre_Bat_Nav();
        printf("                              CHOISISSEZ VOTRE MER...");
        printf("\n\n\n      ");
        printf("                                   1. MERS ALEATOIRES\n");

        printf("\n\n\n\n");
        if (ch != 49 && ch != -1) {
            printf("                                                           ");
            printf("CETTE MER N'EXISTE PAS !!!");

        }
        if (ch == N1) { // si ch == 1
            system("cls");
            commancer_partie();
        }


        printf("\n\n\n\n");
        printf("APPUYER SUR LE NUMERO CORRESPONDANT POUR CONTINUER :   ");
        printf("                                                                                            ESCAPE:   POUR RETOURNER EN ARRIERE");
        ch = _getch();

    } while (ch != ESCAPE);
}

/// AFFICHE L'AIDE
void afficher_aide() {

#pragma execution_caracter_set("UTF-8")
    SetConsoleOutputCP(CP_UTF8); // For accented characters
    int ch;
    titre_Bat_Nav();

    printf("\n"
           "                                         _____ _____  ______ \n"
           "                                   /\\   |_   _|  _  \\| ____|\n"
           "                                  /  \\    | | | |  | | |__   \n"
           "                                 / /\\ \\   | | | |  | |  __|  \n"
           "                                / ____ \\ _| |_| |__| | |____ \n"
           "                               /_/    \\_\\_____|_____/|______|\n"
           "                                                            \n"
           "                                                             ");
    printf("\n\n\n\n\n");
    printf("La bataille navale oppose deux joueurs qui s'affrontent. Chacun a une flotte composée de 5 bateaux, qui sont,"
           " en général, les suivants : 1 bateau (5 cases), 1 bateau"
           " (4 cases), 1 bateau (3 cases), 1 bateau (3 cases) et un autre bateau (2 cases). \n\n"
           "Au d?but du jeu, chaque joueur place ses bateaux sur sa grille. Celle-ci est toujours numérotée de A à J ver"
           "ticalement et de 1 à 10 horizontalement. Le joueurs tire sur une case de l'adversaire : par exemple, B3 ou e"
           "ncore H8. Le but est donc de couler les bateaux adverses. Au fur et à mesure, il faut mettre les pions sur sa"
           " propre grille afin de se souvenir de ses tirs passés.\n"
    );
    printf("\n\n\n\n");
    printf("                                                                                                                                       ESCAPE:   POUR RETOURNER EN ARRIERE");
    do {
        ch = _getch();

    } while (ch != ESCAPE); // tant que nous ne touchons pas sur escape ne rien faire
}

/// AFFICHAGE MENU PRINCIPALE
int menu_pricipal() {
#pragma execution_caracter_set("UTF-8")
    SetConsoleOutputCP(CP_UTF8); // For accented characters
    int touche;

    do {

        system("cls");


        bateau();
        textMenu();
        touche = _getch(); // touche recupere le numero ascii d'une touche selectionée

        switch (touche) {
            case F1 : // touche F1
                system("cls");
                afficher_aide();
                break;
            case ENTER: // touche Enter
                system("cls");
                menuGrilles();
                break;
            case ESCAPE: // ESCAPE
                break;
            case 0: // VALEUR NULL (debugs)
                break;
            default:
                menu_pricipal(); // rappel de la fonction
        }

    } while (touche != 27); //  tant que touche != ESCAPE redemander le switch

    return 0;
}

int main() {

#pragma execution_caracter_set("UTF-8") // For accented characters
    SetConsoleOutputCP(CP_UTF8); // For accented characters

    keybd_event(VK_F11, 0, 0, 0); //Appuie sur ALT
    keybd_event(VK_F11, 0, KEYEVENTF_KEYUP, 0); // Appuie ENTER

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLEU_BLANC); // Text : Bleu et Fond : Blanc


    bateau();
    char nom_utilisateur[15]; // recois le nom du fichier
    char nom_utilisateur_recup[15]; // recupere le nom du fichier avec extention

    printf("taper votre nom d'utilisateur :\n");
    scanf("%s", nom_utilisateur);
    sprintf(nom_utilisateur_recup, "..\\loggins\\%s.txt",
            nom_utilisateur); // donne nom du fichier à nom_utilisateur_recup


    FILE *fichierloggin;
    fichierloggin = fopen(nom_utilisateur_recup, "a+"); // cree
    while (!feof(fichierloggin)) // tant que nous lisons pas jusqu'à la fin du fichier afficher le contenue du fichier
    {
        putchar(fgetc(fichierloggin)); // affiche un charactere du fichier
    }
    fclose(fichierloggin);

    system("pause");
    system("cls");

    bateau();
    textMenu();

    menu_pricipal();


    return 0;
}