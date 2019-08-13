#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"
#include "Node.h"
#include "myLib.h"


int main() {
    int x = 4, y = 9, z = 19;
    int f = 88, t = 765;
    Vector *vector = new_Vector();
    addElement(vector, &x);
    addElement(vector, &y);
    addElement(vector, &z);
    print_integers_vector(vector);

    set(vector, &t, 2);

    print_integers_vector(vector);

    return 0;
}