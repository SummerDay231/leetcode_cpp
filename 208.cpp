#include <string>
using namespace::std;



class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        for (int i=0; i<26; i++) {
            next[i] = NULL;
        }
        isWord = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *pos = this;
        for (int i=0; i<word.size(); i++) {
            char c = word[i];
            int p = c -'a';
            if (pos->next[p] != NULL) {
                pos = pos->next[p];
            }
            else {
                pos->next[p] = new Trie;
                pos = pos->next[p];
            }
        }
        pos->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *pos = this;
        for (int i=0; i<word.size(); i++) {
            char c = word[i];
            int p = c -'a';
            if (pos->next[p] == NULL) {
                return false;
            }
            else {
                pos = pos->next[p];
            }
        }
        return pos->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *pos = this;
        for (int i=0; i<prefix.size(); i++) {
            char c = prefix[i];
            int p = c -'a';
            if (pos->next[p] == NULL) {
                return false;
            }
            else {
                pos = pos->next[p];
            }
        }
        return true;        
    }
private:
    Trie *next[26];
    bool isWord;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */