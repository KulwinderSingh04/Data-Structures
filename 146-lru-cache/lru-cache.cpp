class LRUCache {
public:
    int n;
    class Node {
        public:
        int val, key;
        Node* next;
        Node* prev;
        Node(int key, int val) {
            this -> val = val;
            this -> key = key;
            next = prev = NULL;
        }
    };
    unordered_map<int, Node*> m;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        n = capacity;
        head = tail = NULL;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        int ans = m[key] -> val;
        Node* temp = m[key];
        if(temp -> next == NULL) return ans;
        if(temp -> prev == NULL) {
            head = head -> next;
            head -> prev = NULL;
            tail -> next = temp;
            temp -> prev = tail;
            tail = tail -> next;
            temp -> next = NULL;
            // Node* t = head;
            // while(t) {
            //     cout << t -> val << " ";
            //     t = t -> next;
            // }
            // cout << endl;
            return ans;
        } 
        Node* t1 = temp -> prev;
        t1 -> next = temp -> next;
        temp -> next -> prev = t1;
        temp -> next = NULL;
        tail -> next = temp;
        temp -> prev = tail;
        tail = tail -> next;
        // Node* t = head;
        // while(t) {
        //     cout << t -> val << " ";
        //     t = t -> next;
        // }
        // cout << endl;
        return ans;
    }
    
    void put(int key, int value) {
        if(m.find(key) == m.end()) {
            if(m.size() == n) {
                m.erase(head -> key);
                head = head -> next;
                if(head) head -> prev = NULL;
            }
            Node* newNode = new Node(key, value);
            if(head == NULL) head = tail = newNode;
            else {
                tail -> next = newNode;
                newNode -> prev = tail;
                tail = newNode;
            }
            m[key] = newNode;
        } else {
            m[key] -> val = value;
            get(key);
        }
        // Node* t = head;
        // while(t) {
        //     cout << t -> val << " ";
        //     t = t -> next;
        // }
        // cout << endl;
        // cout << "map -> ";
        // for(auto x : m) cout << x.second -> val<< " ";
        // cout << endl;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */