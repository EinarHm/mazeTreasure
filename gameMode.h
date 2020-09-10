#include <stdio.h>

int automaticMode(int r, int c)
{
    if ((r == TAM - 1) && (c == TAM - 1))
    {
        solucion[r][c] = 1;
        return 1;
    }
    if (r >= 0 && c >= 0 && r < TAM && c < TAM && solucion[r][c] == 0 && maze[r][c] == 0)
    {
        solucion[r][c] = 1;
        if (automaticMode(r + 1, c))
            return 1;

        if (automaticMode(r, c + 1))
            return 1;

        if (automaticMode(r - 1, c))
            return 1;

        if (automaticMode(r, c - 1))
            return 1;

        solucion[r][c] = 0;
        return 0;
    }
    return 0;
}
void manualMode()
{
    int i = 0;
    int j = 0;
    char move;
    int *contador;
    int cont = 0;
    printf("You can move using W[UP] S[DOWN]  D[RIGHT] A[LEFT] \n");
    printPlayerMaze();

    while (playMaze[9][9] != 8)
    {
        scanf("%c", &move);

        switch (move)
        {
        case 'w':
            if (playMaze[i - 1][j] == 0 && i - 1 >= 0)
            {
                playMaze[i - 1][j] = 8;
                playMaze[i][j] = maze[i][j];
                system("cls");
                printPlayerMaze();
                i--;
                cont++;
                contador = &cont;
            }
            else
            {
                system("cls");
                printPlayerMaze();
                printf("There is a wall\n");
            }
            break;
        case 'a':
            if (playMaze[i][j - 1] == 0 && j - 1 >= 0)
            {
                playMaze[i][j - 1] = 8;
                playMaze[i][j] = maze[i][j];
                system("cls");
                printPlayerMaze();
                j--;
                cont++;
                contador = &cont;
            }
            else
            {
                system("cls");
                printPlayerMaze();
                printf("There is a wall\n");
            }
            break;
        case 's':
            if (playMaze[i + 1][j] == 0 && i + 1 >= 0)
            {
                playMaze[i + 1][j] = 8;
                playMaze[i][j] = maze[i][j];
                system("cls");
                printPlayerMaze();
                i++;
                cont++;
                contador = &cont;
            }
            else
            {
                system("cls");
                printPlayerMaze();
                printf("There is a wall\n");
            }
            break;
        case 'd':
            if (playMaze[i][j + 1] == 0 && j + 1 >= 0)
            {
                playMaze[i][j + 1] = 8;
                playMaze[i][j] = maze[i][j];
                system("cls");
                printPlayerMaze();
                j++;
                cont++;
                contador = &cont;
            }
            else
            {
                system("cls");
                printPlayerMaze();
                printf("There is a wall");
            }

            break;

        default:
            break;
        }
    }
    printf("Congratulations you finish the maze in %d moves", *contador);
}
