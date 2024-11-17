#include <stdbool.h>
#include <stdio.h>

void multiplayer(int players);

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
    printf("Ceritanya anda bermain nichhh dengan %d player", players);
}