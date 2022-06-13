#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

static int data_size = 5000000;
static unsigned *int_data;


int setArray(int* array) {
    if (array != NULL) {
        array = malloc(N * sizeof(int));
        return 0;
    }
    else {
        return -1;
    }
}

int getIndex(int* array, int value) {
    for (int i = 0; i < N; ++i) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

