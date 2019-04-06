// Auteur : Johnny Vaca
// Date   : 7 mars 2019
// Descriptions : Bataille Navale
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define TAB_SIZE 10


void loggins(char *retour) {

    char nom_utilisateur[15];

    printf("taper votre nom d'utilisateur :\n");
    scanf("%s", nom_utilisateur);
    sprintf(nom_utilisateur, "%s.txt", nom_utilisateur);
    strcpy(retour, nom_utilisateur);



}


int grilles_aleatoires() {
    int nombreAleatoire;

    srand(time(NULL));
    nombreAleatoire = (rand() % 10) + 1;

    return nombreAleatoire;
}
void raccourcis() {
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
}
void vider_buffer() {

    int c;
    do {
        c = getchar();
    } while (c != EOF && c != '\n');

}
void logo() {

    printf("              ____        _        _ _ _        _    _                  _      \n"
           "             |  _ \\     | |      (_) | |      | \\ | |                | |     \n"
           "             | |_) | __ _| |_ __ _ _| | | ___  |  \\| | __ ___   ____ _| | ___ \n"
           "             |  _ < / _` | __/ _` | | | |/ _ \\ | . ` |/ _` \\ \\ / / _` | |/ _ \\\n"
           "             | |_) | (_| | || (_| | | | |  __/ | |\\  | (_| |\\ V / (_| | |  __/\n"
           "             |____/ \\__,_|\\__\\__,_|_|_|_|\\___| |_| \\_|\\__,_| \\_/ \\__,_|_|\\___|");
    printf("\n\n\n\n");
}
void bateau() {

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

}
void textMenu() {
    printf("APPUYER SUR ENTER POUR JOUER");
    printf("                                                                    ");
    printf("                 ESCAPE:   POUR RETOURNER EN ARRIERE                          ");
    printf("F1 AIDE");
    printf("\n");
}
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
        if( i == 0)
        {

        }
        printf("%c%c%c%c%c", DHSB, DHSB, DHSB, DHSB, DHTB);
    }
    printf("%c%c%c%c%c", DHSB, DHSB, DHSB, DHSB, DTRC);
    printf("\n");

}
void bottom() {

    SetConsoleOutputCP(65001); // For accented characters
    SetConsoleOutputCP(437); // For semi-graphic characters

    printf("                                     %c", DBLC);
    for (int i = 0; i < TAB_SIZE - 1; ++i) {
        printf("%c%c%c%c%c", DHSB, DHSB, DHSB, DHSB, DHBB);
    }
    printf("%c%c%c%c%c", DHSB, DHSB, DHSB, DHSB, DBRC);
}
int affichageGrille() {


    int alea;
    alea = grilles_aleatoires();


    int grille[TAB_SIZE][TAB_SIZE];


    FILE *Handle;
    char tmp[500];

    sprintf(tmp, "grille%d.txt", alea);
    // printf("\nfichier = %s\n",tmp);
    Handle = fopen(tmp, "r");
    if (Handle != NULL) {

        for (int f = 0; f < TAB_SIZE; f++) {
            for (int g = 0; g < TAB_SIZE; ++g) {
                grille[f][g] = fgetc(Handle);
                grille[f][g] = grille[f][g] - 48;

            }


        }
        fclose(Handle);
    }


    for (int f = 0; f < TAB_SIZE; f++) {
        for (int g = 0; g < TAB_SIZE; ++g) {

            //    printf("%d",grille[f][g]);
        }
        printf("\n");


    }


#pragma execution_caracter_set("UTF-8")
    SetConsoleOutputCP(CP_UTF8); // For accented characters

    SetConsoleOutputCP(65001); // For accented characters
    SetConsoleOutputCP(437); // For semi-graphic characters
    int ch;
    int x = 0, y2 = 0;
    char y = '/';
    int liste_bateaux[NBR_BATEAUX] = {0, 0, 0, 0, 0, 0};
    int compteur_tout = 0;
    int compteur_bateaux = 0;
    int compteur_touches = 1;
    raccourcis();
    int switchs = 1;



    //   do {

    while (((compteur_tout < PERDU) || (compteur_bateaux < GAGNE)) && (switchs == 1)) {

        if (compteur_bateaux < GAGNE) {
            if ((x >= 0 || x < TAB_SIZE) || (y2 >= 0 || y2 < TAB_SIZE)) {

printf("\n\n\n\n\n\n\n");printf("\n\n\n\n\n\n\n");printf("\n\n\n\n\n\n\n");
                top();


                for (int j = 0; j < TAB_SIZE; ++j) {

                    for (int i = 0; i < TAB_SIZE; ++i) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLEU_BLANC);

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

                        printf("%c%c%c%c", 219, 219, 219, 219);


                    }
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLEU_BLANC);
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
                                if(j == 5)
                                {
                                    if(grille[y2][x] >20){
                                        printf("                       COULE");
                                    }else if(grille[y2][x] == 10)
                                    {
                                        printf("                       A L'EAU !!!");
                                    } else if(grille[y2][x] >10){
                                        printf("                       TOUCHE");
                                    }

                                }


                            }
                        }
                        printf("\n");
                    }

                }


                bottom();
              //  printf("     grille:%d        y2 = %d       ||    x = %d        compteur tout : %d\n", grille[y2][x],y2, x, compteur_tout);
                printf("\n\n\n\n\nSelectionner votre case :  ");


                scanf("%c%d", &y, &x);
                if((y >= 65)&&(y <= 74))
                {
                    y2 = (int) y - 48 - 49 + 32;
                }
                else
                {
                    y2 = (int) y - 48 - 49;
                }



                x--;


                if (compteur_tout == 0) {

                } else {
                    x = -1;
                    y2 = -1;

                }




            }
            while ((x < 0 || x > TAB_SIZE) || (y2 < 0 || y2 > TAB_SIZE)) {
                 system("cls");
                printf("\n\n\n\n\n\n\n");printf("\n\n\n\n\n\n\n");printf("\n\n\n\n\n\n\n");
                top();


                for (int j = 0; j < TAB_SIZE; ++j) {

                    for (int i = 0; i < TAB_SIZE; ++i) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLEU_BLANC);

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

                        printf("%c%c%c%c", 219, 219, 219, 219);


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
                                if(j == 0)
                                {
                              //
                                }
                                printf("%c", DC);
                            }
                            printf("%c%c%c%c", DHSB, DHSB, DHSB, DHSB);
                            if (i == TAB_SIZE - 1) {
                                printf("%c", DVRB);
                            }
                        }
                        printf("\n");
                    }

                }

                bottom();


                printf("\n");
              //  printf("compteur tout : %d\n", compteur_tout);
               // printf("     grille:%d        y2 = %d       ||    x = %d        compteur tout : %d\n", grille[y2][x],y2, x, compteur_tout);
                printf("\n\n\n\n\nSelectionner votre case :  ");
                //_getch();
                scanf("%c%d", &y, &x);
                if((y >= 65)&&(y <= 74))
                {
                    y2 = (int) y - 48 - 49 + 32;
                }
                else
                {
                    y2 = (int) y - 48 - 49;
                }
                x--;
                printf("grille : %d%d\n\n", y2, x);


            }


            if (grille[y2][x] < 10) {
                compteur_tout++;
            }

            if ((grille[y2][x] != 10) && (grille[y2][x] != 0)) {
                if (grille[y2][x] < 10) {
                    compteur_bateaux++;
                }

            }
            if (compteur_bateaux == GAGNE) {
                switchs = 0;
            }

        }


        if (grille[y2][x] == EAU && grille[y2][x] < TOUCHE_EAU && liste_bateaux[0] < EAUX) {
            grille[y2][x] = grille[y2][x] + 10;
            liste_bateaux[0]++;


        }

        if (grille[y2][x] == BATEAU_2) {
            grille[y2][x] = grille[y2][x] + 10;
            liste_bateaux[1]++;
            if (liste_bateaux[1] == BATEAU_2 + 1) {
                for (int i = 0; i < TAB_SIZE; ++i) {
                    for (int j = 0; j < TAB_SIZE; ++j) {
                        if (grille[i][j] == BATEAU_2 + 10) {
                            grille[i][j] = grille[i][j] + 10;

                        }
                    }
                }
            }
        }


        if (grille[y2][x] == BATEAU_3_1) {
            grille[y2][x] = grille[y2][x] + 10;
            liste_bateaux[2]++;

            if (liste_bateaux[2] == BATEAU_3_1 + 1) {
                for (int i = 0; i < TAB_SIZE; ++i) {
                    for (int j = 0; j < TAB_SIZE; ++j) {
                        if (grille[i][j] == BATEAU_3_1 + 10) {
                            grille[i][j] = grille[i][j] + 10;

                        }
                    }
                }
            }

        }

        if (grille[y2][x] == BATEAU_3_2) {
            grille[y2][x] = grille[y2][x] + 10;

            liste_bateaux[3]++;

            if (liste_bateaux[3] == BATEAU_3_2) {
                for (int i = 0; i < TAB_SIZE; ++i) {
                    for (int j = 0; j < TAB_SIZE; ++j) {
                        if (grille[i][j] == BATEAU_3_2 + 10) {
                            grille[i][j] = grille[i][j] + 10;

                        }
                    }
                }
            }
        }

        if (grille[y2][x] == BATEAU_4) {
            grille[y2][x] = grille[y2][x] + 10;

            liste_bateaux[4]++;

            if (liste_bateaux[4] == BATEAU_4) {
                for (int i = 0; i < TAB_SIZE; ++i) {
                    for (int j = 0; j < TAB_SIZE; ++j) {
                        if (grille[i][j] == BATEAU_4 + 10) {
                            grille[i][j] = grille[i][j] + 10;

                        }
                    }
                }
            }
        }

        if (grille[y2][x] == BATEAU_5) {
            grille[y2][x] = grille[y2][x] + 10;

            liste_bateaux[5]++;
            if (liste_bateaux[5] == BATEAU_5) {
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







        //  grille[x][y] = grille[x][y]+10;

        // while(liste_bateaux[])
        // ch = _getch();
        //system("cls");
    } //while (ch != 27);



    system("cls");
    printf("BRAVO  !!!");
    int score;
    score = PERDU+1-(PERDU+1-compteur_tout)-GAGNE;
    printf("\n\n votre scores est : %d\n\n", score);

int charLecture;
    char nom[15];
    bateau();
    printf("\n\n\n\nReecriver votre nom d'utilisateur pour enregistrer votre score\n\n\n");

    FILE *fichierloggin;
    fichierloggin = fopen(nom, "a");
    while (fichierloggin == NULL)
    {
        loggins(nom);
        fichierloggin = fopen(nom, "a");
    }
    fprintf(fichierloggin,"score: %d\n",score);
    fclose(fichierloggin);


    fichierloggin = fopen(nom, "r");
 while((charLecture = fgetc(fichierloggin))!= EOF)
 {
     if(charLecture == '\n')
     {
         printf("\n");
     }
     else
     {
         putchar(charLecture);
     }
 }
    fclose(fichierloggin);

system("pause");
system("cls");
    return score;
}

void menuGrilles() {

    int ch = -1;


    do {

        system("cls");

        logo();
        printf("                              CHOISISSEZ VOTRE MER...");
        printf("\n\n\n      ");
        printf("                                   1. MERS ALEATOIRES\n");

        printf("\n\n\n\n");
        if (ch != 49 && ch != -1) {
            printf("                                                           ");
            printf("CETTE MER N'EXISTE PAS !!!");
            printf("getch = %d",ch);
            // printf("%d",ch);
        }
        if (ch == 49) {
            system("cls");
            affichageGrille();
        }


        printf("\n\n\n\n");
        printf("APPUYER SUR LE NUMERO CORRESPONDANT POUR CONTINUER :   ");
        printf("                                                                                            ESCAPE:   POUR RETOURNER EN ARRIERE");
        ch = _getch();

    } while (ch != 27);
}
void afficher_aide() {

#pragma execution_caracter_set("UTF-8")
    SetConsoleOutputCP(CP_UTF8); // For accented characters
    int ch;
    logo();

    printf("\n"
           "                                          _____ _____  ______ \n"
           "                                   /\\   |_   _|  _ \\| ____|\n"
           "                                  /  \\    | | | |  | | |__   \n"
           "                                 / /\\\\   | | | |  | |  __|  \n"
           "                                / ____ \\ _| |_| |__| | |____ \n"
           "                               /_/   \\_\\_____|_____/|______|\n"
           "                                                            \n"
           "                                                             ");
    printf("\n\n\n\n\n");
    printf("La bataille navale oppose deux joueurs qui s'affrontent. Chacun a une flotte compos?e de 5 bateaux, qui sont, en g?n?ral, les suivants : 1 porte-avion (5 cases), 1 croiseur (4 cases), 1 contre-torpilleur (3 cases), 1 sous-marin (3 cases), 1 torpilleur (2 cases). \n"
           "\n"
           "Au d?but du jeu, chaque joueur place ses bateaux sur sa grille. Celle-ci est toujours num?rot?e de A ? J verticalement et de 1 ? 10 horizontalement. Un ? un, les joueurs vont \"tirer\" sur une case de l'adversaire : par exemple, B.3 ou encore H.8. Le but est donc de couler les bateaux adverses. Au fur et ? mesure, il faut mettre les pions sur sa propre grille afin de se souvenir de ses tirs pass?s.[r?f. n?cessaire]\n"
           "\n"
           "Un fonctionnement plus sophistiqu? mettant en ?uvre de la strat?gie est de tirer une salve (trois coups par exemple) et de donner le r?sultat global de la salve.");
    printf("\n\n\n\n");
    printf("                                                                                                                                       ESCAPE:   POUR RETOURNER EN ARRIERE");
    do {
        ch = _getch();

    } while (ch != 27);
}
int principal() {
    int touche;

    do {

        system("cls");


        bateau();
        textMenu();
        touche = _getch();

        switch (touche) {
            case 59 :
                system("cls");
                afficher_aide();
                break;
            case 13:
                system("cls");
                menuGrilles();
                break;
            case 27:
                break;
            case 0:
                break;
            default:
                principal();
        }

    } while (touche != 27);

    return 0;
}
int main() {


#pragma execution_caracter_set("UTF-8")
    SetConsoleOutputCP(CP_UTF8); // For accented characters

    keybd_event(VK_F11, 0, 0, 0); //Appuie sur ALT
    keybd_event(VK_F11, 0, KEYEVENTF_KEYUP, 0); // Relache ENTREE

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLEU_BLANC);

    char nom[15];
    bateau();
  loggins(nom);


    FILE *fichierloggin;
    fichierloggin = fopen(nom, "a+");
    fclose(fichierloggin);

  //  system("cls");

    bateau();
    textMenu();

    principal();


    return 0;
}