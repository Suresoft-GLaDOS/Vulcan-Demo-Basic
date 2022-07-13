#include <stdio.h>
#include <stdlib.h>
#include "src/example.h"
//#include "src/ProductionCode.h"
#include "src/RangeChecker.h"
#include "src/MissedStatements.h"
#include "src/MethodInsertion.h"
#include "src/BranchChecker.h"
#include "src/BranchChecker_avl.h"

#define TEST_SIZE

#ifdef GCOV
#include <signal.h>
static struct sigaction dpp_gcov_sigaction;
static struct sigaction dpp_orig_sigaction;
void dpp_sighandler(int signum) {
	__gcov_flush();
	sigaction(sigaction, &dpp_orig_sigaction, NULL);
	raise(signum);
	exit(1);
}
#endif
void __asan_on_error(void) {
#ifdef GCOV
    __gcov_flush();
#endif
}



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

//double input5[TEST_SIZE][4] = {
//    {10, 8, 4, 4},
//    {10, 8, 4, 4},
////    {10, 8, 4, 4},
//    {9, 9, 5, 5},
//    {9, 9, 5, 5}
//};
//
//
//double input5_1[TEST_SIZE][4] = {
//    {5.0, 5.0, 7.0, 7.0},
//    {7, 9, 11, 4},
////    {1, 5, 4, 1},
//    {4, 12, 8, 8},
//    {5, 8, 10, 3}
//};

int input6_1[TEST_SIZE][11] = {
    {4, 10, 13, 20, 25, 32, 55, 20, 25, 32, 55},
    {3, 8, 11, 6, 8, 10, 30, 6, 8, 10, 30},
    {7, 6, 5, 4, 3, 2, 1, 4, 3, 2, 1},
    {20, 200, 5, 2, 3, 25, 5, 2, 3, 25, 5},
    {7, 6, 5, 4, 3, 2, 1, 4, 3, 2, 1},
    {20, 200, 5, 2, 3, 25, 5, 2, 3, 25, 5},
    {8, -24, -29, 60, -18, 20, 24, -13, -10, -26, 15 },
    {38, 6, 1, 90, 12, 50, 54, 17, 20, 4, 45 },
};

int input6_2[TEST_SIZE][3] = {
    {4, 10, 13},
    {3, 11, 10},
    {8, 6, 5},
    {5, 3, 5},
    {0, 0, 0},
    {0, 0, 25},
    {-13, -19, -26},
    {17, 11, 4}
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

double expected_output5[TEST_SIZE][4] = {
    {5, 5, 7, 7},

//    {0, 0, 0, 0},
    {7, 9, 8, 8},
    {5, 8, 8, 5},
    {7.8, 8.0, 10.0, 5.25}
 };

int expected_output6[TEST_SIZE][11] = {
    {20, 25, 32, 55},
    {6, 8, 30},
    {1, 2, 3, 4, 7},
    {2, 20, 25, 200},
    {1, 2, 3, 4, 5, 6, 7},
    {2, 3, 5, 20, 200},
    {-29, -24, -18, -10, 8, 15, 20, 24, 60},
    {1, 6, 12, 20, 38, 45, 50, 54, 90}
};



int main(int argc, char *argv[]) {
#ifdef GCOV
	  {
		  dpp_gcov_sigaction.sa_handler = dpp_sighandler;
		  sigemptyset(&dpp_gcov_sigaction.sa_mask);
		  dpp_gcov_sigaction.sa_flags = 0;
		  sigaction(SIGSEGV, &dpp_gcov_sigaction, &dpp_orig_sigaction);
		  sigaction(SIGFPE, &dpp_gcov_sigaction, &dpp_orig_sigaction);
		  sigaction(SIGABRT, &dpp_gcov_sigaction, &dpp_orig_sigaction);
	  }
#endif
    int test_case = atoi(argv[1]);
    int test_index = atoi(argv[2]); //e.q. ./test 2 3
    bool compare = true;

    switch(test_case) {


    }
    return 0;


}
