
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int position[2] = {0, 0};
    int snakes[101] = {0};
    int ladders[101] = {0};
    int player = 0, dice;
    char enter;

    srand(time(NULL));

    ladders[4] = 14;
    ladders[9] = 31;
    ladders[20] = 38;
    ladders[28] = 84;
    ladders[40] = 59;
    ladders[63] = 81;
    ladders[71] = 91;

    snakes[17] = 7;
    snakes[54] = 34;
    snakes[62] = 19;
    snakes[64] = 60;
    snakes[87] = 24;
    snakes[93] = 73;
    snakes[95] = 75;
    snakes[99] = 78;

    printf("================================\n");
    printf("       SNAKE AND LADDER GAME\n");
    printf("================================\n");

    while (1) {
        printf("\nPlayer %d's Turn", player + 1);
        printf("\nPress Enter to Roll Dice...");
        getchar();

        dice = rand() % 6 + 1;
        printf("Dice Rolled: %d\n", dice);

        if (position[player] + dice <= 100) {
            position[player] += dice;

            printf("Moved to Position %d\n", position[player]);

            if (ladders[position[player]] != 0) {
                printf("Ladder! Climb Up to %d\n",
                       ladders[position[player]]);
                position[player] = ladders[position[player]];
            }

            if (snakes[position[player]] != 0) {
                printf("Snake Bite! Slide Down to %d\n",
                       snakes[position[player]]);
                position[player] = snakes[position[player]];
            }
        } else {
            printf("Need exact number to reach 100!\n");
        }

        printf("\nPlayer 1 Position: %d\n", position[0]);
        printf("Player 2 Position: %d\n", position[1]);

        if (position[player] == 100) {
            printf("\n============================\n");
            printf("PLAYER %d WINS THE GAME!\n", player + 1);
            printf("============================\n");
            break;
        }

        player = 1 - player;
    }

    printf("\nThank you for playing!\n");

    return 0;
}
