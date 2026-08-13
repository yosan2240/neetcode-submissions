class LRUCache {
public:
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k, int v) {
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int max_capacity, cur_capacity = 0;
    Node *head, *tail;  // dummy sentinels
    unordered_map<int, Node*> list_table;  // maps key to its node in the list

    LRUCache(int capacity) {
        max_capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        int value = -1;
        if(list_table.count(key)) {
            Node* target = list_table[key];
            value = target->val;
            removeNode(target);
            insertTail(target);
        }
            
        return value;
    }
    
    void put(int key, int value) {
        Node *newNode = new Node(key, value);

        // if key exists, remove the old node (capacity unchanged)
        if (list_table.count(key)) {
            Node *target = list_table[key];
            removeNode(target);
            delete target;
            list_table.erase(key);
        } else {
            // new key: evict LRU if at capacity
            if (cur_capacity >= max_capacity) {
                Node *lru = head->next;
                list_table.erase(lru->key);  // remove from hash table
                removeNode(lru);
                delete lru;
            } else {
                cur_capacity++;
            }
        }

        // insert new node at tail and update hash table
        insertTail(newNode);
        list_table[key] = newNode;
    }

    void removeNode(Node* node) {
        Node *prevnode = node->prev;
        prevnode->next = node->next;
        node->next->prev = prevnode;
    }

    void insertTail(Node* node) {
        Node *last = tail->prev;
        last->next = node;
        node->prev = last;
        node->next = tail;
        tail->prev = node;
    }
};
