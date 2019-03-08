#include <stdio.h>
#include <conio.h>
#include <windows.h>
void afficher_aide()
        {
      int ch;
            do {system("cls");
                printf("AIDE");
                ch = _getch();

            } while (ch != 27);

        }
int main()
{      int touche;
    do {
        printf("\n"
               "██████╗  █████╗ ████████╗ █████╗ ██╗██╗     ██╗     ███████╗    ███╗   ██╗ █████╗ ██╗   ██╗ █████╗ ██╗     ███████╗\n"
               "██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗██║██║     ██║     ██╔════╝    ████╗  ██║██╔══██╗██║   ██║██╔══██╗██║     ██╔════╝\n"
               "██████╔╝███████║   ██║   ███████║██║██║     ██║     █████╗      ██╔██╗ ██║███████║██║   ██║███████║██║     █████╗  \n"
               "██╔══██╗██╔══██║   ██║   ██╔══██║██║██║     ██║     ██╔══╝      ██║╚██╗██║██╔══██║╚██╗ ██╔╝██╔══██║██║     ██╔══╝  \n"
               "██████╔╝██║  ██║   ██║   ██║  ██║██║███████╗███████╗███████╗    ██║ ╚████║██║  ██║ ╚████╔╝ ██║  ██║███████╗███████╗\n"
               "╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝╚══════╝╚══════╝╚══════╝    ╚═╝  ╚═══╝╚═╝  ╚═╝  ╚═══╝  ╚═╝  ╚═╝╚══════╝╚══════╝\n"
               "                                                                                                                   ");
        printf("ENTER : JOUER     ||      F1 : l'aide     ||     ESCAPE :  quiter \n\n");
        touche = _getch();
        switch (touche)
        {
            case 109:

                break;
            case 59 :
                system("cls");
                afficher_aide();
                break;
            case 13:
                system("cls");
                printf("jouer");
                break;
            case 27:
                return 0;
            default: main();
        }
    } while (touche != 27);



    return 0;
}