#include <cassert>
#include <fibonacci.h>

// Test function
void testFibonacci() {
    assert(fibonacci(0) == 0);
    assert(fibonacci(1) == 1);
    assert(fibonacci(2) == 1);
    assert(fibonacci(5) == 5);
    assert(fibonacci(10) == 55);
}
