#include "hamt.h"
#include <functional>
#include <unordered_map>

namespace hamt {

    HAMTNode::~HAMTNode() {
        delete trieNode;
    }

    void HAMT::insert(std::string word) {
        std::size_t hash = std::hash<std::string>{}(word);
        trie::TrieNode* currentNode;

        if (root.find(hash) == root.end()) {
            currentNode = new trie::TrieNode();
            root[hash] = new HAMTNode(currentNode, hash);
        } else {
            currentNode = root[hash]->trieNode;
        }

        for (const auto& c : word) {
            if (currentNode->children.find(c) == currentNode->children.end()) {
                currentNode->children[c] = new trie::TrieNode();
            }
            currentNode = currentNode->children[c];
        }
        currentNode->isEndOfWord = true;
    }

    bool HAMT::search(std::string word) {
        std::size_t hash = std::hash<std::string>{}(word);
        if (root.find(hash) == root.end()) {
            return false;
        }
        trie::TrieNode* currentNode = root[hash]->trieNode;

        for (const auto& c : word) {
            if (currentNode->children.find(c) == currentNode->children.end()) {
                return false;
            }
            currentNode = currentNode->children[c];
        }
        return currentNode->isEndOfWord;
    }

    void HAMT::deleteWord(std::string word) {
        std::size_t hash = std::hash<std::string>{}(word);
        if (root.find(hash) == root.end()) {
            return;
        }
        trie::TrieNode* currentNode = root[hash]->trieNode;

        // Helper function to delete nodes recursively
        std::function<bool(trie::TrieNode*, const std::string&, std::size_t)> deleteNodes;
        deleteNodes = [&](trie::TrieNode* node, const std::string& key, std::size_t index) {
            if (index == key.length()) {
                if (!node->isEndOfWord) {
                    return false;
                }
                node->isEndOfWord = false;
                return node->children.empty();
            }

            char c = key[index];
            if (node->children.find(c) == node->children.end()) {
                return false;
            }

            bool shouldDeleteCurrentNode = deleteNodes(node->children[c], key, index + 1);

            if (shouldDeleteCurrentNode) {
                delete node->children[c];
                node->children.erase(c);
                return node->children.empty() && !node->isEndOfWord;
            }

            return false;
        };

        if (deleteNodes(currentNode, word, 0) && currentNode->children.empty()) {
            delete root[hash];
            root.erase(hash);
        }
    }

} // namespace hamt
