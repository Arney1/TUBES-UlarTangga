// #include <stdio.h>
#include <stdlib.h>
#include "board.c"
void move(int n, Player player);
int rollDice();
int checkLadderSnake(Player playerArray[], int playerNum, Ladder L[], Snake S[]);

int rollDice() {
    int min = 1;
    int max = 6;
    return (rand() % (max - min + 1) + min);
}

void move(int n, Player player) {
    player.position += n;
}