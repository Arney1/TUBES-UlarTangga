#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <stdlib.h>

typedef int Ladder[2];
typedef int Snake[2];

void initiateLadders(int numLadders, int grid, int occupied[],
                     int *occupiedCount, Ladder arr[]);
void initiateSnakes(int numSnakes, int grid, int occupied[], int *occupiedCount,
                    Snake arr[]);
int searchNumber(int arr[], int size, int num);
int searchNumber2D(int arr[][2], int col, int row, int num);

int main() {
  srand(time(0));
  int n;
  printf("berapa kali berapa: ");
  scanf("%d", &n);
  int ladderCount = 5;
  int snakeCount = 5;
  int occupied[(ladderCount + snakeCount) * 2];
  int occupiedCount = 0;
  Snake S[snakeCount];
  Ladder L[ladderCount];
  initiateLadders(ladderCount, n, occupied, &occupiedCount, L);
  initiateSnakes(snakeCount, n, occupied, &occupiedCount, S);
  //   Ladder L[ladderCount];
  //   for (int i = 0; i < ladderCount; i++) {
  //     scanf("%d %d", &L[i][0], &L[i][1]);
  //   }

  int gridNum = n * n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("---------");
    }
    printf("\n");
    for (int j = 0; j < n; j++) {
      int sum;
      if (i % 2 == 0) {
        sum = gridNum - j;
      } else {
        sum = gridNum - n + 1 + j;
      }

      int ladderNum = searchNumber2D(L, 2, ladderCount, sum);
      int snakeNum = searchNumber2D(S, 2, snakeCount, sum);
      if (ladderNum != -1) {
        printf("▲%d      |", ladderNum + 1);
      } else if (snakeNum != -1) {
        printf("▼%d      |", snakeNum + 1);
      } else {
        printf("        |");
      }
    }
    printf("\n");
    for (int j = 0; j < n; j++) {
      printf("        |");
    }
    printf("\n");
    for (int j = 0; j < n; j++) {
      int sum;
      if (i % 2 == 0) {
        sum = gridNum - j;
      } else {
        sum = gridNum - n + 1 + j;
      }

      if (sum > 99) {
        printf("%d     |", sum);
      } else if (sum > 9) {
        printf("%d      |", sum);
      } else {
        printf("%d       |", sum);
      }
    }

    printf("\n");
    gridNum -= n;
  }
  for (int j = 0; j < n; j++) {
    printf("---------");
  }
  printf("\n");
}

void initiateLadders(int numLadders, int grid, int occupied[],
                     int *occupiedCount, Ladder arr[]) {
  for (int i = 0; i < numLadders; i++) {
    int j = 0;
    while (j < 2) {
      int max = grid * grid - 1;
      int min = 2;
      int block = rand() % (max - min + 1) + min;
      if (searchNumber(occupied, *occupiedCount, block) == -1) {
        arr[i][j] = block;
        occupied[*occupiedCount] = block;
        (*occupiedCount)++;
        j++;
      }
    }
  }
}

int searchNumber(int arr[], int size, int num) {
  for (int i = 0; i < size; i++) {
    if (num == arr[i]) {
      return i;
    }
  }
  return -1;
}

int searchNumber2D(int arr[][2], int col, int row, int num) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (num == arr[i][j]) {
        return i;
      }
    }
  }
  return -1;
}

void initiateSnakes(int numSnakes, int grid, int occupied[], int *occupiedCount,
                    Snake arr[]) {
  for (int i = 0; i < numSnakes; i++) {
    int j = 0;
    while (j < 2) {
      int max = grid * grid - 1;
      int min = 2;
      int block = rand() % (max - min + 1) + min;
      if (searchNumber(occupied, *occupiedCount, block) == -1) {
        arr[i][j] = block;
        occupied[*occupiedCount] = block;
        (*occupiedCount)++;
        j++;
      }
    }
  }
}