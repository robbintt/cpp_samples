#include <iostream>
#include <fibonacci.h>
#include <fibonacci_test.h>

int main() {
    testFibonacci();
    std::cout << "Tests completed without exception (no assert failed)\n";
    return 0;
}
