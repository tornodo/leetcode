#include <map>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

class trie {
    struct Node {
        map<char, Node*> table;
        bool end;
        Node(): end(false) {}
    };

public:
    trie() {
        root = new Node();
        // pArr.push_back(root);
    }

    ~trie() {
        // for(int i = pArr.size() - 1; i > 0; --i) {
        //     delete pArr[i];
        // }
    }

    void insert(const string& word) {
        Node* curr = root;
        for(int i = 0; i < word.size(); i++) {
            if (curr->table.count(word[i]) == 0) {
                curr->table[word[i]] = new Node();
                // pArr.push_back(curr->table[word[i]]);
            }
            curr = curr->table[word[i]];
        }
        curr->end = true;
    }

    bool search(const string& word) {
        return find(word, true);
    }

    bool startWith(const string& word) {
        return find(word);
    }

    const string startWithPrefix(const string& word) {
        stringstream buffer;
        Node* curr = root;
        for(int i = 0; i < word.size(); i++) {
            if (curr->table.count(word[i]) == 0) {
                break;
            }
            buffer << word[i];
            curr = curr->table[word[i]];
        }
        return buffer.str();
    }

private:
    bool find(const string& word, bool exaceMatch = false) {
        Node* curr = root;
        for(int i = 0; i < word.size(); i++) {
            if (curr->table.count(word[i]) == 0) {
                return false;
            }
            curr = curr->table[word[i]];
        }
        if (exaceMatch) {
            if (curr->end) {
                return true;
            }
            return false;
        }
        return true;
    }

    Node* root;
    // vector<Node*> pArr;
};