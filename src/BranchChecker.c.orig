
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
double* cohenSutherlandClip(int x1, int y1,
                         int x2, int y2, int rectangle0, int rectangle1, int rectangle2, int rectangle3)
{
    double dx1 = x1;
    double dx2 = x2;
    double dy1 = y1;
    double dy2 = y2;

    double dr0 = rectangle0;
    double dr1 = rectangle1;
    double dr2 = rectangle2;
    double dr3 = rectangle3;

    setRectangle(dr0, dr1, dr2, dr3);
    // Compute region codes for P1, P2
    printf("%f %f %f %f\n", x1, y1, x2, y2);
    int code1 = computeCode(dx1, dy1);
    int code2 = computeCode(dx2, dy2);

    printf("code1: %d code2: %d\n", code1, code2);

    double* clippedLine = (double*)malloc(sizeof(double) * 4);

    // Initialize line as outside the rectangular window
    bool accept = false;

    for (int i = 0; i < 8; i++) {

        if ((code1 == 0) && (code2 == 0)) { // && (code2 == 0) Condition add
            // If both endpoints lie within rectangle
            printf("T code1: %d code2: %d\n", code1, code2);
            accept = true;
            break;
        }
        else if (code1 & code2) { //original: code1 & code2
            printf("F code1: %d code2: %d\n", code1, code2);
            // If both endpoints are outside rectangle,
            // in same region
            break;
        }
        else {
            // Some segment of line lies within the
            // rectangle
            int code_out;
            double x, y;

            // At least one endpoint is outside the
            // rectangle, pick it.
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            // Find intersection point;
            // using formulas y = y1 + slope * (x - x1),
            // x = x1 + (1 / slope) * (y - y1)
            if (code_out & TOP) { //original: code_out & TOP
                // point is above the clip rectangle
                x = dx1 + (dx2 - dx1) * (y_max - dy1) / (dy2 - dy1);
                y = y_max;
            }
            else if (code_out & BOTTOM) {
                // point is below the rectangle
                x = dx1 + (dx2 - dx1) * (y_min - dy1) / (dy2 - dy1);
                y = y_min;
            }
            else if (code_out & RIGHT) {
                // point is to the right of rectangle
//                y = (dy2 - dy1) * (x_max - dx1) / (dx2 - dx1) + dy1; //Original
                y = (dy2 - dy1) * (x_max - dx1) / (dx2 - dx1) + dx1;
                x = x_max;
            }
            else if (code_out & LEFT) {
                // point is to the left of rectangle
                y = dy1 + (dy2 - dy1) * (x_min - dx1) / (dx2 - dx1);  // Original
//                y = x1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            // Now intersection point x, y is found
            // We replace point outside rectangle
            // by intersection point
            if (code_out == code1) {
                dx1 = x;
                dy1 = y;
                code1 = computeCode(dx1, dy1);
            }
            else {
                dx2 = x;
                dy2 = y;
                code2 = computeCode(dx2, dy2);
            }
        }
        if (i > 4) {
            clippedLine[0] = 0;
            clippedLine[1] = 0;
            clippedLine[2] = 0;
            clippedLine[3] = 0;
            printf("Line rejected\n");
            return clippedLine;
        }
    }
    clippedLine[0] = dx1;
    clippedLine[1] = dy1;
    clippedLine[2] = dx2;
    clippedLine[3] = dy2;
    if (accept) {
        printf("Line accepted from %f, %f to %f, %f\n", dx1, dy1, dx2, dy2);
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
