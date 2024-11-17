#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Ladder[2];
typedef int Snake[2];

// Function Declarations
void initiateLadders(int numLadders, int grid, int occupied[], int *occupiedCount, Ladder arr[]);
void initiateSnakes(int numSnakes, int grid, int occupied[], int *occupiedCount, Snake arr[]);
int searchNumber(int arr[], int size, int num);
int searchNumber2D(int arr[][2], int col, int row, int num);
void shuffleArray(int arr[], int size);

int main() {
    srand(time(0));  // Seed the random number generator once at the beginning of main()

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

    return 0;
}

// Optimized initiateLadders to reduce search time
void initiateLadders(int numLadders, int grid, int occupied[], int *occupiedCount, Ladder arr[]) {
    int availablePositions[grid * grid - 2];
    for (int i = 0, index = 0; i < grid * grid - 2; i++) {
        if (searchNumber(occupied, *occupiedCount, i) == -1) {
            availablePositions[index++] = i;
        }
    }

    shuffleArray(availablePositions, sizeof(availablePositions) / sizeof(availablePositions[0]));

    for (int i = 0; i < numLadders; i++) {
        arr[i][0] = availablePositions[i * 2];
        arr[i][1] = availablePositions[i * 2 + 1];
        occupied[*occupiedCount] = arr[i][0];
        (*occupiedCount)++;
        occupied[*occupiedCount] = arr[i][1];
        (*occupiedCount)++;
    }
}

// Optimized initiateSnakes to reduce search time
void initiateSnakes(int numSnakes, int grid, int occupied[], int *occupiedCount, Snake arr[]) {
    int availablePositions[grid * grid - 2];
    for (int i = 0, index = 0; i < grid * grid - 2; i++) {
        if (searchNumber(occupied, *occupiedCount, i) == -1) {
            availablePositions[index++] = i;
        }
    }

    shuffleArray(availablePositions, sizeof(availablePositions) / sizeof(availablePositions[0]));

    for (int i = 0; i < numSnakes; i++) {
        arr[i][0] = availablePositions[i * 2];
        arr[i][1] = availablePositions[i * 2 + 1];
        occupied[*occupiedCount] = arr[i][0];
        (*occupiedCount)++;
        occupied[*occupiedCount] = arr[i][1];
        (*occupiedCount)++;
    }
}

// Optimized searchNumber for linear search
int searchNumber(int arr[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}

// Search for a number in a 2D array
int searchNumber2D(int arr[][2], int col, int row, int num) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] == num) {
                return i;
            }
        }
    }
    return -1;
}

// Shuffle function to randomize the array
void shuffleArray(int arr[], int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
