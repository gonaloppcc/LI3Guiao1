#ifndef LI3_EX2_H
#define LI3_EX2_H
#define ID_SIZE 23


typedef struct users { // Each user has a char[23] id;
    char **id;
    int numUsers;
} users;

struct review {
    char *review_id, *user_id, *business_id;
    float stars;
    int useful, funny, cool;
};

typedef struct reviews {
    struct review **reviews;
    int numReviews;
} reviews;

struct business {
    char *business_id, *name, *city;
    float stars;
    int review_count;
};

typedef struct businesss {
    struct business **business;
    int numBusiness;
} businesss;

users* readUsers(const char *path);

reviews* readReviews(const char *path);

businesss* readBusiness(const char *path);



#endif //LI3_EX2_H
