/* 
 * File:   animals.h
 * Author: tibo
 *
 * Created on 5 December 2014, 3:00 PM
 */


struct animal{
   void (*addOne)(struct animal* self);
   int (*getCount)(struct animal* self);
};

struct animal** getAnimals();
