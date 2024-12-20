#include "game.c"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void multiplayer(int players);
int setDifficulty();

int main() {
  printf("\n");
  printf("---------------------\n");
  printf("Snakes and Ladders !!\n");
  printf("---------------------\n");
  printf("\n");
  bool isRunning = true;
  while (isRunning) {
    printf("Menu:\n");
    printf("1. Main multiplayer\n");
    printf("2. Exit\n");
    printf("Pilih menu (1/2): ");
    int menuPicked;
    scanf("%d", &menuPicked);
    getchar();
    switch (menuPicked) {
    case 1:
      printf("\n");
      printf("Banyak player (1 sampai 4): ");
      int players;
      scanf("%d", &players);
      printf("\n");
      multiplayer(players);
      break;
    case 2:
      printf("\n");
      printf("bai baii\n");
      printf("\n");
      isRunning = false;
      break;
    default:
      printf("\n");
      printf("Pilihan menu tidak ada\n");
      printf("\n");
    }
  }
  return 0;
}

void multiplayer(int players) {
  // printf("Ceritanya anda bermain nichhh dengan %d player", players);
  char colors[4][7] = {"\033[31m", "\033[34m", "\033[32m", "\033[33m"};
  Player playerArray[players];
  initiatePlayers(playerArray, players);
  printPlayers(playerArray, players, colors, 4);
  int difficulty = setDifficulty();
  int ladderCount, snakeCount;
  getLadderSnakeCount(&ladderCount, &snakeCount, difficulty);
  Snake S[snakeCount];
  Ladder L[ladderCount];
  initiateBoard(snakeCount, ladderCount, S, L);
  bool isRunning = true;
  int grid = 10;
  while (isRunning) {
    for (int i = 0; i < players; i++) {
      system("clear");
      printf("Keterangan: ▲ = Tangga, ▼ = Ular");
      printBoard(S, L, playerArray, snakeCount, ladderCount, players, grid);
      int temp;
      getchar();
      printf("Giliran Player %d\n", i+1);
      printf("Tekan angka 1 untuk mengocok dadu\n");
      scanf("%d", &temp);

      move(rollDice(), &playerArray[i], grid);
    }
  }
}

int setDifficulty() {
  printf("1. Easy\n2. Normal\n3. Hard\n");
  int selected;
  getchar();
  printf("Pilih Difficulty (1/2/3)");
  scanf("%d", &selected);
  while ((selected != 1) && (selected != 2) && (selected != 3)) {
    printf("Difficulty tidak ada");
    scanf("%d", &selected);
  }
  return selected;
}