#include <cassert>
#include <iostream>
#include <sstream>
#include <my_complex.h>

// Test function
void testComplex() {
    my_complex::Complex c1(1.0, 2.0);
    my_complex::Complex c2(3.0, 4.0);

    // Test addition
    Complex c3 = c1 + c2;
    assert(c3.real == 4.0 && c3.imag == 6.0);

    // Test subtraction
    Complex c4 = c1 - c2;
    assert(c4.real == -2.0 && c4.imag == -2.0);

    // Test multiplication
    Complex c5 = c1 * c2;
    assert(c5.real == -5.0 && c5.imag == 10.0);

    // Test division
    Complex c6 = c1 / c2;
    assert(c6.real == 11.0 / 25.0 && c6.imag == 2.0 / 25.0);

    // Test equality
    assert((c1 == c2) == false);
    assert((c1 == c1) == true);

    // Test inequality
    assert((c1 != c2) == true);
    assert((c1 != c1) == false);

    // Test string format
    std::ostringstream oss;
    oss << c1;
    std::string expected_format = "1 + 2i";
    assert(oss.str() == expected_format);
}
