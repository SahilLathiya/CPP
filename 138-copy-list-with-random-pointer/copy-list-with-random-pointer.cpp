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
        unordered_map<Node*, Node*> mpp;
        Node * ans = new Node(0);
        Node * ptr = ans;
        Node * h = head;
        
        while(head){
            ptr->next = new Node(head->val);
            mpp[head] = ptr->next;
            ptr = ptr->next;
            head = head->next;
        }

        ptr = ans->next;
        int i = 0;
        while(ptr){
            ptr->random = mpp[h->random];
            // cout<<rand[i]<<' ';
            i++;
            ptr = ptr->next;
            h = h ->next;
        }

        return ans->next;
    }
};