#include <stdio.h>

int automaticMode(int r, int c)
{
    //if destination is reached, maze is solved
    //destination is the last cell(maze[SIZE-1][SIZE-1])

    if ((r == TAM - 1) && (c == TAM - 1))
    {
        solucion[r][c] = 1;
        return 1;
    }
    //checking if we can visit in this cell or not
    //the indices of the cell must be in (0,SIZE-1)
    //and solution[r][c] == 0 is making sure that the cell is not already visited
    //maze[r][c] == 0 is making sure that the cell is not blocked
    if (r >= 0 && c >= 0 && r < TAM && c < TAM && solucion[r][c] == 0 && maze[r][c] == 0)
    {
        //if safe to visit then visit the cell
        solucion[r][c] = 1;
        //going down
        if (automaticMode(r + 1, c))
            return 1;
        //going right
        if (automaticMode(r, c + 1))
            return 1;
        //going up
        if (automaticMode(r - 1, c))
            return 1;
        //going left
        if (automaticMode(r, c - 1))
            return 1;
        //backtracking
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
                printPlayerMaze();
                i--;
                cont++;
                contador = &cont;
            }
            else
            {
                printf("There is a wall\n");
                printPlayerMaze();
            }
            break;
        case 'a':
            if (playMaze[i][j - 1] == 0 && j - 1 >= 0)
            {
                playMaze[i][j - 1] = 8;
                playMaze[i][j] = maze[i][j];
                printPlayerMaze();
                j--;
                cont++;
                contador = &cont;
            }
            else
            {
                printf("There is a wall\n");
                printPlayerMaze();
            }
            break;
        case 's':
            if (playMaze[i + 1][j] == 0 && i + 1 >= 0)
            {
                playMaze[i + 1][j] = 8;
                playMaze[i][j] = maze[i][j];
                printPlayerMaze();
                i++;
                cont++;
                contador = &cont;
            }
            else
            {
                printf("There is a wall\n");
                printPlayerMaze();
            }
            break;
        case 'd':
            if (playMaze[i][j + 1] == 0 && j + 1 >= 0)
            {
                playMaze[i][j + 1] = 8;
                playMaze[i][j] = maze[i][j];
                printPlayerMaze();
                j++;
                cont++;
                contador = &cont;
            }
            else
            {
                printf("There is a wall");
                printPlayerMaze();
            }

            break;

        default:
            break;
        }
    }
    printf("Congratulations you finish the maze in %d moves", *contador);
}
