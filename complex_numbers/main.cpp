#include <iostream>
#include "ComplexNumber.h"

int main() {
    ComplexNumber x(3, 4);
    ComplexNumber y(5, -4);
    
    ComplexNumber z = x / y;
    z.print();

    return 0;
}
