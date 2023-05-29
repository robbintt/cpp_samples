#include <iostream>
#include <fibonacci.h>
#include "fibonacci_test.h"
#include <my_complex.h>
#include "complex_test.h"
#include "trie_perf_test.h"

int main() {

    testFibonacci();
    std::cout << "fibonacci.h completed without exception or failed assertion.\n";

    testComplex();
    std::cout << "complex.h completed without exception or failed assertion.\n";

    TriePerformanceTest();

    return 0;
}
