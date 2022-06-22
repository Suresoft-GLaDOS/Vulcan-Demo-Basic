#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "3by3puzzle.h"

#define LEFT      75
#define RIGHT   77
#define UP        72
#define DOWN  80


int get_directionkey() {
    int key;
    key = _getch();
    if (key == 224)     {
        return _getch();
    }
    return 0;
}

void print_puzzle(int puzzle[][3]) {
    int r, c;
    system("cls");
    for (r = 0; r<3; r++) {
        for (c = 0; c<3; c++) {
            if (puzzle[r][c]) {
                printf("%3d", puzzle[r][c]);
            }
            else {
                printf("   ");
            }
        }
        printf("\n");
    }
}


int is_ending(int puzzle[][3]) {
    int r, c;

    for (r = 0; r<3; r++) {
        for (c = 0; c<3; c++) {
            if (puzzle[r][c] != r * 3 + c + 1) {
                return (r == 2) && (c == 2);
            }
        }
    }

    return 0;
}


int playPuzzle(int* arrowArray) {
    int puzzle[3][3] = { { 1,3,2 },{ 7,8,4 },{ 6,5,0 } };
    int row = 2;
    int col = 2;
    int key = 0;

    for (int i = 0; i < 4; i++) {
        print_puzzle(puzzle);
        printf(">> Select Arrow Key \n");
        key = input6[]

        switch (key) {
            case RIGHT:
                if (col>0) {
                    puzzle[row][col] = puzzle[row][col - 1];
                    puzzle[row][col - 1] = 0;
                    col--;
                }

                break;
            case LEFT:
                if (col<3 - 1) {
                    puzzle[row][col] = puzzle[row][col + 1];
                    puzzle[row][col + 1] = 0;
                    col++;
                }
                break;
            case UP:
                if (row<3 - 1) {
                    puzzle[row][col] = puzzle[row + 1][col];
                    puzzle[row + 1][col] = 0;
                    row++;
                }
                break;
            case DOWN:
                if (row>0) {
                    puzzle[row][col] = puzzle[row - 1][col];
                    puzzle[row - 1][col] = 0;
                    row--;
                }
                break;
            }
    }
    return 0;
}