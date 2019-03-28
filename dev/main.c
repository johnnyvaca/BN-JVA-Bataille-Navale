// Auteur : Johnny Vaca
// Date   : 7 mars 2019
// Descriptions : Bataille Navale
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define TAB_SIZE 10



void raccourcis(){


#define DTLC 201 // +, Double Top Left Corner
#define DTRC 187 // +, Double Top Right Corner
#define DBLC 200 // +, Double Bottom Left Corner
#define DBRC 188 // +, Double Bottom Right Corner
#define DVSB 186 // �, Double Vertical Simple Border
#define DVRB 185 // �, Double Vertical Right Border
#define DVLB 204 // �, Double Vertical Left Border
#define DHSB 205 // -, Double Horizontal Simple Border
#define DHBB 202 // -, Double Horizontal Bottom Border
#define DHTB 203 // -, Double Horizontal Top Border
#define DC   206 // +, Double Center
#define BLEU  17 //, BLEU SUR BLEU
#define BLEU_BLANC  241 //, BLEU SUR BLANC
#define BLANC  255 //, BLANC SUR BLANC
#define NOIR  0 //, NOIR
#define ROUGE  68 //, ROUGE

};

int grilleFixe[TAB_SIZE][TAB_SIZE] = {
        {1,0,0,0,0,0,0,0,0,1},
        {2,0,5,5,5,5,5,0,0,3},
        {2,0,0,0,0,0,0,0,0,3},
        {0,0,3,0,0,0,0,0,0,3},
        {0,0,3,0,1,1,0,0,0,0},
        {0,0,3,0,1,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,4,4,4,4},
        {0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,0,1}
};
void body()
{

    for (int j = 0; j < TAB_SIZE; ++j) {

        for (int i = 0; i < TAB_SIZE ; ++i) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BLEU_BLANC );

            if(i == 0)
            {
                if(j >=9)
                {
                    printf("%d",j+1);
                } else
                {
                    printf(" %d",j+1);
                }


            }
            if(i == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BLEU_BLANC );
                printf("    ");
            }
            printf("%c",DVSB);


            printf(" %d  ", grilleFixe[j][i]);








        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BLEU_BLANC );
        printf("%c",DVSB);
        printf("\n");
        if(j != TAB_SIZE-1)
        {
            for (int i = 0; i < TAB_SIZE ; ++i) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BLEU_BLANC);
                if(i == 0)
                {
                    printf("      %c",DVLB);
                }
                else
                {
                    printf("%c",DC);
                }
                printf("%c%c%c%c",DHSB,DHSB,DHSB,DHSB);
                if(i == TAB_SIZE-1)
                {
                    printf("%c",DVRB);
                }
            }
            printf("\n");
        }

    }

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
void top()
{
#pragma execution_caracter_set("UTF-8")
    SetConsoleOutputCP(65001); // For accented characters
    SetConsoleOutputCP(437); // For semi-graphic characters
    for (int i = 0; i < TAB_SIZE; ++i) {
        if(i == 0)
        {
            printf("        %c  ",i+'A');
        }
        else
        {
            printf("  %c  ",'A'+i);
        }

    }
    printf("\n");
    printf("      %c",DTLC);
    for (int i = 0; i < TAB_SIZE -1; ++i) {
        printf("%c%c%c%c%c",DHSB,DHSB,DHSB,DHSB,DHTB);
    }
    printf("%c%c%c%c%c",DHSB,DHSB,DHSB,DHSB,DTRC);
    printf("\n");

}

void bottom()
{

    SetConsoleOutputCP(65001); // For accented characters
    SetConsoleOutputCP(437); // For semi-graphic characters

    printf("      %c",DBLC);
    for (int i = 0; i < TAB_SIZE -1; ++i) {
        printf("%c%c%c%c%c",DHSB,DHSB,DHSB,DHSB,DHBB);
    }
    printf("%c%c%c%c%c",DHSB,DHSB,DHSB,DHSB,DBRC);
}
void affichageGrille() {

    raccourcis();
    int ch;
    top();
    body();
    bottom();

    do {
        //system("cls");

        //printf("\n\n\n%d",ch);
        ch = _getch();
    } while (ch != 27);
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
        if (ch != 49 && ch != -1 ) {
            printf("                                                           ");
            printf("CETTE MER N'EXISTE PAS !!!");
        }
        if (ch == 49) {
            system("cls");
            printf("\n\ngrille fixe");
        }
        if(ch == 50)
        {
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
    printf("La bataille navale oppose deux joueurs qui s'affrontent. Chacun a une flotte compos�e de 5 bateaux, qui sont, en g�n�ral, les suivants : 1 porte-avion (5 cases), 1 croiseur (4 cases), 1 contre-torpilleur (3 cases), 1 sous-marin (3 cases), 1 torpilleur (2 cases). \n"
           "\n"
           "Au d�but du jeu, chaque joueur place ses bateaux sur sa grille. Celle-ci est toujours num�rot�e de A � J verticalement et de 1 � 10 horizontalement. Un � un, les joueurs vont \"tirer\" sur une case de l'adversaire : par exemple, B.3 ou encore H.8. Le but est donc de couler les bateaux adverses. Au fur et � mesure, il faut mettre les pions sur sa propre grille afin de se souvenir de ses tirs pass�s.[r�f. n�cessaire]\n"
           "\n"
           "Un fonctionnement plus sophistiqu� mettant en �uvre de la strat�gie est de tirer une salve (trois coups par exemple) et de donner le r�sultat global de la salve.");
    printf("\n\n\n\n");
    printf("                                                                                                                                       ESCAPE:   POUR RETOURNER EN ARRIERE");
    do {
        ch = _getch();

    } while (ch != 27);
}
int principal(){
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
            default: principal();
        }

    } while (touche != 27 );

    return 0;
}
int main() {



#pragma execution_caracter_set("UTF-8")
    SetConsoleOutputCP(CP_UTF8); // For accented characters

    keybd_event(VK_F11,0,0,0); //Appuie sur ALT
    keybd_event(VK_F11,0,KEYEVENTF_KEYUP,0); // Relache ENTREE

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BLEU_BLANC );
    menu();
    principal();




    return 0;
}