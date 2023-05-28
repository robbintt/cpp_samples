#include <iostream>
#include "fibonacci.h"
#include "complex.h"

int main() {
    //fibonacci.cpp
    std::cout << fibonacci(10) << "\n";

    //complex.cpp
    my_complex::Complex c1(1.0, 2.0);
    my_complex::Complex c2(3.0, 4.0);
    std::cout << "c1: " << c1 << " c2: " << c2 << std::endl;
    std::cout << "c1 + c2: " << c1 + c2 << std::endl;
    std::cout << "c1 - c2: " << c1 - c2 << std::endl;
    std::cout << "c1 * c2: " << c1 * c2 << std::endl;
    std::cout << "c1 / c2: " << c1 / c2 << std::endl;
    std::cout << "c1 == c2: " << (c1 == c2 ? "true" : "false") << std::endl;
    std::cout << "c1 != c2: " << (c1 != c2 ? "true" : "false") << std::endl;

    return 0;
}
