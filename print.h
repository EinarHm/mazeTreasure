#include <stdio.h>
#include "maze.h"

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