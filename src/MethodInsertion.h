#include <unistd.h>

struct Vector {
    int* values;
    int size;
    int cap;
};


void setVector(struct Vector* newVector, int default_capacity);
void push_back(struct Vector* newVector, int new_value);
void pop_back(struct Vector* newVector);
int computeCost(struct Vector* travelPlan, int budget);
int newTravelPlan(struct Vector* origPlan, int* toAdd, int* toDelete);
