#include <iostream>
#include <fibonacci.h>
#include <fibonacci_test.h>
#include <complex.h>
#include <complex_test.h>

int main() {

    testFibonacci();
    std::cout << "fibonacci.h completed without exception or failed assertion.\n";

    testComplex();
    std::cout << "complex.h completed without exception or failed assertion.\n";

    return 0;

}
