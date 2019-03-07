#include <stdio.h>
#include <conio.h>
void afficher_aide()
        {
            int touche;
            do {
                touche = _getch();

                printf("%d\n", touche);      // print numeric key value
            } while (touche != 59);          // end when Esc pressed
        }
int main()
{
    afficher_aide();


    return 0;
}