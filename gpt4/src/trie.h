#include <unordered_map>
#include <string>

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode();
    ~TrieNode();
};

class Trie {
public:
    TrieNode* root;

    Trie();
    ~Trie();

    void insert(std::string word);
    bool search(std::string word);
    bool remove(TrieNode* node, std::string word, int depth = 0);
    void deleteWord(std::string word);
};
