#include <stdio.h>
#include <stdlib.h>
#include "ex3.h"
#include "ex2.h"

int main(int args, char const *argv[]) {
    const char businessPath[100] = "files/business.csv";
    const char reviewsPath[100] = "files/reviews.csv";
    const char usersPath[100] = "files/users.csv";

    users *users = readUsers(usersPath);
    reviews *reviews = readReviews(reviewsPath);
    businesss *businesss = readBusiness(businessPath);

    // a
    int reviewsCount = 0;
    for (int i = 0; i < businesss->numBusiness; i++) {
        if (businesss->business[i]->review_count) reviewsCount++;
    }
    printf("%d negócios têm reviews.\n", reviewsCount);

    // b
    int count4stars = 0;
    for (int i = 0; i < businesss->numBusiness; i++) {
        if (businesss->business[i]->stars >= 4) count4stars++;
    }
    printf("%d negócios têm 4 ou + estrelas.\n", count4stars);

    // c
    int max = 0;
    int numBus = 0;
    for (int i = 0; i < businesss->numBusiness - 1; i++) {
        if (businesss->business[i]->review_count > max) {
            max = businesss->business[i]->review_count;
            numBus = i;
        }
    }
    printf("O negócio com mais reviews é o negócio número %d.\n", numBus);

    // h
    for (int i = 0; i < reviews->numReviews; i++) {

    }

    return 0;
}