// Auteur : Johnny Vaca
// Date   : 7 mars 2019
// Descriptions : Bataille Navale
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define TAB_SIZE 10


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
#define BATEAU_2 2
#define BATEAU_3_1 3
#define BATEAU_3_2 3
#define BATEAU_4 4
#define BATEAU_5 5
#define EAU 0
#define EAUX (TAB_SIZE)*(TAB_SIZE)-BATEAU_2-BATEAU_3_1-BATEAU_3_2-BATEAU_4-BATEAU_5
};

int grilleFixe[TAB_SIZE][TAB_SIZE] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {2, 0, 5, 5, 5, 5, 5, 0, 0, 3},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {0, 0, 3, 0, 0, 0, 0, 0, 0, 3},
        {0, 0, 3, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 4, 4, 4, 4},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};


void vider_buffer()
{

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

void menu() {

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
            printf("        %d  ", i + 1);
        } else {
            printf("  %d  ", i + 1);
        }

    }
    printf("\n");
    printf("      %c", DTLC);
    for (int i = 0; i < TAB_SIZE - 1; ++i) {
        printf("%c%c%c%c%c", DHSB, DHSB, DHSB, DHSB, DHTB);
    }
    printf("%c%c%c%c%c", DHSB, DHSB, DHSB, DHSB, DTRC);
    printf("\n");

}
void body() {


    for (int j = 0; j < TAB_SIZE; ++j) {

        for (int i = 0; i < TAB_SIZE; ++i) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLEU_BLANC);

            if (i == 0) {


                printf(" %c", j + 'A');
            }
            if (i == 0) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLEU_BLANC);
                printf("    ");
            }
            printf("%c", DVSB);
            if (grilleFixe[j][i] == VIDE || grilleFixe[j][i] < TOUCHE_EAU) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLANC);
            } else {
                if (grilleFixe[j][i] == TOUCHE_EAU) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLEU);
                } else {
                    if (grilleFixe[j][i] > TOUCHE && grilleFixe[j][i] < COULE) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NOIR);
                    } else {
                        if (grilleFixe[j][i] > COULER) {
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
                    printf("      %c", DVLB);
                } else {
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

}

void bottom() {

    SetConsoleOutputCP(65001); // For accented characters
    SetConsoleOutputCP(437); // For semi-graphic characters

    printf("      %c", DBLC);
    for (int i = 0; i < TAB_SIZE - 1; ++i) {
        printf("%c%c%c%c%c", DHSB, DHSB, DHSB, DHSB, DHBB);
    }
    printf("%c%c%c%c%c", DHSB, DHSB, DHSB, DHSB, DBRC);
}

void affichageGrille() {

#pragma execution_caracter_set("UTF-8")
    SetConsoleOutputCP(CP_UTF8); // For accented characters

    SetConsoleOutputCP(65001); // For accented characters
    SetConsoleOutputCP(437); // For semi-graphic characters
    int ch;
int x = -1, y2 = 0;
char y = '<';
int liste_bateaux[6]={0,0,0,0,0,0};
int compteur_tout = 0;
int compteur_bateaux = 0;
    raccourcis();



 //   do {

    while ((compteur_tout != TAB_SIZE*TAB_SIZE-1)||( compteur_bateaux < BATEAU_2+BATEAU_3_1+BATEAU_3_2+BATEAU_4+BATEAU_5)){

        if( compteur_bateaux < BATEAU_2+BATEAU_3_1+BATEAU_3_2+BATEAU_4+BATEAU_5)
        {
            if ((x >=0 || x< TAB_SIZE)||(y2 >=0 || y2 <TAB_SIZE))
            {   top();
                body();
                bottom();


                printf("\n\n\n\n\n\n\n");

                for (int i = 0; i < TAB_SIZE; ++i) {
                    for (int j = 0; j < TAB_SIZE; ++j) {
                        printf("%d ",grilleFixe[i][j]);
                    }printf("\n");
                }




                printf("\n0 : %d\n", liste_bateaux[0]);
                printf("1 : %d\n", liste_bateaux[1]);
                printf("2 : %d\n", liste_bateaux[2]);
                printf("3 : %d\n", liste_bateaux[3]);
                printf("4 : %d\n", liste_bateaux[4]);
                printf("5 : %d\n", liste_bateaux[5]);

                printf("compteur:bat : %d\n", compteur_bateaux);
                printf("compteur: tout : %d\n\n\n", compteur_tout);

                printf("Selectionner votre case :  ");


                scanf("%c%d",&y, &x);
                y2 = (int) y - 48 - 49;



                x--;









                compteur_tout++;
                x = -1;
                y2 = -1;
            }




            while ((x <0 || x> TAB_SIZE)||(y2 <0 || y2 >TAB_SIZE))
            {
                system("cls");
                top();
                body();
                bottom();


                printf("\n\n\n\n\n\n\n");
                printf("Selectionner votre case :  ");

                scanf("%c%d",&y, &x);
                y2 = (int) y - 48 - 49;
                x--;
                printf("bbb : %d%d\n\n", y2,x);




            }

if((grilleFixe[y2][x] != 10)&&(grilleFixe[y2][x] != 0))
{
    if(grilleFixe[y2][x] < 10)
    {
        compteur_bateaux++;
    }

}
if(compteur_bateaux == BATEAU_2+BATEAU_3_1+BATEAU_3_2+BATEAU_4+BATEAU_5)
{
    compteur_tout == TAB_SIZE*TAB_SIZE-1;
}

        }
        else
        {
            system("cls");
            printf("BRAVO  !!!");
        }






        if (grilleFixe[y2][x] == EAU && grilleFixe[y2][x] < TOUCHE_EAU && liste_bateaux[0] < EAUX) {
            grilleFixe[y2][x] = grilleFixe[y2][x] + 10;

            liste_bateaux[0]++;
        }

        if (grilleFixe[y2][x] == BATEAU_2) {
            grilleFixe[y2][x] = grilleFixe[y2][x] + 10;

            liste_bateaux[1]++;
        }

        if (grilleFixe[y2][x] == BATEAU_3_1) {
            grilleFixe[y2][x] = grilleFixe[y2][x] + 10;

            liste_bateaux[2]++;
        }

        if (grilleFixe[y2][x] == BATEAU_3_2) {
            grilleFixe[y2][x] = grilleFixe[y2][x] + 10;

            liste_bateaux[3]++;
        }

        if (grilleFixe[y2][x] == BATEAU_4) {
            grilleFixe[y2][x] = grilleFixe[y2][x] + 10;

            liste_bateaux[4]++;
        }

        if (grilleFixe[y2][x] == BATEAU_5) {
            grilleFixe[y2][x] = grilleFixe[y2][x] + 10;

            liste_bateaux[5]++;
        }





        system("cls");







      //  grilleFixe[x][y] = grilleFixe[x][y]+10;

       // while(liste_bateaux[])
       // ch = _getch();
            //system("cls");
    } //while (ch != 27);



    system("cls");

}

void menuGrilles() {

    int ch = -1;


    do {

        system("cls");

        logo();
        printf("                              CHOISISSEZ VOTRE MER...");
        printf("\n\n\n      ");
        printf("                                   1. MER FIXE\n");
        printf("                                   2. AFFICHAGE GRILLE");
        printf("\n\n\n\n");
        if (ch != 49 && ch != -1) {
            printf("                                                           ");
            printf("CETTE MER N'EXISTE PAS !!!");
        }
        if (ch == 49) {
            system("cls");
            printf("\n\ngrille fixe");
        }
        if (ch == 50) {
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
        menu();
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
    menu();
    principal();


    return 0;
}