
// C++ program to implement Cohen Sutherland algorithm
// for line clipping.
#include <stdio.h>
#include "BranchChecker.h"

// Defining region codes
const int INSIDE = 0; // 0000
const int LEFT = 1; // 0001
const int RIGHT = 2; // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8; // 1000

// Defining x_max, y_max and x_min, y_min for
// clipping rectangle. Since diagonal points are
// enough to define a rectangle
int x_max;
int y_max;
int x_min;
int y_min;

void setRectangle(int x_M, int y_M, int x_m, int y_m) {
    x_max = x_M;
    x_min = x_m;
    y_max = y_M;
    y_min = y_m;
}

// Function to compute region code for a point(x, y)
int computeCode(double x, double y)
{
    // initialized as being inside
    int code = INSIDE;

    if (x < x_min) { // to the left of rectangle
        printf("L\n");
        code |= LEFT;
    }
    else if (x > x_max) { // to the right of rectangle
        printf("R\n");
        code |= RIGHT;
    }
    if (y < y_min) { // below the rectangle
        printf("B\n");
        code |= BOTTOM;
    }
    else if (y > y_max) { // above the rectangle
        printf("y: %f, y_max: %f\n", y, y_max);
        printf("T\n");
        code |= TOP;
    }

    return code;
}

// Implementing Cohen-Sutherland algorithm
// Clipping a line from P1 = (x2, y2) to P2 = (x2, y2)
double* cohenSutherlandClip(double x1, double y1,
                         double x2, double y2, double* rectangle)
{
    setRectangle(rectangle[0], rectangle[1], rectangle[2], rectangle[3]);
    // Compute region codes for P1, P2
    printf("%f %f %f %f\n", x1, y1, x2, y2);
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    printf("code1: %d code2: %d\n", code1, code2);

    double* clippedLine = (double*)malloc(sizeof(double) * 4);

    // Initialize line as outside the rectangular window
    bool accept = false;

    for (int i = 0; i < 4; i++) {

        if (((code1 == 0)) && !(code2 != 0)) {
            printf("T code1: %d code2: %d\n", code1, code2);
    accept = 1;
            break;
} else if (code1 & code2) {
            printf("F code1: %d code2: %d\n", code1, code2);
            break;
} else {
            int code_out;
            double x, y;
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;
    if (code_out & TOP) {
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
    } else if (code_out & BOTTOM) {
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
    } else if (code_out & RIGHT) {
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
    } else if (code_out & LEFT) {
                y = (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }
            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
    } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    clippedLine[0] = x1;
    clippedLine[1] = y1;
    clippedLine[2] = x2;
    clippedLine[3] = y2;
    if (accept) {
        printf("Line accepted from %f, %f to %f, %f\n", x1, y1, x2, y2);
        // Here the user can add code to display the rectangle
        // along with the accepted (portion of) lines
    }
    else {
        clippedLine[0] = 0;
        clippedLine[1] = 0;
        clippedLine[2] = 0;
        clippedLine[3] = 0;
        printf("Line rejected\n");
    }


    return clippedLine;
}

// Driver code
//int main()
//{
//    // First Line segment
//    // P11 = (5, 5), P12 = (7, 7)
//    cohenSutherlandClip(5, 5, 7, 7);
//
//    // Second Line segment
//    // P21 = (7, 9), P22 = (11, 4)
//    cohenSutherlandClip(7, 9, 11, 4);
//
//    // Third Line segment
//    // P31 = (1, 5), P32 = (4, 1)
//    cohenSutherlandClip(1, 5, 4, 1);
//
//    return 0;
//}