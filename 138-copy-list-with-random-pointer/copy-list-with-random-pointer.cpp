/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * ptr = head;
        Node * dummy = new Node(-1);
        Node * ans = dummy;
        unordered_map<Node*, Node*> mpp;
        while(ptr){
            dummy->next = new Node(ptr->val);
            mpp[ptr] = dummy->next;
            ptr = ptr->next;
            dummy = dummy->next;
        }

        ptr = head;
        dummy = ans->next;
        while(ptr){
            dummy->random = mpp[ptr->random];
            ptr = ptr->next;
            dummy = dummy->next;
        }
        return ans->next;
    }
};