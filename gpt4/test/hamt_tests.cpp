#include <vector>
#include <string>
#include <cassert>
#include <hamt.h>
#include "hamt_tests.h"

void test_insert_search(hamt::HAMT& h) {
    hamt::HAMT h;
    std::vector<std::string> words = {
        "apple", "banana", "cherry", "orange", "pear", "grape", "kiwi"};

    for (const auto& word : words) {
        h.insert(word);
    }

    for (const auto& word : words) {
        assert(h.search(word));
    }

    assert(!h.search("nonexistent"));
}

void test_deletion(hamt::HAMT& h) {
    hamt::HAMT h;
    std::vector<std::string> words = {
        "apple", "banana", "cherry", "orange", "pear", "grape", "kiwi"};

    for (const auto& word : words) {
        h.insert(word);
    }

    h.deleteWord("apple");
    assert(!h.search("apple"));

    h.deleteWord("banana");
    assert(!h.search("banana"));
}

void test_memory_management(hamt::HAMT& h) {
    hamt::HAMT h1;
    hamt::HAMT h2;

    std::vector<std::string> words = {
        "apple", "banana", "cherry", "orange", "pear", "grape", "kiwi"};

    for (const auto& word : words) {
        h1.insert(word);
    }

    for (const auto& word : words) {
        h1.deleteWord(word);
    }

    assert(h1.root.size() == h2.root.size());
}
