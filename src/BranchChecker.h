#include <stdbool.h>

int computeCode(double x, double y);
void setRectangle(int x_M, int y_M, int x_m, int y_m);
double* cohenSutherlandClip(int x1, int y1, int x2, int y2, int rectangle0, int rectangle1, int rectangle2, int rectangle3);