class Node {
    public:
        int key;
        int val;
        Node * next;
        Node * prev;

    Node(int k, int v){
        key = k;
        val = v;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
    // Emply Doubly LL
    Node * head = new Node(-1, -1);
    Node * tail = new Node(-1, -1);

    // Emply MAP <key, Node *>
    unordered_map<int, Node*> mpp;

    int size;

public:
    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        // Current Size
        size = capacity;
    }
    
    int get(int key) {
        // Key alread present
        if(mpp.find(key)!=mpp.end()){
            int value = mpp[key]->val;

            // Remove from that posistion and insert at begining
            Node * NodeToModify = mpp[key];
            NodeToModify->prev->next = NodeToModify->next;
            NodeToModify->next->prev = NodeToModify->prev;
            NodeToModify->next = head->next;
            NodeToModify->prev = head->next->prev;
            head->next->prev = NodeToModify;
            head->next = NodeToModify;
            return value;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {

        // Key alread present
        if(mpp.find(key)!=mpp.end()){
            mpp[key]->val = value;
            // Remove from that posistion and insert at begining
            Node * NodeToModify = mpp[key];
            NodeToModify->prev->next = NodeToModify->next;
            NodeToModify->next->prev = NodeToModify->prev;
            NodeToModify->next = head->next;
            NodeToModify->prev = head->next->prev;
            head->next->prev = NodeToModify;
            head->next = NodeToModify;
        }
        else{   // Key Not present
            if(size>0){
                // Insert New Node
                Node * temp = new Node(key, value);
                // Insert in MAP
                mpp[key] = temp;
                // Insert After Head
                temp->next = head->next;
                temp->prev = head->next->prev;
                head->next->prev = temp;
                head->next = temp;

                //Decrease size
                size--;
            }
            else{

                // Remove Last Node that is node before tail
                Node * NodeToRemove = tail->prev;

                // Remove from map
                mpp.erase(NodeToRemove->key);

                // Remove Node
                NodeToRemove->prev->next = NodeToRemove->next;
                tail->prev = NodeToRemove->prev;
                delete NodeToRemove;

                // Increase Size
                size++;


                // Insert New Node
                Node * temp = new Node(key, value);
                // Insert in MAP
                mpp[key] = temp;
                // Insert After Head
                temp->next = head->next;
                temp->prev = head->next->prev;
                head->next->prev = temp;
                head->next = temp;

                //Decrease size
                size--;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */