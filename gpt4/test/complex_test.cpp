#include <cassert>
#include <complex.h>

// Test function
void testComplex() {
    my_complex::Complex c1(1.0, 2.0);
    my_complex::Complex c2(3.0, 4.0);

    // should be asserts
    std::cout << "c1: " << c1 << " c2: " << c2 << std::endl;
    std::cout << "c1 + c2: " << c1 + c2 << std::endl;
    std::cout << "c1 - c2: " << c1 - c2 << std::endl;
    std::cout << "c1 * c2: " << c1 * c2 << std::endl;
    std::cout << "c1 / c2: " << c1 / c2 << std::endl;
    std::cout << "c1 == c2: " << (c1 == c2 ? "true" : "false") << std::endl;
    std::cout << "c1 != c2: " << (c1 != c2 ? "true" : "false") << std::endl;
}
