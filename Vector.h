//
// Created by yuval on 11/08/2019.
//
#include "Node.h"
#include "myLib.h"

#ifndef VECTOR_TASK_VECTOR_H
#define VECTOR_TASK_VECTOR_H

typedef struct vector Vector;

// the vector's struct constructor
Vector* new_Vector();

// adds a value's reference to the last of the vector
void addElement(Vector* this , void* element);

// returns the value's reference at the declared index
void* get(Vector* this, int index);

// delete everything from the vector.(makes him empty and set size to 0)
void clear(Vector* this);

// returns the vector's amount of elements
int size(Vector* this);

// returns the specified index of an element by his reference
boolean contains(Vector* this, void* element);

// copy all the vector's element's reference to an suitable array
void copyInto(Vector* this, void** array);

// returns the element's reference by his index in the vector
void* elementAt(Vector* this, int index);

// returns the vector's first element's reference
void* firstElement(Vector* this);

// returns result of if the current vector is equals to the other
boolean equals(Vector* this, Vector* other);

// returns the index of element in the vector by his reference (if element is not exist returns -1)
int indexOf(Vector* this, void* element);

// returns result of if the vector is empty
boolean isEmpty(Vector* this);

// returns the vector's last element
void* lastElement(Vector* this);

// returns the last index of element in the vector by his reference (if element is not exist returns -1)
int lastIndexOf(Vector* this, void* element);

// remove element from the vector by it's index and returns the element's reference
void* removeElement(Vector* this, int index);

// remove element from the vector by it's reference and returns if the method had succeeded(true for success)
boolean removeElementByReference(Vector* this, void* element);

// convert the vector to a references' array and returns the result
void** to_array(Vector* this);

// set an element in a specific index in the vector
void set(Vector* this, void* element, int index);

// A debugging function for printing out a integers vector
void print_integers_vector(Vector* this);

#endif //VECTOR_TASK_VECTOR_H
