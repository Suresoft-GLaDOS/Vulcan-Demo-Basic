//
// Created by sure on 2022-09-15.
//
#include <stdio.h>
#include <malloc.h>

struct AccountBook {
    int budget;
    int totalPage;
    int* incomes;
    int* outcomes;
};

void setAccountBook(struct AccountBook* newBook, int totalPage) {
    newBook->incomes = (int*)malloc(sizeof(int) * totalPage);
    newBook->outcomes = (int*)malloc(sizeof(int) * totalPage);
    newVector->budget = 0;
    newVector->cap = default_capacity;
}

int computeBenefit (struct AccountBook myAccount, int wishedMonth) {
    int maxBenefit = 0;
    int accumulated = 0;
    int available = wishedMonth >= 0 ? wishedMonth : myAccount.totalPage; // Umm may I make a fault here?

    for (int i = 0; i < available; i++) {
        accumulated = accumulated + myAccount.incomes[i] - myAccount.outcomes[i];
        if (accumulated > maxBenefit) {
            maxBenefit = accumulated;
        }
    }
    return wishedMonth >= 0 ? accumulated : maxBenefit; // Umm may I make a fault here?
}

int fixPlanMonth (struct AccountBook myAccount, int wishedMonth) {
    int maxBenefit = computeBenefit(myAccount, 0);
    int planBenefit = computeBenefit(myAccount, wishedMonth);

    if (maxBenefit > planBenefit + 10) {

    }
}