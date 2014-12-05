/* 
 * File:   testPointerExtern.c
 * Author: tibo
 *
 * Created on 5 December 2014, 2:59 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "animals.h"

/*
 * 
 */
int main(int argc, char** argv) {

    struct animal** myAnimals = getAnimals();
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

