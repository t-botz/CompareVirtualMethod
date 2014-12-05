/* 
 * File:   animals.c
 * Author: tibo
 *
 * Created on 5 December 2014, 3:01 PM
 */

#include <stdlib.h>
#include "animals.h"


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

struct animal** getAnimals(){
    struct dog* myDog = malloc(sizeof(struct dog));
    struct cat* myCat = malloc(sizeof(struct cat));
    struct zebra* myZebra = malloc(sizeof(struct zebra));

    myDog->count=0;
    myDog->animal.addOne=&dogAdd;
    myDog->animal.getCount=&dogCount;
    
    myCat->count=0;
    myCat->animal.addOne=&catAdd;
    myCat->animal.getCount=&catCount;

    myZebra->count=0;
    myZebra->animal.addOne=&zebraAdd;
    myZebra->animal.getCount=&zebraCount;
    
    struct animal** myAnimals = malloc(sizeof(struct animal*) * 3);
    myAnimals[0]=(struct animal*)myDog;
    myAnimals[1]=(struct animal*)myCat;
    myAnimals[2]=(struct animal*)myZebra;
    
    return myAnimals;
}