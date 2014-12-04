/* 
 * File:   testPointer.c
 * Author: tibo
 *
 * Created on 4 December 2014, 11:37 PM
 */

#include <stdio.h>
#include <stdlib.h>

struct animal{
   void (*addOne)(struct animal* self);
   int (*getCount)(struct animal* self);
};

struct dog{
   struct animal animal;
   int count;
} ;
void dogAdd(struct animal* self) {
    ((struct dog*)self)->count++;
}

int dogCount(struct animal* self) {
    return ((struct dog*)self)->count;
}

struct cat{
   struct animal animal;
   int count;
} ;
void catAdd(struct animal* self) {
    ((struct cat*)self)->count++;
}

int catCount(struct animal* self) {
    return ((struct cat*)self)->count;
}

typedef struct zebra{
   struct animal animal;
   int count;
} Zebra;
void zebraAdd(struct animal* self) {
    ((struct zebra*)self)->count++;
}

int zebraCount(struct animal* self) {
    return ((struct zebra*)self)->count;
}

int main(int argc, char** argv) {
    struct dog myDog = {
        .animal={
            .addOne=&dogAdd,
            .getCount=&dogCount
        },
        .count=0
    };
    struct dog myCat = {
        .animal={
            .addOne=&catAdd,
            .getCount=&catCount
        },
        .count=0
    };
    struct dog myZebra = {
        .animal={
            .addOne=&zebraAdd,
            .getCount=&zebraCount
        },
        .count=0
    };
    struct animal* myAnimals[3] ={(struct animal*)&myDog,(struct animal*)&myCat,(struct animal*)&myZebra};
    int i;
    for (i = 0; i < 10000000; i++) {
        int j;
            struct animal* a = myAnimals[i%3];
            a->addOne(a);
        
    }
    int j;
    for (j = 0; j < 3; j++) {
        struct animal* a = myAnimals[j];
        printf("count : %d",a->getCount(a));
    }

    return (EXIT_SUCCESS);
}

