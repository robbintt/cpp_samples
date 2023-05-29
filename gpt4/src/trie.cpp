#include "Trie.h"
#include <iostream>

namespace trie {

    TrieNode::TrieNode() : isEndOfWord(false) {}

    TrieNode::~TrieNode() {
        for(auto &p : children)
            delete p.second;
    }

    Trie::Trie() {
        root = new TrieNode();
    }

    Trie::~Trie() {
        delete root;
    }

    void Trie::insert(std::string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }

    bool Trie::search(std::string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->isEndOfWord;
    }

    bool Trie::remove(TrieNode* node, std::string word, int depth) {
        if (!node) {
            return false;
        }

        if (depth == word.size()) {
            if (node->isEndOfWord) {
                node->isEndOfWord = false;
                return node->children.empty();
            }
        }
        else {
            char index = word[depth];
            if (node->children.find(index) == node->children.end())
                return false;
            if (remove(node->children[index], word, depth + 1)) {
                delete node->children[index];
                node->children.erase(index);
                return !node->isEndOfWord && node->children.empty();
            }
        }
        return false;
    }

    void Trie::deleteWord(std::string word) {
        if (!search(word)) {
            std::cout << "Word not found in the trie.\n";
            return;
        }
        remove(root, word);
    }
} // namespace trie
