#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex2.h"

businesss* readBusiness(const char *path) {
    FILE *f = fopen(path, "r");
    if (!f) perror("Invalid file path");

    struct businesss *listOfBusiness = malloc(sizeof(struct businesss));
    listOfBusiness->numBusiness = 1;
    listOfBusiness->business = malloc(sizeof(struct business *) * listOfBusiness->numBusiness);

    ssize_t bufferSize = 1024;
    char buffer[bufferSize];
    int count = 0;

    while (fgets(buffer, bufferSize, f)) {
        if (count == listOfBusiness->numBusiness) {
            listOfBusiness->numBusiness*=2;
            listOfBusiness->business= realloc(listOfBusiness->business, sizeof(struct business *) * listOfBusiness->numBusiness);
        }

        struct business *business = (struct business *) malloc(sizeof(struct business));
        char* bufferAux = buffer;
        business->business_id = strdup(strsep(&bufferAux, ";"));
        business->name = strdup(strsep(&bufferAux, ";"));
        business->city = strdup(strsep(&bufferAux, ";"));
        business->stars = atof(strsep(&bufferAux, ";"));
        business->review_count = atoi(strsep(&bufferAux, ";"));
        listOfBusiness->business[count] = business;
        count++;
    }
    listOfBusiness->numBusiness = count;
    return listOfBusiness;
}


reviews* readReviews(const char *path) {
    FILE *f = fopen(path, "r");
    if (!f) perror("Invalid file path");

    reviews *listOfReviews = malloc(sizeof(struct reviews));
    listOfReviews->numReviews = 1;
    listOfReviews->reviews = malloc(sizeof(struct review *) * listOfReviews->numReviews);

    ssize_t bufferSize = 1024;
    char buffer[bufferSize];
    int count = 0;

    while (fgets(buffer, bufferSize, f)) {
        if (count == listOfReviews->numReviews) {
            listOfReviews->numReviews*=2;
            listOfReviews->reviews= realloc(listOfReviews->reviews, sizeof(struct review *) * listOfReviews->numReviews);
        }

        struct review *review = (struct review *) malloc(sizeof(struct review));
        char* bufferAux = buffer;
        review->review_id = strdup(strsep(&bufferAux, ";"));
        review->user_id = strdup(strsep(&bufferAux, ";"));
        review->business_id = strdup(strsep(&bufferAux, ";"));
        review->stars = atof(strsep(&bufferAux, ";"));
        review->useful = atoi(strsep(&bufferAux, ";"));
        review->funny = atoi(strsep(&bufferAux, ";"));
        review->cool = atoi(strsep(&bufferAux, ";"));
        listOfReviews->reviews[count] = review;
        count++;
    }
    listOfReviews->numReviews = count;

    return listOfReviews;
}


users* readUsers(const char *path) {
    FILE *f = fopen(path, "r");
    if (!f) perror("Invalid file path");

    users *listOfUsers = malloc(sizeof(struct users));

    int bufferSize = 1024; // Assume-se que não haverá linhas que tenham mais caracteres do que esta variavel
    char buffer[bufferSize];
    int count = 0;
    listOfUsers->numUsers = 1;
    listOfUsers->id = malloc(sizeof(char *) * listOfUsers->numUsers);

    while (fgets(buffer, bufferSize, f)) {
        if (count == listOfUsers->numUsers) {
            listOfUsers->numUsers *= 2;
            listOfUsers->id = realloc(listOfUsers->id, listOfUsers->numUsers * sizeof (char *));
        }
        listOfUsers->id[count++] = strndup(buffer, ID_SIZE);
    }
    listOfUsers->numUsers = count;

    return listOfUsers;
}