#include <stdio.h>
#include <stdlib.h>
#include "RangeChecker.h"

int* playMany(int startIndex, int N, int* playList, bool random) {
    int* result = (int*)malloc(sizeof(int) * N);
    int index = startIndex;
    result[0] = playList[index];
    printf("%d ", result[0]);
    for (int i = 1; i < N; i++) {
        result[i] = playList[playNext(index, playList, random)];
        printf("%d ", result[i]);
        index++;
    }
    printf("\n");
    return result;
}

int playNext(int index, int* playList, bool random) {
    if (random) {
        int randomIndex = rand()/(sizeof(playList)/sizeof(int));
        return randomIndex;
    }
    else {
//        printf("index: %d\n", index+1);
        return index+1;
    }
}