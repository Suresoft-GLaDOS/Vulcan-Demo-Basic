#include <stdio.h>
#include <stdlib.h>
#include "src/example.h"
#include "src/ProductionCode.h"

#define TEST_SIZE

// int input[TEST_SIZE][4] = {
//   {3, 3, 5},
//   {1, 2, 3},
//   {3, 2, 1},
//   {5, 5, 5},
//   {5, 3, 4},
//   {2, 1, 3},
//   {4, 4, 3},
// };

int input[TEST_SIZE][4] = {
  {78},
  {2},
  {33},
  {999},
  {-1},
  {34},
  {8888},
};

// int expected_output[TEST_SIZE] = {
//   3, 2, 2, 5, 4, 2, 4
// };

int expected_output[TEST_SIZE] = {
  0, 0, 0, 0, 0, 1, 8
};

// int main(int argc, char *argv[]) {
//     int test_index = atoi(argv[1]);
//     int actual_output = mid(input[test_index][0], input[test_index][1], input[test_index][2]);
//     printf("actual %d, expected %d\n", actual_output, expected_output[test_index]);
//     if (actual_output == expected_output[test_index]) {
//         printf("PASSED\n");
//     } else {
//         printf("FAILED\n");
//     }
//     return actual_output == expected_output[test_index] ? 0 : 1;
// }

int main(int argc, char *argv[]) {
    int test_index = atoi(argv[1]);
    int actual_output = FindFunction_WhichIsBroken(input[test_index][0]);
    printf("actual %d, expected %d\n", actual_output, expected_output[test_index]);
    if (actual_output == expected_output[test_index]) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }
    return actual_output == expected_output[test_index] ? 0 : 1;
}
