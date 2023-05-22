#include <cassert>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Test function
void testFibonacci() {
    assert(fibonacci(0) == 0);
    assert(fibonacci(1) == 1);
    assert(fibonacci(2) == 1);
    assert(fibonacci(5) == 5);
    assert(fibonacci(10) == 55);
}

int main() {
    testFibonacci();
    return 0;
}