#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "src/example.h"
//#include "src/ProductionCode.h"
#include "src/RangeChecker.h"
#include "src/MissedStatements.h"
#include "src/MethodInsertion.h"

#define TEST_SIZE

struct stForTest1 {
    int index;
    int* playList;
    int playN;
    bool random;
};



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

struct stForTest1* initStruct1() {
    struct stForTest1 st1_1 = {.index = 0, .playList = (int*)malloc(sizeof(int) * 5), .playN = 5, .random = false};
//    st1_1.playList = (int[5]){11, 12, 13, 14, 15};
    memcpy(st1_1.playList, (int []){11, 12, 13, 14, 15}, 5 * sizeof st1_1.playList[0]);
    struct stForTest1 st1_2 = {.index = 7, .playList = (int*)malloc(sizeof(int) * 10), .playN = 3, .random = false};
//    st1_2.playList = (int[10]){6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    memcpy(st1_2.playList, (int []){6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, 10 * sizeof st1_2.playList[0]);
    struct stForTest1 st1_3 = {.index = 7, .playList = (int*)malloc(sizeof(int) * 10), .playN = 4, .random = false};
//    st1_3.playList = (int[10]){6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    memcpy(st1_3.playList, (int []){6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, 10 * sizeof st1_3.playList[0]);
    struct stForTest1 st1_4 = {.index = 0, .playList = (int*)malloc(sizeof(int) * 5), .playN = 6, .random = false};
    st1_4.playList = (int[5]){6, 7, 8, 9, 10};
    memcpy(st1_4.playList, (int []){6, 7, 8, 9, 10}, 5 * sizeof st1_4.playList[0]);
    struct stForTest1* input = (struct stForTest1[4]){st1_1, st1_2, st1_3, st1_4};
    return input;
}

int input2[TEST_SIZE][3] = {
   {100, 500},
   {500, 500},
   {600, 550},
   {1000, 500}
 };

int input3[TEST_SIZE][3] = {
   {100, 500},
   {500, 500},
   {600, 550},
   {1000, 500}
 };


 int input4[TEST_SIZE][7] = {
   {4, 12, 3, 7, 2, 11, 14},
   {1, 8, 2, 3, 12, 6, 14},
   {7, 8, 1, 11, 10, 6, 8},
   {10, 7, 2, 12, 9, 11, 6}
 };

 int input4_1[TEST_SIZE] = {
    60,
    40,
    55,
    50
 };

int input4_2[4] = {
    5, 9, 10, 0
};

int input4_3[4] = {
    15, 1, 8, 0
};

int expected_output1[TEST_SIZE][10] = {
    {11, 12, 13, 14, 15},
    {13, 14, 15},
    {13, 14, 15, 6},
    {6, 7, 8, 9, 10, 6}
};

int expected_output2[TEST_SIZE][3] = {
    {0, 100},
    {1, 0},
    {1, 50},
    {2, 0}
};

int expected_output4[TEST_SIZE][15] = {
    {4, 12, 3, 7, 2, 11, 14, 3},
    {1, 8, 2, 3, 12, 6, 3, 3},
    {7, 8, 1, 11, 10, 6, 8},
    {10, 7, 2, 12, 9, 7}
};

int expected_output4_1[TEST_SIZE] = {
    56,
    38,
    51,
    47
 };

 int expected_output4_2[TEST_SIZE][11] = {
    {4, 12, 3, 7, 2, 11, 14, 3, 5, 9, 10},
    {2, 3, 12, 6, 3, 3, 5, 9, 10},
    {7, 11, 10, 6, 5, 9, 10},
    {10, 7, 2, 12, 9, 7, 5, 9, 10}
 };

int main(int argc, char *argv[]) {
    int test_case = atoi(argv[1]);
    int test_index = atoi(argv[2]); //e.q. ./test 2 3
    bool compare = true;

    switch(test_case) {
//        case 1: ;//Range checker
//            struct stForTest1* input1 = initStruct1();
//            printf("%d\n", input1[test_index].index);
//            printf("%d\n", input1[test_index].playN);
//            printf("%d\n", input1[test_index].playList[0]);
//            int index = input1[test_index].index;
//            int playN = input1[test_index].playN;
//            int* actual_output1 = playMany(index, playN, input1[test_index].playList, input1[test_index].random);
//            compare = true;
//            printf("Start: %d\n", input1[test_index].index);
//            printf("N: %d\n", input1[test_index].playN);
//            for (int i = 0; i < playN; i++) {
//                printf("Expected: %d, Actual: %d\n", expected_output1[test_index][i], actual_output1[i]);
//                if (actual_output1[i] != expected_output1[test_index][i]) {
//                    compare = false;
//                    break;
//                }
//            }
//            if (compare) {
//                printf("PASSED\n");
//            }
//            else {
//                printf("FAILED\n");
//            }
//            return compare == true ? 0 : 1;


//        case 2: ;//MissedStatements
//            int* actual_output2 = vendingMachine(input2[test_index][0], input2[test_index][1]);
//            compare = true;
//            printf("coin: %d\n", input2[test_index][0]);
//            printf("price: %d\n", input2[test_index][1]);
//            for (int i = 0; i < 2; i++) {
//                printf("Expected: %d, Actual: %d\n", expected_output2[test_index][i], actual_output2[i]);
//                if (actual_output2[i] != expected_output2[test_index][i]) {
//                    compare = false;
//                    break;
//                }
//            }
//            if (compare) {
//                printf("PASSED\n");
//            }
//            else {
//                printf("FAILED\n");
//            }
//            return compare == true ? 0 : 1;
//        case 3: ;//NullChecker
//            int set = setArray();
//            int* actual_output3 = getIndex(input2[test_index][0], input2[test_index][1]);
//            compare = true;
//            printf("coin: %d\n", input2[test_index][0]);
//            printf("price: %d\n", input2[test_index][1]);
//            for (int i = 0; i < 2; i++) {
//                printf("Expected: %d, Actual: %d\n", expected_output2[test_index][i], actual_output2[i]);
//                if (actual_output2[i] != expected_output2[test_index][i]) {
//                    compare = false;
//                    break;
//                }
//            }
//            if (compare) {
//                printf("PASSED\n");
//            }
//            else {
//                printf("FAILED\n");
//            }
//            return compare == true ? 0 : 1;

        case 4: ;//MethodInsertion
            struct Vector planVector;
            struct Vector* planVectorP = &planVector;
            setVector(planVectorP, 7);
            int* addPlan = (int*)malloc(sizeof(int) * 3);
            int* delPlan = (int*)malloc(sizeof(int) * 3);
            for(int i = 0; i < 7; i++) {
                planVectorP->values[i] = input4[test_index][i];
            }
            for(int i = 0; i < 3; i++) {
                addPlan[i] = input4_2[i];
                delPlan[i] = input4_3[i];
            }
            planVectorP->size = 7;

            int actual_output4 = computeCost(planVectorP, input4_1[test_index]);
            compare = true;


            for (int i = 0; i < planVectorP->size; i++) {
                printf("Expected: %d, Actual: %d\n", expected_output4[test_index][i], planVectorP->values[i]);
                if (planVectorP->values[i] != expected_output4[test_index][i]) {
                    compare = false;
                    break;
                }
            }

            if(actual_output4 != expected_output4_1[test_index]) {
                printf("ExpectedCost: %d, ActualCost: %d\n", expected_output4_1[test_index], actual_output4);
                compare = false;
            }

            int newCost = newTravelPlan(planVectorP, addPlan, delPlan);

            for (int i = 0; i < planVectorP->size; i++) {
                printf("%d, ", planVectorP->values[i]);
            }

            printf("NewCost: %d %d\n", planVectorP->size, newCost);

            if (planVectorP->size==newCost) {
                printf("PASSED\n");
            }
            else {
                printf("FAILED\n");
            }
            return compare == true ? 0 : 1;
    }
    return 0;


}
