//
// Created by sure on 2022-09-19.
//
#include <stdio.h>
#include <stdlib.h>
#include "3Dimension.h"

int* findDot(int x, int y, int z) {
    int* result = (int*) malloc(sizeof(int)*4);
    for (int i = 0; i < 4; i++) {
        result[i] = -1;
    }
    int curIdx = 0;

    if (x < 0 && (y >= 0 || z >= 0)) {
        result[curIdx] = 0;
        curIdx++;
    }
    if (x >= 0 && y >= 0) { // Original: if (x >= 0 && (y >= 0 || z >= 0))
        result[curIdx] = 1;
        curIdx++;
    }
    if (x >= 0 && y >=0 || z >= 0) {
        result[curIdx] = 2;
        curIdx++;
    }
    if (x < 0 || y >= 0 && z >= 0) {
        result[curIdx] = 3;
        curIdx++;
    }

    return result;
}

