#include <stdio.h>
#include <stdlib.h>
#include "MissedStatements.h"


int* vendingMachine(int coin, int price) {
    int* result = (int*)malloc(sizeof(int) * 2);
    if(coin<500) {
        printf("insert more\n");
        result[0] = 0;
        result[1] = coin;
        return result;
    }
    else if(coin < price) {
        result[0] = 1;
        result[1] = coin-500;
        return result;
    }
    else if(coin > price) {
        result[0] = (int) coin/price;
        result[1] = coin%price;
        return result;
    }
    else if(coin == price) {
        result[0] = (int) coin/price;
        result[1] = coin%price;
    }

}

int* vendingMachine2(int coin, int price) {
    int* result = (int*)malloc(sizeof(int) * 2);
    if(coin<500) {
        printf("insert more\n");
        result[0] = 0;
        result[1] = coin;
        return result;
    }
    else if(coin < price) {
        result[0] = 1;
        result[1] = coin-500;
        return result;
    }
    else if(coin > price) {
        result[0] = (int) coin/price;
        result[1] = coin%price;
        return result;
    }
    else {
        result[0] = 0;
        result[1] = 0;
        return result;
    }
}