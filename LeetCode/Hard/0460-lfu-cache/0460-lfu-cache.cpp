class LFUCache {
    struct Node {
        int key, val, freq;
        Node *prev, *next;

        Node(int k, int v) {
            key = k;
            val = v;
            freq = 1;
            prev = next = nullptr;
        }
    };

    struct DLL {
        Node *head, *tail;
        int sz;

        DLL() {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            sz = 0;
        }

        void addFront(Node* node) {
            node->next = head->next;
            node->prev = head;

            head->next->prev = node;
            head->next = node;
            sz++;
        }

        void remove(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            sz--;
        }

        Node* removeLast() {
            if (sz == 0) return nullptr;

            Node* node = tail->prev;
            remove(node);
            return node;
        }
    };

    int cap, minFreq;
    unordered_map<int, Node*> keyNode;
    unordered_map<int, DLL*> freqList;

    void updateFreq(Node* node) {
        int f = node->freq;

        freqList[f]->remove(node);

        if (f == minFreq && freqList[f]->sz == 0)
            minFreq++;

        node->freq++;

        if (!freqList.count(node->freq))
            freqList[node->freq] = new DLL();

        freqList[node->freq]->addFront(node);
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (!keyNode.count(key))
            return -1;

        Node* node = keyNode[key];
        updateFreq(node);

        return node->val;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (keyNode.count(key)) {
            Node* node = keyNode[key];
            node->val = value;
            updateFreq(node);
            return;
        }

        if ((int)keyNode.size() == cap) {
            Node* victim = freqList[minFreq]->removeLast();
            keyNode.erase(victim->key);
            delete victim;
        }

        Node* node = new Node(key, value);

        minFreq = 1;

        if (!freqList.count(1))
            freqList[1] = new DLL();

        freqList[1]->addFront(node);
        keyNode[key] = node;
    }
};