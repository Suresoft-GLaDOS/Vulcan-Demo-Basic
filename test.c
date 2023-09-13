#include <stdio.h>
#include <stdlib.h>
#include "example.h"

#define TEST_SIZE

int input[TEST_SIZE][2] = {
  {10, 10},
  {20, 20},
  {13, 13},
  {14, 14}
};

int expected_output[TEST_SIZE] = {
  1, 0, 0, 0
};

int main(int argc, char *argv[]) {
    int test_index = atoi(argv[1]);
    int actual_output = function(input[test_index][0], input[test_index][1]);
    printf("actual %d, expected %d\n", actual_output, expected_output[test_index]);
    if (actual_output == expected_output[test_index]) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }
    return actual_output == expected_output[test_index] ? 0 : 1;
}