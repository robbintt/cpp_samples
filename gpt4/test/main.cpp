#include <iostream>
#include <fibonacci.h>
#include "fibonacci_test.h"
#include <my_complex.h>
#include "complex_test.h"
#include "trie_perf_test.h"
#include <hamt.h>
#include "hamt_tests.h"

int main() {

    testFibonacci();
    std::cout << "fibonacci.h completed without exception or failed assertion.\n";

    testComplex();
    std::cout << "complex.h completed without exception or failed assertion.\n";

    TriePerformanceTest();
    std::cout << "TriePerformanceTest completed without exception or failed assertion.\n";

    hamt::HAMT* h = new hamt::HAMT;
    test_insert_search(*h);
    test_deletion(*h);
    test_memory_management(*h);
    delete h;
    std::cout << "HAMT tests completed without exception or failed assertion.\n";

    return 0;
}
