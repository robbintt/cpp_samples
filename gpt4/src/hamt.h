#ifndef HAMT_H
#define HAMT_H

#include "trie.h"
#include <unordered_map>
#include <string>

namespace hamt {

    struct HAMTNode {
        trie::TrieNode* trieNode;
        std::size_t hash;

        HAMTNode(trie::TrieNode* node, std::size_t h) : trieNode(node), hash(h) {}
    };

    class HAMT {
    public:
        std::unordered_map<std::size_t, HAMTNode*> root;

        void insert(std::string word);
        bool search(std::string word);
        void deleteWord(std::string word);
    };

} // namespace hamt

#endif // HAMT_H
