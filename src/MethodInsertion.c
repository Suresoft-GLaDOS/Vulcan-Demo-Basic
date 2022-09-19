#include <stdio.h>
#include <malloc.h>

#include "MethodInsertion.h"



void setVector(struct Vector* newVector, int default_capacity) {
    newVector->values = (int*)malloc(sizeof(int) * default_capacity);
    newVector->size = 0;
    newVector->cap = default_capacity;
}

void push_back(struct Vector* newVector, int new_value) {
//    printf("push 3\n");
    if(newVector->size == newVector->cap) {
        int* temp = (int*)malloc(sizeof(int) * newVector->cap * 2);
        for (int i = 0; i < newVector->cap; i++) {
            temp[i] = newVector->values[i];
        }
        free(newVector->values);
        newVector->values = temp;
        newVector->cap *= 2;
    }
    newVector->values[newVector->size] = new_value;
    newVector->size = newVector->size + 1;
}

//void increaseSize(struct Vector* newVector, int add) {
//    if(newVector->size + add >= newVector->cap) {
//        int* temp = (int*)malloc(sizeof(int) * default_capacity * 2);
//        for (int i = 0; i < newVector->cap) {
//            temp[i] = newVector->values[i];
//        }
//        free(newVector->values);
//        newVector->values = temp;
//        newVector->cap *= 2;
//    }
//    newVector->size = newVector->size + add;
//}

void pop_back(struct Vector* newVector) {
    if(newVector) {
        newVector->values[newVector->size-1] = -1;
        newVector->size = newVector->size -1;
    }
}

void decreaseSize(struct Vector* newVector, int remove) {
    newVector->size = newVector->size - remove;
}

int newTravelPlan(struct Vector* origPlan, int* toAdd, int* toDelete) {
    int newCost = 0;
    int newSize = origPlan->size;

//    for (int i = 0; i < origPlan->size; i++) {
//        printf("origPlan: %d\n", origPlan->values[i]);
//    }

    for (int i = 0; i < 3; i++) {
        push_back(origPlan, toAdd[i]);
//        increaseSize(origPlan, 1);
    }
    newSize = newSize + 3;
    for (int i = 0; i < origPlan->size; i++) {
        while(1){
            int delFlag = 0;
            for (int j = 0; j < 3; j++) {
                if (origPlan->values[i] == toDelete[j]) {
                    delFlag = 1;
                    for (int k = i; k < origPlan->size; k++) {
                        origPlan->values[k] = origPlan->values[k+1];

                    }
                    pop_back(origPlan);
                    newSize--;
//                    break; //it can be another fault example
                }
            }
            if(delFlag == 0) {
                break;
            }
        }

    }
//    for (int i = 0; i < origPlan->size; i++) {
//        if (origPlan->values[i]) {
//            push_back(newPlan, origPlan->values[i]);
////            increaseSize(newPlan, 1);
//        }
//    }
    for(int i = 0; i < newSize; i++) {
        newCost = newCost + origPlan->values[i];
    }

    return newSize;
}

int computeCost(struct Vector* travelPlan, int budget) {
    int cost = 0;
    for (int i = 0; i < travelPlan->size; i++) {
        cost = cost + travelPlan->values[i];
    }

    while (cost > budget) {
        cost = cost - travelPlan->values[travelPlan->size-1];
//        pop_back(travelPlan);
        printf("budget: %d  cost: %d\n", budget, cost);
    }



    while (cost <= budget - 5) {
        if (budget >= cost + 10) {
            cost = cost + 7;
            push_back(travelPlan, 7);
    //        increaseSize(travelPlan, 1);
        }
        else if (budget >= cost + 5) {
            cost = cost + 3;
            push_back(travelPlan, 3);
            printf("add 3\n");
    //        increaseSize(travelPlan, 1);
        }

    }


    return cost;
}

void rePlanning(struct Vector* travelPlan, int* addPlan, int* deletePlan) {

}