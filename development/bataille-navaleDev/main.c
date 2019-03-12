#include <stdio.h>
#include <conio.h>
#include <windows.h>

void raccoursis()
{
#define STLC 218 // ┌, Single Top Left Corner
#define STRC 191 // ┐, Single Top Right Corner
#define SBLC 192 // └, Single Bottom Left Corner
#define SBRC 217 // ┘, Single Bottom Right Corner
#define SVSB 179 // │, Single Vertical Simple Border
#define SVRB 180 // ┤, Single Vertical Right Border
#define SVLB 195 // ├, Single Vertical Left Border
#define SHSB 196 // ─, Single Horizontal Simple Border
#define SHBB 193 // ┴, Single Horizontal Bottom Border
#define SHTB 194 // ┬, Single Horizontal Top Border
#define SC   197 // ┼, Single Center
#define DTLC 201 // ╔, Double Top Left Corner
#define DTRC 187 // ╗, Double Top Right Corner
#define DBLC 200 // ╚, Double Bottom Left Corner
#define DBRC 188 // ╝, Double Bottom Right Corner
#define DVSB 186 // ║, Double Vertical Simple Border
#define DVRB 185 // ╣, Double Vertical Right Border
#define DVLB 204 // ╠, Double Vertical Left Border
#define DHSB 205 // ═, Double Horizontal Simple Border
#define DHBB 202 // ╩, Double Horizontal Bottom Border
#define DHTB 203 // ╦, Double Horizontal Top Border
#define DC   206 // ╬, Double Center
}
void logo()
{
    printf("              ____        _        _ _ _        _    _                  _      \n"
           "             |  _ \\     | |      (_) | |      | \\ | |                | |     \n"
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

void grilles()
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
            printf("\n\nFIN grille\n\n");
        }
void afficher_aide()
        {
      int ch;
      raccoursis();
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
            printf("La bataille navale oppose deux joueurs qui s'affrontent. Chacun a une flotte composée de 5 bateaux, qui sont, en général, les suivants : 1 porte-avion (5 cases), 1 croiseur (4 cases), 1 contre-torpilleur (3 cases), 1 sous-marin (3 cases), 1 torpilleur (2 cases). \n"
                   "\n"
                   "Au début du jeu, chaque joueur place ses bateaux sur sa grille. Celle-ci est toujours numérotée de A à J verticalement et de 1 à 10 horizontalement. Un à un, les joueurs vont \"tirer\" sur une case de l'adversaire : par exemple, B.3 ou encore H.8. Le but est donc de couler les bateaux adverses. Au fur et à mesure, il faut mettre les pions sur sa propre grille afin de se souvenir de ses tirs passés.[réf. nécessaire]\n"
                   "\n"
                   "Un fonctionnement plus sophistiqué mettant en œuvre de la stratégie est de tirer une salve (trois coups par exemple) et de donner le résultat global de la salve.");
            do {
                ch = _getch();

            } while (ch != 27);
            printf("\n\nFIN AIDE\n\n");

        }
int main()
{
    #pragma execution_caracter_set("UTF-8")
    SetConsoleOutputCP(65001); // For accented characters
    SetConsoleOutputCP(437); // For semi-graphic characters


    int ch;
    system("color f1");
    int touche;
menu();
     do {

    //printf("\n\nTOUCHE = %d\n\n",touche);
    system("cls");
    menu();
    touche = _getch();
       switch (touche)
        {
            case 59 :
                system("cls");
                printf("\nAIDE\n");
                afficher_aide();
                break;
            case 13:
                system("cls");
                printf("\nGRILLE FIXE\n");
                grilles();
                break;
            case 27:
                break;
            case 0:
                break;
            default: main();
        }
//         printf("%d\n\n", touche);
printf("hello");


    } while (touche != 27);

}