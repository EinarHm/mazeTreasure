#include <stdio.h>
#include "print.h"
#include "intro.h"
#include "gameMode.h"

int main(int argc, char const *argv[])
{
    system("cls");
    int answer;
    answer = introduction();

    if (answer == 1)
    {
        //printf("You can move using W[UP] S[DOWN]  D[RIGHT] A[LEFT] \n");
        //system("cls");
        manualMode();
    }
    else if (answer == 2)
    {
        printf("The maze \n");
        printMaze();
        printf("Solucion: \n");
        if (automaticMode(0, 0))
        {
            printSolucion();
        }
        else
        {
            printf("No solution");
        }

        return 0;
    }
    else
    {
        return 0;
    }
}
