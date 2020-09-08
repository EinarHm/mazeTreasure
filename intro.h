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

int introduction(void)
{
    char answer;
    printf("Welcome to ");
    printf("%s,%s %s \n", textDecorationStart, gameTitle, textDecorationEnd);
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

        printf("%s", gameModeQuestion);
        printf("%s \n %s \n", gameModeManual, gameModeAutomatic);
        scanf("%c", &answer);
        if (answer == '1')
        {
            return 1;
        }
        if (answer = '2')
        {
            return 2;
        }

    } while (answer != '1' || answer != '2');
}