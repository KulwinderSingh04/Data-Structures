class Node {
    public:
    bool flag;
    vector<Node*> freq;
    Node() {
        flag = false;
        freq.resize(26, NULL);
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        int n = word.size();
        Node* node = root;
        for(int i = 0; i < n; i++) {
            if(node -> freq[word[i] - 97] == NULL) {
                node -> freq[word[i] - 97] = new Node();
            }
            node = node -> freq[word[i] - 97];
        }
        node -> flag = true;
    }
    
    bool search(string word) {
        int n = word.size();
        Node* node = root;
        for(int i = 0; i < n; i++) {
            if(node -> freq[word[i] - 97] == NULL) return false;
            node = node -> freq[word[i] - 97];
        }
        return node -> flag;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        Node* node = root;
        for(int i = 0; i < n; i++) {
            if(node -> freq[prefix[i] - 97] == NULL) return false;
            node = node -> freq[prefix[i] - 97];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */