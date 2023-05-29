#include <ctime>
#include <iostream>
#include <trie.h>
#include "trie_perf_test.h"

std::vector<std::string> generateTestData(int numWords) {
    std::vector<std::string> testData;
    for (int i = 0; i < numWords; ++i) {
        testData.push_back("word" + std::to_string(i));
    }
    return testData;
}

void TriePerformanceTest() {
    // Prepare test data
    const int numWords = 1000000;
    std::vector<std::string> testData = generateTestData(numWords);

    // Create Trie
    trie::Trie trie;

    // Measure insertion time
    std::clock_t startInsert = std::clock();
    for (const auto &word : testData) {
        trie.insert(word);
    }
    double durationInsert = ( std::clock() - startInsert ) / (double) CLOCKS_PER_SEC;

    // Measure search time
    std::clock_t startSearch = std::clock();
    for (const auto &word : testData) {
        trie.search(word);
    }
    double durationSearch = ( std::clock() - startSearch ) / (double) CLOCKS_PER_SEC;

    std::cout << "Insertion of " << numWords << " words took " << durationInsert << " seconds.\n";
    std::cout << "Search of " << numWords << " words took " << durationSearch << " seconds.\n";
}
