// https://www.codesdope.com/blog/article/backtracking-to-solve-a-rat-in-a-maze-c-java-pytho/
// https://gist.github.com/shlomibabluki/4524141

#include <stdio.h>

#define TAM 5

int maze[TAM][TAM] = {
    {0, 1, 0, 1, 1},
    {0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1},
    {0, 0, 1, 0, 0},
    {1, 0, 0, 1, 0}};

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

void printSolucion()
{
    int i, j /*, count*/;
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            printf("%d\t", solucion[i][j]);
            // count++;
        }
        printf("\n\n");
    }

    // printf("%d", count);
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

int main(int argc, char const *argv[])
{
    printMaze();

    printf("Solucion: \n");
    int i, j;
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            solucion[i][j] = 0;
        }
    }

    if (solveMaze(0, 0))
    {
        printSolucion();
    }
    else
    {
        printf("No hay solucion");
    }

    return 0;
}
