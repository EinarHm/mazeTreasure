// https://www.codesdope.com/blog/article/backtracking-to-solve-a-rat-in-a-maze-c-java-pytho/
// https://gist.github.com/shlomibabluki/4524141

#include <stdio.h>

#define TAM 10

int maze[TAM][TAM] = {
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 1, 1, 1, 0, 1, 0, 1},
    {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 1, 1, 0, 1, 0, 1, 0},
    {0, 0, 1, 1, 1, 0, 1, 0, 1, 0},
    {1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int playMaze[TAM][TAM] = {
    {8, 0, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 1, 1, 1, 0, 1, 0, 1},
    {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 1, 1, 0, 1, 0, 1, 0},
    {0, 0, 1, 1, 1, 0, 1, 0, 1, 0},
    {1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int solucion[TAM][TAM];

void printMaze()
{
    printf("Original Maze: \n");
    int i, j;
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            printf("%d\t", maze[i][j]);
        }
        printf("\n\n");
    }
}

void printPlayerMaze()
{
    int i, j;
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            printf("%d\t", playMaze[i][j]);
        }
        printf("\n\n");
    }
}

void printSolucion()
{
    int i, j, cont = 0;
    int *contador;
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            printf("%d\t", solucion[i][j]);

            if (solucion[i][j] == 1)
            {
                cont++;
                contador = &cont;
            }
        }
        printf("\n\n");
    }

    printf("El numero de movimientos es %d\n", *contador);
}

//function to solve the maze using Backtracking
int solveMaze(int r, int c)
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
        if (solveMaze(r + 1, c))
            return 1;
        //going right
        if (solveMaze(r, c + 1))
            return 1;
        //going up
        if (solveMaze(r - 1, c))
            return 1;
        //going left
        if (solveMaze(r, c - 1))
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
    printf("Congratulations you finish the maze");
}

int main(int argc, char const *argv[])
{
    char answer;
    printf("Press 1 to play manual\n");
    printf("Press 2 to play auto\n");
    scanf("%c", &answer);

    if (answer == '1')
    {
        printf("You can move using W[UP] S[DOWN]  D[RIGHT] A[LEFT] \n");
        manualMode();
    }
    if (answer == '2')
    {
        printf("The maze \n");
        printMaze();
        printf("Solucion: \n");
        if (solveMaze(0, 0))
        {
            printSolucion();
        }
        else
        {
            printf("No solution");
        }

        return 0;
    }
}
