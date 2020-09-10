#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

const char textDecorationStart[] = "---|";
const char textDecorationEnd[] = "|---";
const char gameTitle[] = "Maze Treasure";
const char historyIntroduction[] = "Every 100 years the king open the maze to let only the most braves to take his treasure[Enter]";
const char introQuestion[] = "Are you ready [Y/N]";
const char gameModeQuestion[] = "Which game mode yo want?";
const char gameModeManual[] = "Manual [1]";
const char gameModeAutomatic[] = "Automatic[2]";

int introduction()
{
    char answer;
    char answer2;
    printf("Welcome to \n ");
    printf("%s %s %s \n", textDecorationStart, gameTitle, textDecorationEnd);
    printf("%s \n", historyIntroduction);

    do
    {

        printf("%s \n", introQuestion);
        scanf("%c", &answer);
        answer = tolower(answer);
        if (answer == 'n')
        {
            abort();
        }
    } while (answer != 'y');

    do
    {
        system("cls");
        printf("%s \n", gameModeQuestion);
        printf("%s \n%s \n", gameModeManual, gameModeAutomatic);
        scanf("%c", &answer2);
        if (answer2 == '1')
        {
            return 1;
        }
        if (answer2 == '2')
        {
            return 2;
        }
    } while (answer2 != '1' || answer2 != '2');
}