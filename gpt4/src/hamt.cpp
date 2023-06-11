#include "hamt.h"
#include <functional>
#include <unordered_map>

namespace hamt {

    // Add a destructor definition for HAMTNode
    HAMTNode::~HAMTNode() {
        delete trieNode;
    }

    void HAMT::insert(std::string word) {
        std::size_t hash = std::hash<std::string>{}(word);
        trie::Trie trie;

        if (root.find(hash) != root.end()) {
            trie.root = root[hash]->trieNode;
        }
        trie.insert(word);

        // Update the trieNode pointer in the HAMTNode after inserting the word
        if (root.find(hash) != root.end()) {
            root[hash]->trieNode = trie.root;
        } else {
            root[hash] = new HAMTNode(trie.root, hash);
        }
    }

    bool HAMT::search(std::string word) {
        std::size_t hash = std::hash<std::string>{}(word);
        if (root.find(hash) == root.end()) {
            return false;
        }
        trie::Trie trie;
        trie.root = root[hash]->trieNode;
        return trie.search(word);
    }

    void HAMT::deleteWord(std::string word) {
        std::size_t hash = std::hash<std::string>{}(word);
        if (root.find(hash) == root.end()) {
            return;
        }
        trie::Trie trie;
        trie.root = root[hash]->trieNode;
        trie.deleteWord(word);
        if (trie.root->children.empty()) {
            delete trie.root;
            delete root[hash]; // Delete HAMTNode before removing it from the map
            root.erase(hash);
        } else {
            root[hash]->trieNode = trie.root;
        }
    }

} // namespace hamt
