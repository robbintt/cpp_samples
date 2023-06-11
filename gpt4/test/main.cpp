#include <iostream>
#include <fibonacci.h>
#include "fibonacci_test.h"
#include <my_complex.h>
#include "complex_test.h"
#include "trie_perf_test.h"
#include "hamt_tests.h"

int main() {

    testFibonacci();
    std::cout << "fibonacci.h completed without exception or failed assertion.\n";

    testComplex();
    std::cout << "complex.h completed without exception or failed assertion.\n";

    TriePerformanceTest();
    std::cout << "TriePerformanceTest completed without exception or failed assertion.\n";

    test_insert_search();
    test_deletion();
    test_memory_management();
    std::cout << "HAMT tests completed without exception or failed assertion.\n";



    return 0;
}
