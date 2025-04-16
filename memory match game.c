#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 2
#define COLS 4

void printBoard(char *visible) {
    printf("\nBoard:\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf(" %c ", *(visible + i*COLS + j));
        }
        printf("\n");
    }
}

int main() {
    char board[ROWS][COLS] = {
        {'A', 'B', 'C', 'D'},
        {'D', 'C', 'B', 'A'}
    };
    char visible[ROWS][COLS];
    int matches = 0, row1, col1, row2, col2;

    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
            visible[i][j] = '*';

    printf("?? Memory Match Game! Match all pairs to win!\n");

    while(matches < (ROWS * COLS) / 2) {
        printBoard(&visible[0][0]);
        printf("Pick first card (row col): ");
        scanf("%d %d", &row1, &col1);
        printf("Pick second card (row col): ");
        scanf("%d %d", &row2, &col2);

        visible[row1][col1] = board[row1][col1];
        visible[row2][col2] = board[row2][col2];
        printBoard(&visible[0][0]);

        if(board[row1][col1] == board[row2][col2]) {
            printf("?? It's a match!\n");
            matches++;
        } else {
            printf("? Not a match. Try again!\n");
            visible[row1][col1] = '*';
            visible[row2][col2] = '*';
        }
    }

    printf("?? You won the game! All pairs matched!\n");
    return 0;
}

