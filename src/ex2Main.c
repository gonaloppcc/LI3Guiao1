#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex2.h"


int main(int args, char const *argv[]) {
    const char businessPath[100] = "files/business.csv";
    const char reviewsPath[100] = "files/reviews.csv";
    const char usersPath[100] = "files/users.csv";

    // argv[1] -> business/review/user (Type of file) argv[2] -> Path (if args == 2
    if (args > 1) { // Argv[1] deve ser um número que identifique qual o ficheiro pretendido pelo utilizador
        if (args > 3) {
            fprintf(stderr, "Too many arguments");
            exit(-1);
        }
        if (strlen(argv[1]) >= 2) {
            fprintf(stderr, "Path too big");
            exit(-1);
        }
        else {

        }//strcpy(PATH, argv[1]);
    }

    users *users = readUsers(usersPath);
    reviews *reviews = readReviews(reviewsPath);
    businesss *businesss = readBusiness(businessPath);

    printf("%s\n", reviews->reviews[2000]->business_id);
    printf("%s", users->id[2000]);
    printf("%d", businesss->business[160584]->review_count);

    return 0;
}
