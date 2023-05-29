#include <iostream>
#include "fibonacci.h"
#include "my_complex.h"
#include "trie.h"

int main() {
    //fibonacci.cpp
    std::cout << fibonacci(10) << "\n";

    //complex.cpp
    my_complex::Complex c1(1.0, 2.0);
    my_complex::Complex c2(3.0, 4.0);
    std::cout << "c1: " << c1 << " c2: " << c2 << std::endl;
    std::cout << "c1 + c2: " << c1 + c2 << std::endl;
    std::cout << "c1 - c2: " << c1 - c2 << std::endl;
    std::cout << "c1 * c2: " << c1 * c2 << std::endl;
    std::cout << "c1 / c2: " << c1 / c2 << std::endl;
    std::cout << "c1 == c2: " << (c1 == c2 ? "true" : "false") << std::endl;
    std::cout << "c1 != c2: " << (c1 != c2 ? "true" : "false") << std::endl;

    //trie.cpp
    trie::Trie trie;
    trie.insert("test");
    trie.insert("tea");
    trie.insert("to");

    assert(trie.search("test"));
    assert(!trie.search("testing"));
    assert(trie.search("tea"));
    assert(!trie.search("te"));
    assert(trie.search("to"));

    trie.deleteWord("tea");
    assert(!trie.search("tea"));

    std::string serialized = trie.serialize();
    trie::Trie newTrie;
    newTrie.deserialize(serialized);

    assert(newTrie.search("test"));
    assert(!newTrie.search("testing"));
    assert(!newTrie.search("tea"));
    assert(newTrie.search("to"));

    return 0;
}
